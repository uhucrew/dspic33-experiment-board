#!/bin/sh

docker run -it -v $PWD:/work -w /work/window_functions node:16 npm install bessel
docker run -it -v $PWD:/work -w /work/window_functions node:16 node generate_window.js
