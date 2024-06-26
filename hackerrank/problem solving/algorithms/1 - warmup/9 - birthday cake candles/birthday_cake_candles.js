// https://www.hackerrank.com/challenges/birthday-cake-candles/problem?isFullScreen=true

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
    console.log(birthdayCakeCandles(array));
}

    function readIntArray() {
        return readLine().split(' ').map(Number);
    }

    function birthdayCakeCandles(candles) {
        let maxCount = 0;
        let maxElement = 0;

        for (let x of candles)
            if (x > maxElement) {
                maxElement = x;
                maxCount = 1;
            }
            else if (x === maxElement)
                ++maxCount;

        return maxCount;
    }
