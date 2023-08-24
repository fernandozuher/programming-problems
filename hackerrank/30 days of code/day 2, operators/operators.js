// https://www.hackerrank.com/challenges/30-operators/problem?isFullScreen=true

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
    let mealCost = parseFloat(readLine());
    let tipPercent = parseInt(readLine());
    let taxPercent = parseInt(readLine());

    solve(mealCost, tipPercent, taxPercent);
}

    function solve(mealCost, tipPercent, taxPercent) {
        let totalCost = (mealCost + mealCost * tipPercent / 100 + mealCost * taxPercent / 100).toFixed(0);
        console.log(totalCost);
    }
