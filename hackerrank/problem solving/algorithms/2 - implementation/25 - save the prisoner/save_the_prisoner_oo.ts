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
    let prisonersChairNumberToWarn: number[] = new Array(N_TEST_CASES);

    for (let i = 0; i < prisonersChairNumberToWarn.length; i++) {
        const TEST_CASE: number[] = readTestCase();
        const OBJ: SaveThePrisoner = new SaveThePrisoner(TEST_CASE);
        prisonersChairNumberToWarn[i] = OBJ.getPrisonerChairNumberToWarn();
    }

    printResults(prisonersChairNumberToWarn);
}

    function readANumber() {
        return +readLine();
    }

    function readTestCase() {
        const TEST_CASE: number[] = readLine().split(' ').map(Number);
        return TEST_CASE;
    }

    class SaveThePrisoner {

        private _prisoners;
        private _sweets;
        private _chairNumberToBegin;
        private _prisonerChairNumberToWarn;

        constructor(testCase: number[]) {
            this._prisoners = testCase[0];
            this._sweets = testCase[1];
            this._chairNumberToBegin = testCase[2];

            this._prisonerChairNumberToWarn = this._saveThePrisoner();
        }

            private _saveThePrisoner() {
                let prisonerChairNumberToWarn = this._chairNumberToBegin + (this._sweets - 1);

                if (prisonerChairNumberToWarn > this._prisoners) {
                    prisonerChairNumberToWarn %= this._prisoners;

                    if (prisonerChairNumberToWarn === 0)
                        prisonerChairNumberToWarn = this._prisoners;
                }

                return prisonerChairNumberToWarn;
            }

        public getPrisonerChairNumberToWarn() {
            return this._prisonerChairNumberToWarn;
        }
    }

    function printResults(array: number[]) {
        array.forEach(element => console.log(element));
    }
