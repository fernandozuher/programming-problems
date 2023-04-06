// Source: https://www.hackerrank.com/challenges/append-and-delete/problem?isFullScreen=true

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
    const INITIAL_STRING = readLine();
    const FINAL_STRING = readLine();
    const NUMBER_OF_OPERATIONS = +readLine();

    const OBJ = new AppendAndDelete(INITIAL_STRING, FINAL_STRING, NUMBER_OF_OPERATIONS);
    const RESPONSE = OBJ.getResponse();
    printOutput(RESPONSE);
}

    function printOutput(response) {
        console.log(response ? "Yes" : "No");
    }

    class AppendAndDelete {
        #initialString;
        #finalString;
        #numberOfOperations;

        #commonPrefixSizeBetweenStrings;
        #areOperationsSuitableToReplacement;

        constructor(initialString, finalString, numberOfOperations) {
            this.#initialString = initialString;
            this.#finalString = finalString;
            this.#numberOfOperations = numberOfOperations;

            this.#appendAndDelete();
        }

            #appendAndDelete() {
                this.#commonPrefixSizeBetweenStrings = this.#findCommonPrefixSizeBetweenStrings();

                const SIZE_OF_DIFFERENT_CHARACTERS_FROM_INITIAL_STRING = this.#initialString.length - this.#commonPrefixSizeBetweenStrings;
                const SIZE_OF_DIFFERENT_CHARACTERS_FROM_FINAL_STRING = this.#finalString.length - this.#commonPrefixSizeBetweenStrings;

                const MINIMAL_QUANTITY_OF_OPERATIONS_TO_REPLACE_STRING = SIZE_OF_DIFFERENT_CHARACTERS_FROM_INITIAL_STRING + SIZE_OF_DIFFERENT_CHARACTERS_FROM_FINAL_STRING;
                
                this.#numberOfOperations -= MINIMAL_QUANTITY_OF_OPERATIONS_TO_REPLACE_STRING;
                this.#areOperationsSuitableToReplacement = this.#areOperationsSuitableToReplaceString();
            }

                #findCommonPrefixSizeBetweenStrings() {
                    let size = 0;
                    while (size != this.#initialString.length && size != this.#finalString.length && this.#initialString[size] === this.#finalString[size])
                        size++;
                    return size;
                }

                #areOperationsSuitableToReplaceString() {
                    if (this.#numberOfOperations < 0 ||
                        (this.#areOperationsBiggerThanZeroAndOdd() && this.#areNotOperationsEnoughToRemoveAndReplaceCommonPrefix()))
                        return false;
                    return true;
                }

                    #areOperationsBiggerThanZeroAndOdd() {
                        return this.#numberOfOperations > 0 && this.#numberOfOperations%2 === 1;
                    }

                    #areNotOperationsEnoughToRemoveAndReplaceCommonPrefix() {
                        return this.#numberOfOperations < this.#commonPrefixSizeBetweenStrings*2;
                    }

        getResponse() {
            return this.#areOperationsSuitableToReplacement;
        }
    }
