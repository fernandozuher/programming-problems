// https://www.hackerrank.com/challenges/crush/problem?isFullScreen=true

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
    let [n, nQueries]: number[] = readIntArray();
    console.log(arrayManipulation(n, nQueries));
}

    function readIntArray(): number[] {
        return readLine().split(' ').map(Number);
    }

    function arrayManipulation(n: number, nQueries: number): number {
        // n + 2 = 1-indexed array + range-end
        let array: number[] = new Array(n + 2).fill(0);

        while (nQueries--) {
            let [b, e, summand]: number[] = readIntArray();
            array[b] += summand;
            array[e + 1] -= summand;
        }

        let sum: number = 0;
        let max: number = 0;
        for (const x of array) {
            if (x == 0)
                continue;
            sum += x;
            max = Math.max(max, sum);
        }

        return max;
    }
