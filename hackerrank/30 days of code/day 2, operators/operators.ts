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
    let mealCost: number = parseFloat(readLine());
    let tipPercent: number = parseInt(readLine());
    let taxPercent: number = parseInt(readLine());
    solve(mealCost, tipPercent, taxPercent);
}

function solve(mealCost: number, tipPercent: number, taxPercent: number) {
    let totalCost: string = (mealCost + mealCost * tipPercent / 100 + mealCost * taxPercent / 100).toFixed(0);
    console.log(totalCost);
}
