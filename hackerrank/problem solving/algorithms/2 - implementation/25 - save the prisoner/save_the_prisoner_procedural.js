// Source: https://www.hackerrank.com/challenges/save-the-prisoner/problem?isFullScreen=true

'use strict';

process.stdin.resume();
process.stdin.setEncoding('utf-8');

let inputString = '';
let currentLine = 0;

process.stdin.on('data', function(inputStdin) {
    inputString += inputStdin;
});

process.stdin.on('end', function() {
    inputString = inputString.split('\n');
    main();
});

function readLine() {
    return inputString[currentLine++];
}


function main() {
    const N_TEST_CASES = readANumber();
    const PRISONERS_CHAIR_NUMBER_TO_WARN = readTestCasesAndSaveThePrisoners(N_TEST_CASES);
    printResults(PRISONERS_CHAIR_NUMBER_TO_WARN);
}

    function readANumber() {
        return +readLine();
    }

    function readTestCasesAndSaveThePrisoners(nTestCases) {
        let prisonersChairNumberToWarn = new Array(nTestCases);

        for (let i = 0; i < nTestCases; i++) {
            const TEST_CASE = readTestCase();
            prisonersChairNumberToWarn[i] = saveThePrisoner(TEST_CASE);
        }

        return prisonersChairNumberToWarn;
    }

        function readTestCase() {
            const TEST_CASE = readLine().split(' ').map(Number);
            return TEST_CASE;
        }

        function saveThePrisoner(testCase) {
            const PRISONERS = testCase[0];
            const SWEETS = testCase[1];
            const CHAIR_NUMBER_TO_BEGIN = testCase[2];
            let prisonerChairNumberToWarn = CHAIR_NUMBER_TO_BEGIN + (SWEETS - 1);

            if (prisonerChairNumberToWarn > PRISONERS) {
                prisonerChairNumberToWarn %= PRISONERS;

                if (prisonerChairNumberToWarn === 0)
                    prisonerChairNumberToWarn = PRISONERS;
            }

            return prisonerChairNumberToWarn;
        }

    function printResults(array) {
        array.forEach(element => console.log(element));
    }
