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

//////////////////////////////////////////////////

function main() {
    let n = +readLine();
    let array = readIntArray();
    let [positiveProportion, negativeProportion, zeroProportion] = plusMinus(array);
    console.log(positiveProportion.toFixed(6));
    console.log(negativeProportion.toFixed(6));
    console.log(zeroProportion.toFixed(6));
}

    function readIntArray() {
        return readLine().split(' ').map(Number);
    }

    function plusMinus(array) {
        let [positive, negative, zero] = [0, 0, 0];

        for (let x of array)
            if (x > 0)
                ++positive;
            else if (x < 0)
                ++negative;
            else
                ++zero;

        let n = array.length;
        let positiveProportion = positive / n;
        let negativeProportion = negative / n;
        let zeroProportion = zero / n;
        
        return [positiveProportion, negativeProportion, zeroProportion];
    }
