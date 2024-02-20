// https://www.hackerrank.com/challenges/append-and-delete/problem?isFullScreen=true

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
    let initialString = readLine();
    let finalString = readLine();
    let operations = +readLine();
    let obj = new AppendAndDelete(initialString, finalString, operations);
    console.log(obj.areOperationsSuitableToReplacement() ? "Yes" : "No");
}

    class AppendAndDelete {
        #initialString;
        #finalString;
        #operations;

        #commonPrefixSizeBetweenStrings;
        #areOperationsSuitableToReplacement;

        constructor(initialString, finalString, operations) {
            this.#initialString = initialString;
            this.#finalString = finalString;
            this.#operations = operations;
            this.#commonPrefixSizeBetweenStrings = 0;
            this.#areOperationsSuitableToReplacement = false;
            this.#appendAndDelete();
        }

            #appendAndDelete() {
                this.#commonPrefixSizeBetweenStrings = this.#findCommonPrefixSizeBetweenStrings();

                let sizeOfDifferentCharactersFromInitialString = this.#initialString.length - this.#commonPrefixSizeBetweenStrings;
                let sizeOfDifferentCharactersFromFinalString = this.#finalString.length - this.#commonPrefixSizeBetweenStrings;

                let minimalQuantityOfOperationsToReplaceString = sizeOfDifferentCharactersFromInitialString + sizeOfDifferentCharactersFromFinalString;
                
                this.#operations -= minimalQuantityOfOperationsToReplaceString;
                this.#areOperationsSuitableToReplacement = this.#areOperationsSuitableToReplaceString();
            }

                #findCommonPrefixSizeBetweenStrings() {
                    let size = 0;
                    let n = Math.min(this.#initialString.length, this.#finalString.length);
                    while (n-- && this.#initialString[size] === this.#finalString[size])
                        ++size;
                    return size;
                }

                #areOperationsSuitableToReplaceString() {
                    if (this.#operations < 0 ||
                        (this.#areOperationsBiggerThanZeroAndOdd() && this.#areNotOperationsEnoughToRemoveAndReplaceCommonPrefix()))
                        return false;
                    return true;
                }

                    #areOperationsBiggerThanZeroAndOdd() {
                        return this.#operations > 0 && this.#operations%2 === 1;
                    }

                    #areNotOperationsEnoughToRemoveAndReplaceCommonPrefix() {
                        return this.#operations < this.#commonPrefixSizeBetweenStrings*2;
                    }

        areOperationsSuitableToReplacement() {
            return this.#areOperationsSuitableToReplacement;
        }
    }
