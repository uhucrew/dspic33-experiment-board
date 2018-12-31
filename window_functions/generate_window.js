#!/usr/bin/env node

var fs= require('fs');

var fftHeader= '../fft.h';



var windowFunctions= [];
var fftPoints= 512;
var dataType= 'uint16_t';
var dataSize= 16;
var dataFactor= Math.pow(2, dataSize);
var zeroPadding= '0000';

var headerReader= require('readline').createInterface({
    input: fs.createReadStream(fftHeader)
});

headerReader.on('line', function(line) {
    //#define FFT_POINTS         1024
    //__prog__ extern uint16_t blackman_window[FFT_POINTS] __attribute__((space(prog)));
    if (line.indexOf('#define') === 0 && line.indexOf('FFT_POINTS') > -1) {
        fftPoints= +line.split(/\s+/)[2];
        console.log('INFO: found number of FFT_POINTS: ', fftPoints);
    }
    if (line.indexOf('indow[FFT_POINTS]') > -1) {
        line.split(/\s/).forEach(function(part) {
            if (part.match(/int\d+_t/)) {
                dataType= part;
                console.log('INFO: found FFT data type: ', dataType);
                dataSize= +part.match(/\d+/)[0];
                dataFactor= Math.pow(2, dataSize);
                console.log('INFO: found FFT data size: ', dataSize);
                switch (dataSize) {
                case 8:
                    zeroPadding= '00';
                    break;
                case 16:
                    zeroPadding= '0000';
                    break;
                case 24:
                    zeroPadding= '000000';
                    break;
                case 32:
                    zeroPadding= '00000000';
                    break;
                case 48:
                    zeroPadding= '000000000000';
                    break;
                case 64:
                    zeroPadding= '0000000000000000';
                    break;
                default:
                    console.log('WARNING: unknown dataType length: ', +part.match(/\d+/)[0]);
                }
            }
        });
        var windowFunction= line.split(/_t/)[1].trim().split(/\[/)[0];
        console.log('INFO: found required window function: ', windowFunction);
        windowFunctions.push(windowFunction);
    }
});



var rectangle_window= function(step, points) {
    return 0.5;
};

var hamming_window= function(step, points) {
    var alpha= 25 / 46;
    var beta= 1 - alpha;

    var value= alpha - beta * Math.cos((2 * Math.PI * step) / (points - 1));
    return value;
};


var blackman_window= function(step, points) {
    var alpha= 0.16;
    var a0= (1 - alpha) / 2;
    var a1= 0.5;
    var a2= alpha / 2;

    var value= a0 - a1 * Math.cos((2 * Math.PI * step) / (points - 1)) + a2 * Math.cos((4 * Math.PI * step) / (points - 1));
    if (value < 1 / dataFactor) value = 0;
    return value;
};


var blackman_harris_window= function(step, points) {
    var a0= 0.35875;
    var a1= 0.48829;
    var a2= 0.14128;
    var a3= 0.01168;

    var value= a0 - a1 * Math.cos((2 * Math.PI * step) / (points - 1)) + a2 * Math.cos((4 * Math.PI * step) / (points - 1)) - a3 * Math.cos((6 * Math.PI * step) / (points - 1));
    if (value < 1 / dataFactor) value = 0;
    return value;
};


var gauss_window= function(step, points) {
    var sigma= 0.4

    //FIXME: correct wrong function
    var value= Math.pow(Math.E, Math.pow(2, ((step - (points - 1) / 2) / ((points - 1) / 2 * sigma))) * -0.5);
    return value;
};


var functions= {
    rectangle_window: rectangle_window,
    hamming_window: hamming_window,
    blackman_window: blackman_window,
    blackman_harris_window: blackman_harris_window,
    gauss_window: gauss_window,
};


var writeWindow= function(windowName, points) {
    if (!(windowName in functions)) {
        console.log('WARNING: no function for ' + windowName + ', skipping...');
        return;
    }

    console.log('INFO: calculating ' + windowName + ', output to ../' + windowName + '.c');
    var outputFile= '../' + windowName + '.c';
    fs.writeFileSync(outputFile, '#include <xc.h>\n\n\n', 'utf8');
    fs.appendFileSync(outputFile, '__prog__ uint16_t ' + windowName + '[' + points + '] __attribute__((space(auto_psv))) = {\n', 'utf8');
    var line= '  ';
    for (var i= 0; i < points; i++) {
        var value= Math.min(dataFactor - 1, functions[windowName](i, points) * dataFactor);
        var hexStr= Math.round(value).toString(16);
        line += '  0x' + zeroPadding.substr(hexStr.length) + hexStr;
        if (i < points - 1) line += ',';
        if ((i + 1) % 8 === 0) {
            line += '\n';
            fs.appendFileSync(outputFile, line, 'utf8');
            line= '  ';
        }
    }
    fs.appendFileSync(outputFile, '};\n', 'utf8');
};


headerReader.on('close', function() {
    windowFunctions.forEach(function(windowName) {
        writeWindow(windowName, fftPoints);
    });

    process.exit();
});
