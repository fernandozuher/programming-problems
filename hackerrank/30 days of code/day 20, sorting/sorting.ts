// https://www.hackerrank.com/challenges/30-sorting/problem?isFullScreen=true

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
    let _ = readLine();
    let list = readLine().split(' ').map(Number);

    console.log(`Array is sorted in ${bubbleSort(list)} swaps.`);
    console.log(`First Element: ${list[0]}`);
    console.log(`Last Element: ${list[list.length - 1]}`);
}

    function bubbleSort(a: number[]) {
        let numberOfSwaps = 0

        for (let n = a.length - 1; n; --n) {
            for (let i = 0; i < n; ++i)
                if (a[i] > a[i + 1]) {
                    [a[i], a[i+1]] = [a[i+1], a[i]];
                    ++numberOfSwaps;
                }

            if (!numberOfSwaps)
                break;
        }

        return numberOfSwaps;
    }
