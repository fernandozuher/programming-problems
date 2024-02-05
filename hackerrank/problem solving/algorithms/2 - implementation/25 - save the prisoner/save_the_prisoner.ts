// https://www.hackerrank.com/challenges/save-the-prisoner/problem?isFullScreen=true

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
    let prisonersChairNumberToWarn: number[] = Array(n).fill(0);

    for (let i = 0; i < n; ++i) {
        let [prisoners, sweets, chairNumberToBegin]: number[] = readIntArray();
        prisonersChairNumberToWarn[i] = saveThePrisoner(prisoners, sweets, chairNumberToBegin);
    }

    prisonersChairNumberToWarn.forEach(x => console.log(x));
}
    function readIntArray(): number[] {
        return readLine().split(' ').map(Number);
    }

    function saveThePrisoner(prisoners: number, sweets: number, chairNumberToBegin: number): number {
        let prisonerChairNumberToWarn: number = chairNumberToBegin + (sweets - 1);
        let x: number = prisonerChairNumberToWarn;

        if (x > prisoners) {
            x %= prisoners;
            if (x == 0)
                x = prisoners;
        }

        return x;
    }
