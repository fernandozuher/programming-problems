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
    const MEAL_COST = parseFloat(readLine());
    const TIP_PERCENT = parseInt(readLine());
    const TAX_PERCENT = parseInt(readLine());

    solve(MEAL_COST, TIP_PERCENT, TAX_PERCENT);
}

    function solve(mealCost, tipPercent, taxPercent) {
        const TOTAL_COST = (mealCost + mealCost * tipPercent / 100 + mealCost * taxPercent / 100).toFixed(0);
        console.log(TOTAL_COST);
    }
