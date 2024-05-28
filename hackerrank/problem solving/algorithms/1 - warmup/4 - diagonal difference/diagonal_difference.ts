// https://www.hackerrank.com/challenges/diagonal-difference/problem?isFullScreen=true

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
    console.log(diagonalDifference(n));
}

    function diagonalDifference(n: number): number {
        let [primaryDiagonal, secondaryDiagonal] = [0, 0];
        for (let i = 0; i < n; ++i) {
            let line: number[] = readIntArray();
            primaryDiagonal += line[i];
            secondaryDiagonal += line[n - i - 1];
        }
        return Math.abs(primaryDiagonal - secondaryDiagonal);
    }

        function readIntArray(): number[] {
            return readLine().split(' ').map(Number);
        }
