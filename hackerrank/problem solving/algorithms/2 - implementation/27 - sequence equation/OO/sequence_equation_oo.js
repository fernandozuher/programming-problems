// Source: https://www.hackerrank.com/challenges/permutation-equation/problem?isFullScreen=true

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
    const SIZE = readANumber();
    const ARRAY = readAnArray();

    const OBJ = new SequenceEquation(ARRAY);
    OBJ.printPermutatedArray();
}

    function readANumber() {
        return +readLine();
    }

    function readAnArray() {
        const ARRAY = readLine().split(" ").map(Number);
        return ARRAY;
    }

    class SequenceEquation {
        #inputArray;
        #elementsPositionsArray;
        #permutatedArray;

        constructor(array) {
            this.#inputArray = array;
            this.#elementsPositionsArray = this.#generateElementsPositionsArray();
            this.#permutatedArray = this.#generatePermutatedArray();
        }

            #generateElementsPositionsArray() {
                const elementsPositionsArray = new Array(this.#inputArray.length).fill(0);
                this.#inputArray.forEach((element, i) => {
                    elementsPositionsArray[element-1] = i;
                });
                return elementsPositionsArray;
            }

            #generatePermutatedArray() {
                const permutatedArray = new Array(this.#elementsPositionsArray.length).fill(0);
                this.#elementsPositionsArray.forEach((element, i) => {
                    permutatedArray[i] = this.#elementsPositionsArray[element] + 1;
                });
                return permutatedArray;
            }

        printPermutatedArray() {
            this.#permutatedArray.forEach(element => console.log(element));
        }
    }
