// https://www.hackerrank.com/challenges/30-operators/problem?isFullScreen=true

'use strict';

process.stdin.resume();
process.stdin.setEncoding('utf-8');

let inputString: string = '';
let inputLines: string[] = [];
let currentLine: number = 0;

process.stdin.on('data', function(inputStdin: string): void {
    inputString += inputStdin;
});

process.stdin.on('end', function(): void {
    inputLines = inputString.split('\n');
    inputString = '';
    main();
});

function readLine(): string {
    return inputLines[currentLine++];
}

function main() {
    const MEAL_COST: number = parseFloat(readLine());
    const TIP_PERCENT: number = parseInt(readLine());
    const TAX_PERCENT: number = parseInt(readLine());

    solve(MEAL_COST, TIP_PERCENT, TAX_PERCENT);
}

    function solve(mealCost: number, tipPercent: number, taxPercent: number) {
        const TOTAL_COST: string = (mealCost + mealCost * tipPercent / 100 + mealCost * taxPercent / 100).toFixed(0);
        console.log(TOTAL_COST);
    }
