// https://www.hackerrank.com/challenges/birthday-cake-candles/problem?isFullScreen=true

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

//////////////////////////////////////////////////

function main() {
    let n: number = +readLine();
    let array: number[] = readIntArray();
    console.log(birthdayCakeCandles(array));
}

    function readIntArray(): number[] {
        return readLine().split(' ').map(Number);
    }

    function birthdayCakeCandles(candles: number[]): number {
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
