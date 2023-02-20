// Source: https://www.hackerrank.com/challenges/save-the-prisoner/problem?isFullScreen=true

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
    const N_TEST_CASES: number = readANumber();
    const PRISONERS_CHAIR_NUMBER_TO_WARN: number[] = readTestCasesAndSaveThePrisoners(N_TEST_CASES);
    printResults(PRISONERS_CHAIR_NUMBER_TO_WARN);
}

    function readANumber(): number {
        return +readLine();
    }

    function readTestCasesAndSaveThePrisoners(nTestCases: number): number[] {
        let prisonersChairNumberToWarn: number[] = new Array(nTestCases);

        for (let i = 0; i < nTestCases; i++) {
            const TEST_CASE: number[] = readTestCase();
            prisonersChairNumberToWarn[i] = saveThePrisoner(TEST_CASE);
        }

        return prisonersChairNumberToWarn;
    }

        function readTestCase(): number[] {
            const TEST_CASE: number[] = readLine().split(' ').map(Number);
            return TEST_CASE;
        }

        function saveThePrisoner(testCase: number[]): number {
            const PRISONERS: number = testCase[0];
            const SWEETS: number = testCase[1];
            const CHAIR_NUMBER_TO_BEGIN: number = testCase[2];
            let prisonerChairNumberToWarn: number = CHAIR_NUMBER_TO_BEGIN + (SWEETS - 1);

            if (prisonerChairNumberToWarn > PRISONERS) {
                prisonerChairNumberToWarn %= PRISONERS;

                if (prisonerChairNumberToWarn === 0)
                    prisonerChairNumberToWarn = PRISONERS;
            }

            return prisonerChairNumberToWarn;
        }

    function printResults(array: number[]) {
        array.forEach(element => console.log(element));
    }
