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
    let prisonersChairNumberToWarn = new Array(N_TEST_CASES);

    for (let i = 0; i < prisonersChairNumberToWarn.length; i++) {
        const TEST_CASE = readTestCase();
        const OBJ = new SaveThePrisoner(TEST_CASE);
        prisonersChairNumberToWarn[i] = OBJ.getPrisonerChairNumberToWarn();
    }

    printResults(prisonersChairNumberToWarn);
}

    function readANumber() {
        return +readLine();
    }

    function readTestCase() {
        const TEST_CASE = readLine().split(' ').map(Number);
        return TEST_CASE;
    }

    class SaveThePrisoner {

        #prisoners;
        #sweets;
        #chairNumberToBegin;
        #prisonerChairNumberToWarn;

        constructor(testCase) {
            this.#prisoners = testCase[0];
            this.#sweets = testCase[1];
            this.#chairNumberToBegin = testCase[2];

            this.#prisonerChairNumberToWarn = this.#saveThePrisoner();
        }

            #saveThePrisoner() {
                let prisonerChairNumberToWarn = this.#chairNumberToBegin + (this.#sweets - 1);

                if (prisonerChairNumberToWarn > this.#prisoners) {
                    prisonerChairNumberToWarn %= this.#prisoners;

                    if (prisonerChairNumberToWarn === 0)
                        prisonerChairNumberToWarn = this.#prisoners;
                }

                return prisonerChairNumberToWarn;
            }

        getPrisonerChairNumberToWarn() {
            return this.#prisonerChairNumberToWarn;
        }
    }

    function printResults(array) {
        array.forEach(element => console.log(element));
    }
