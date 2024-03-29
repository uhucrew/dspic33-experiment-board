#!/usr/bin/env node

var fs= require('fs');
var util= require('util');
var BESSEL= require('bessel');

var fftHeader= '../window.h';



var windowFunctions= [];
var fftPoints= 1024;
var dataType= 'uint16_t';
var dataSize= 16;
var dataFactor= 1<<(dataSize - 1);
var dataMax= dataFactor - 1;
var zeroPadding= '0000';

var isNumeric= function(obj) {
    return !util.isArray(obj) && (obj - parseFloat(obj) + 1) >= 0;
};


console.log('INFO: reading header file: ', fftHeader);
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
                dataFactor= 1<<(dataSize - 1);
                dataMax= dataFactor - 1;
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
        var windowFunction= line.split(/fractional/)[1].trim().split(/\[/)[0];
        console.log('INFO: found required window function: ', windowFunction);
        windowFunctions.push(windowFunction);
    }
});



var dirichlet_window= function(step, points, factor) {
    var factor= isNumeric(factor) ? factor : 1;
    return factor;
};

var hamming_window= function(step, points, alpha, beta) {
    var alpha= isNumeric(alpha) ? alpha : 25 / 46;
    var beta= isNumeric(beta) ? beta : 1 - alpha;

    var value= alpha - beta * Math.cos((2 * Math.PI * step) / (points - 1));
    return value;
};


var blackman_window= function(step, points) {
    var alpha= isNumeric(alpha) ? alpah : 0.16;
    var a0= isNumeric(a0) ? a0 : (1 - alpha) / 2;;
    var a1= isNumeric(a1) ? a1 : 0.5;
    var a2= isNumeric(a2) ? a2 : alpha / 2;

    var value=
          a0
        - a1 * Math.cos((2 * Math.PI * step) / (points - 1))
        + a2 * Math.cos((4 * Math.PI * step) / (points - 1));

    if (value < 1 / dataFactor) value = 0;
    return value;
};


var blackman_harris_window= function(step, points, a0, a1, a2, a3) {
    var a0= isNumeric(a0) ? a0 : 0.35875;
    var a1= isNumeric(a1) ? a1 : 0.48829;
    var a2= isNumeric(a2) ? a2 : 0.14128;
    var a3= isNumeric(a3) ? a3 : 0.01168;

    var value=
          a0
        - a1 * Math.cos((2 * Math.PI * step) / (points - 1))
        + a2 * Math.cos((4 * Math.PI * step) / (points - 1))
        - a3 * Math.cos((6 * Math.PI * step) / (points - 1));

    if (value < 1 / dataFactor) value = 0;
    return value;
};


var gauss_window= function(step, points, sigma) {
    var sigma= isNumeric(sigma) ? sigma : 0.4;

    var gaussExponent= (step - (points - 1) / 2) / (sigma * (points - 1) / 2);
    var value= Math.pow(Math.E, -0.5 * gaussExponent * gaussExponent);
    return value;
};

var kaiser_window= function(step, points, alpha) {
    var step= step - (points - 1) / 2;
    var alpha= isNumeric(alpha) ? alpha : 16;
    var alphaFactor= Math.pow(( 1 - (2 * step / points) * (2 * step / points)), 0.5);

    var value= BESSEL.besseli(alpha * alphaFactor, 0) / BESSEL.besseli(alpha, 0);
    return value;
};

var bartlett_window= function(step, points) {
    var value= (2 / (points - 1)) * ((points - 1) / 2 - Math.abs(step - ((points - 1) / 2)));
    return value;
};

var flat_top_window= function(step, points, a0, a1, a2, a3, a4) {
    var a0= isNumeric(a0) ? a0 : 1;
    var a1= isNumeric(a1) ? a1 : 1.93;
    var a2= isNumeric(a2) ? a2 : 1.29;
    var a3= isNumeric(a3) ? a3 : 0.388;
    var a4= isNumeric(a4) ? a4 : 0.028;

    var value=
          a0
        - a1 * Math.cos((2 * Math.PI * step) / (points - 1))
        + a2 * Math.cos((4 * Math.PI * step) / (points - 1))
        - a3 * Math.cos((6 * Math.PI * step) / (points - 1))
        + a4 * Math.cos((8 * Math.PI * step) / (points - 1));

    return value;
};


var functions= {
    dirichlet_window: dirichlet_window,
    hamming_window: hamming_window,
    blackman_window: blackman_window,
    blackman_harris_window: blackman_harris_window,
    gauss_window: gauss_window,
    kaiser_window: kaiser_window,
    bartlett_window: bartlett_window,
    flat_top_window: flat_top_window,
};


var writeWindow= function(windowName, points) {
    if (!(windowName in functions)) {
        console.log('WARNING: no function for ' + windowName + ', skipping...');
        return;
    }

    console.log('INFO: calculating ' + windowName + ', output to ../' + windowName + '.c');
    var outputFile= './' + windowName + '.c';
    fs.writeFileSync(outputFile, '#include <xc.h>\n#include <dsp.h>\n\n\n', 'utf8');
    fs.appendFileSync(outputFile, '__prog__ fractional ' + windowName + '[' + points + '] __attribute__((space(prog))) = {\n', 'utf8');
    var line= '  ';
    for (var i= 0; i < points; i++) {
        var value= functions[windowName](i, points);
        if (value < 0) {
            value= Math.round((dataFactor<<1) + value * dataFactor);
            if (value < dataFactor) value= dataFactor;
            if (value > ((dataFactor<<1) - 1)) value= (dataFactor<<1) - 1;
            var hexStr= value.toString(16);
        }
        else {
            value= Math.round(value * dataFactor);
            if (value > dataMax) value= dataMax;
            if (value < 0) value = 0;
            var hexStr= value.toString(16);
        }
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
