// https://www.hackerrank.com/challenges/the-birthday-bar/problem?isFullScreen=true

'use strict';

process.stdin.resume();
process.stdin.setEncoding('utf-8');

let inputString: string = '';
let inputLines: string[] = [];
let currentLine: number = 0;

process.stdin.on('data', function (inputStdin: string): void {
    inputString += inputStdin;
});

process.stdin.on('end', function (): void {
    inputLines = inputString.split('\n');
    inputString = '';
    main();
});

function readLine(): string {
    return inputLines[currentLine++];
}

//////////////////////////////////////////////////

function main() {
    readLine();
    let chocolateSquares: number[] = readIntArray();
    let dayMonth: number[] = readIntArray();
    console.log(birthday(chocolateSquares, dayMonth));
}

    function readIntArray(): number[] {
        return readLine().split(' ').map(Number);
    }
    
    function birthday(chocolateSquares: number[], dayMonth: number[]): number {
        let waysBarCanBeDivided = 0;
        let [day, month]: number[] = dayMonth;
    
        for (let i = 0, n = chocolateSquares.length - month + 1; i < n; ++i) {
            let sum: number = chocolateSquares.slice(i, i + month).reduce((a, b) => a + b, 0);
            if (sum === day)
                ++waysBarCanBeDivided;
        }
    
        return waysBarCanBeDivided;
    }
