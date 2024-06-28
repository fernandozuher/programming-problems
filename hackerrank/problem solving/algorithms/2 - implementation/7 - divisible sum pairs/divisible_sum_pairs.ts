// https://www.hackerrank.com/challenges/divisible-sum-pairs/problem?isFullScreen=true

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
    let [, k] = [...readIntArray()];
    let array: number[] = readIntArray();
    array.sort((a, b) => a - b);
    console.log(divisibleSumPairs(array, k));
}

    function readIntArray(): number[] {
        return readLine().split(' ').map(Number);
    }
    
    function divisibleSumPairs(array: number[], k: number): number {
        let nDivisibleSumPairs = 0;
    
        for (let i = 0, n = array.length - 1; i < n; ++i)
            for (let j = i + 1; j < array.length; ++j)
                if (array[i] <= array[j] && !((array[i] + array[j]) % k))
                    ++nDivisibleSumPairs;
    
        return nDivisibleSumPairs;
    }
