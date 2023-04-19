// Source: https://www.hackerrank.com/challenges/repeated-string/problem?isFullScreen=true

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
    const INPUT_STRING = readLine();
    const N_CHARACTERS = +readLine();

    const OBJ = new RepeatedString(INPUT_STRING, N_CHARACTERS);
    const QUANTITY_OF_A = OBJ.getQuantityOfA();
    console.log(QUANTITY_OF_A);
}

    class RepeatedString {
        #inputString;
        #nCharacters;
        #quantityOfA;

        constructor(inputString, nCharacters) {
            this.#inputString = inputString;
            this.#nCharacters = nCharacters;
            this.#quantityOfA = 0;

            this.#findQuantityOfAInRepeatedString();
        }

            #findQuantityOfAInRepeatedString() {
                this.#quantityOfA = this.#findQuantityOfAInString(this.#inputString);
                this.#quantityOfA *= this.#findQuantityOfRepeatedEntireString();
                this.#quantityOfA += this.#findQuantityOfRemainingA();
            }

                #findQuantityOfAInString(inputString) {
                    let quantityOfA = 0;

                    for (let character of inputString)
                        if (character === 'a')
                            quantityOfA++;

                    return quantityOfA;
                }

                #findQuantityOfRepeatedEntireString() {
                    const N_STRINGS = Math.trunc(this.#nCharacters / this.#inputString.length);
                    return N_STRINGS;
                }

                #findQuantityOfRemainingA() {
                    const N_REMAINING_CHARACTERS_OF_STRING = this.#nCharacters % this.#inputString.length;

                    if (N_REMAINING_CHARACTERS_OF_STRING == 0)
                        return 0;

                    const SUB_STRING = this.#inputString.substring(0, N_REMAINING_CHARACTERS_OF_STRING);
                    return this.#findQuantityOfAInString(SUB_STRING);
                }

        getQuantityOfA() {
            return this.#quantityOfA;
        }
    }
