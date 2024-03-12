// https://www.hackerrank.com/challenges/sparse-arrays/problem?isFullScreen=true

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
    let input: {[key: string]: number} = readInput(n);
    n = +readLine();
    let result: number[] = readQueriesAndCountMatches(input, n);
    result.forEach(x => console.log(x));
}

    function readInput(n: number): {} {
        let input: {[key: string]: number} = {};
        while (n-- > 0) {
            let x: string = readLine();
            input[x] = (input[x]+1) || 1;
        }
        return input;
    }

    function readQueriesAndCountMatches(input: {[key: string]: number}, n: number): number[] {
        let result: number[] = Array(n).fill(0);
        for (let i = 0; i < n; ++i) {
            let query: string = readLine();
            let count: number = input[query] || 0;
            result[i] = count;
        }
        return result;
    }
