// https://www.hackerrank.com/challenges/permutation-equation/problem?isFullScreen=true

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
    let array = readIntArray();
    let obj = new SequenceEquation(array);
    obj.permutatedArray().forEach(x => console.log(x));
}

    function readIntArray() {
        return readLine().split(' ').map(Number);
    }

    class SequenceEquation {
        #array;
        #elementsPositionsArray;
        #permutatedArray;

        constructor(array) {
            this.#array = array;
            this.#elementsPositionsArray = Array(array.length).fill(0);
            this.#permutatedArray = Array(array.length).fill(0);
            this.#generateElementsPositionsArray();
            this.#generatePermutatedArray();
        }

            #generateElementsPositionsArray() {
                this.#array.forEach((element, i) => {
                    this.#elementsPositionsArray[element-1] = i;
                });
            }

            #generatePermutatedArray() {
                this.#elementsPositionsArray.forEach((element, i) => {
                    this.#permutatedArray[i] = this.#elementsPositionsArray[element] + 1;
                });
            }

        permutatedArray() {
            return this.#permutatedArray;
        }
    }
