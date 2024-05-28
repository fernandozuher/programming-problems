// https://www.hackerrank.com/challenges/staircase/problem?isFullScreen=true

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
    staircase(n);
}

    function staircase(n: number) {
        for (let i = 1; i <= n; ++i) {
            for (let j = 0; j < n - i; ++j)
                process.stdout.write(' ');
            for (let k = 0; k < i; ++k)
                process.stdout.write('#');
            console.log('');
        }
    }
