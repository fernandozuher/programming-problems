// https://www.hackerrank.com/challenges/the-birthday-bar/problem?isFullScreen=true

'use strict';

process.stdin.resume();
process.stdin.setEncoding('utf-8');

let inputString = '';
let inputLines = [];
let currentLine = 0;

process.stdin.on('data', function (inputStdin) {
    inputString += inputStdin;
});

process.stdin.on('end', function () {
    inputLines = inputString.split('\n');
    inputString = '';
    main();
});

function readLine() {
    return inputLines[currentLine++];
}

//////////////////////////////////////////////////

function main() {
    readLine();
    let chocolateSquares = readIntArray();
    let dayMonth = readIntArray();
    console.log(birthday(chocolateSquares, dayMonth));
}

    function readIntArray() {
        return readLine().split(' ').map(Number);
    }

    function birthday(chocolateSquares, dayMonth) {
        let waysBarCanBeDivided = 0;
        let [day, month] = dayMonth;

        for (let i = 0, n = chocolateSquares.length - month + 1; i < n; ++i) {
            let sum = chocolateSquares.slice(i, i + month).reduce((a, b) => a + b, 0);
            if (sum === day)
                ++waysBarCanBeDivided;
        }

        return waysBarCanBeDivided;
    }
