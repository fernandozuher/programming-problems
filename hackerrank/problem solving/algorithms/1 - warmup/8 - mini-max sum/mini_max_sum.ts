// https://www.hackerrank.com/challenges/mini-max-sum/problem?isFullScreen=true

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
    let array: number[] = readIntArray();
    array.sort((a, b) => a - b);
    let [minSum, maxSum] = miniMaxSum(array);
    console.log(`${minSum} ${maxSum}`);
}

    function readIntArray(): number[] {
        return readLine().split(' ').map(Number);
    }

    function miniMaxSum(array: number[]): number[] {
        let sum: number = array.reduce((a, b) => a + b);
        let minSum: number = sum - array[array.length - 1];
        let maxSum: number = sum - array[0];
        return [minSum, maxSum];
    }
