// https://www.hackerrank.com/challenges/plus-minus/problem?isFullScreen=true

'use strict';

process.stdin.resume();
process.stdin.setEncoding('utf-8');

let inputString = '';
let inputLines = [];
let currentLine = 0;

process.stdin.on('data', function(inputStdin) {
    inputString += inputStdin;
});

process.stdin.on('end', function() {
    inputLines = inputString.split('\n');
    inputString = '';
    main();
});

function readLine() {
    return inputLines[currentLine++];
}

function main() {
    let n = +readLine();
    let array = readLine().split(' ').map(Number);
    plusMinus(array);
}

    function plusMinus(array) {
        let [positiveQuantity, negativeQuantity, zeroQuantity] = [0, 0, 0];

        for (let number of array)
            if (number > 0)
                ++positiveQuantity;
            else if (number < 0)
                ++negativeQuantity;
            else
                ++zeroQuantity;

        let n = array.length;
        let positiveValuesProportion = positiveQuantity / n;
        let negativeValuesProportion = negativeQuantity / n;
        let zeroValuesProportion = zeroQuantity / n;
        
        console.log(positiveValuesProportion.toFixed(6));
        console.log(negativeValuesProportion.toFixed(6));
        console.log(zeroValuesProportion.toFixed(6));
    }
