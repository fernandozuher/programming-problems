// Source: https://www.hackerrank.com/challenges/cut-the-sticks/problem?isFullScreen=true

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
    const _SIZE = +readLine();
    const ARRAY = readAnArray();
    ARRAY.sort((a, b) => a - b);

    const OBJ = new CutTheSticks(ARRAY);
    const RESULT = OBJ.getRemainingSticksLengthArray();
    printArray(RESULT);
}

    function readAnArray() {
        return readLine().split(" ").map(Number);
    }

    function printArray(array) {
        array.forEach((element, _) => console.log(element));
    }

    class CutTheSticks {
        #sticksLengthArray;
        #sizeSticksLengthArray;
        #remainingSticksLengthArray;

        constructor(array) {
            this.#sticksLengthArray = array;
            this.#sizeSticksLengthArray = array.length;
            this.#initializeRemainingSticksLengthArray();
            this.#cutTheSticks();
        }

            #initializeRemainingSticksLengthArray() {
                this.#remainingSticksLengthArray = [this.#sizeSticksLengthArray];
            }

            #cutTheSticks() {
                for (let i = 0; i < this.#sizeSticksLengthArray; ) {
                    const SHORTEST_STICK_LENGTH = this.#sticksLengthArray[i];

                    i = this.#findFirstElementIndexDifferentOfFirstCurrentShortestStickLengthIndex(i);
                    const CURRENT_ITERATION_SIZE = this.#sizeSticksLengthArray - i;
                    if (i === this.#sizeSticksLengthArray)
                        break;

                    this.#remainingSticksLengthArray.push(CURRENT_ITERATION_SIZE);
                    this.#decreaseSticksLengthsHigherThanCurrentShortestStickLength(i, SHORTEST_STICK_LENGTH);
                }
            }

                #findFirstElementIndexDifferentOfFirstCurrentShortestStickLengthIndex(index) {
                    const SHORTEST_STICK_LENGTH = this.#sticksLengthArray[index];
                    while (index < this.#sizeSticksLengthArray && this.#sticksLengthArray[index] === SHORTEST_STICK_LENGTH)
                        index++;
                    return index;
                }

                #decreaseSticksLengthsHigherThanCurrentShortestStickLength(index, shortestStickLength) {
                    for (let i = index; i < this.#sizeSticksLengthArray; i++)
                        this.#sticksLengthArray[i] -= shortestStickLength;
                }

        getRemainingSticksLengthArray() {
            return this.#remainingSticksLengthArray;
        }
    }
