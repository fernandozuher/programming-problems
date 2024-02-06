// https://www.hackerrank.com/challenges/circular-array-rotation/problem?isFullScreen=true

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
    let [n, rotationCount, nQueries] = readIntArray();
    let array = readIntArray();
    let queries = readLines(nQueries);

    let obj = new CircularArrayRotation(array, rotationCount);
    printArrayAccordingToIndexFromAnotherArray(obj.rotatedArray(), queries);
}

    function readIntArray() {
        return readLine().split(' ').map(Number);
    }

    function readLines(n) {
        return Array(n).fill(0).map(_ => +readLine());
    }

    function printArrayAccordingToIndexFromAnotherArray(array1, array2) {
        array2.forEach(i => console.log(array1[i]));
    }

    class CircularArrayRotation {
        #array;
        #rotationCount;

        constructor(array, rotationCount) {
            this.#array = array;
            this.#rotationCount = rotationCount
            this.#reduceRotations();
            this.#rotateArray();
        }
        
            #reduceRotations() {
                if (this.#array.length > 1)
                    this.#rotationCount = this.#rotationCount >= this.#array.length ? this.#rotationCount % this.#array.length : this.#rotationCount;
                else
                    this.#rotationCount = 0;
            }

            #rotateArray() {
                let firstPartNewArray = this.#array.slice(this.#array.length - this.#rotationCount, this.#array.length);
                let secondPartNewArray = this.#array.slice(0, this.#array.length - this.#rotationCount);
                this.#array = [...firstPartNewArray, ...secondPartNewArray];
            }

        rotatedArray() {
            return this.#array;
        }
    }
