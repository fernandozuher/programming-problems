// https://www.hackerrank.com/challenges/save-the-prisoner/problem?isFullScreen=true

'use strict';

process.stdin.resume();
process.stdin.setEncoding('utf-8');

let inputString = '';
let inputLines = [];
let currentLine = 0;

process.stdin.on('data', function(inputStdin) {
    inputString += inputStdin;
});

process.stdin.on('end', function() {
    inputLines = inputString.split('\n');
    inputString = '';
    main();
});

function readLine() {
    return inputLines[currentLine++];
}

//////////////////////////////////////////////////

function main() {
    let n = +readLine();
    let prisonersChairNumberToWarn = Array(n).fill(0);

    for (let i = 0; i < n; ++i) {
        let [prisoners, sweets, chairNumberToBegin] = readIntArray();
        prisonersChairNumberToWarn[i] = saveThePrisoner(prisoners, sweets, chairNumberToBegin);
    }

    prisonersChairNumberToWarn.forEach(x => console.log(x));
}
    function readIntArray() {
        return readLine().split(' ').map(Number);
    }

    function saveThePrisoner(prisoners, sweets, chairNumberToBegin) {
        let prisonerChairNumberToWarn = chairNumberToBegin + (sweets - 1);
        let x = prisonerChairNumberToWarn;

        if (x > prisoners) {
            x %= prisoners;
            if (x == 0)
                x = prisoners;
        }

        return x;
    }
