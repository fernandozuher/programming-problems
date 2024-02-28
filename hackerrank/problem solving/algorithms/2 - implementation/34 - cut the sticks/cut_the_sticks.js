// https://www.hackerrank.com/challenges/cut-the-sticks/problem?isFullScreen=true

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
    array.sort((a, b) => a - b);

    let obj = new CutTheSticks(array);
    printArray(obj.remainingSticksLengthArray());
}

    function readIntArray() {
        return readLine().split(' ').map(Number);
    }

    function printArray(array) {
        array.forEach(x => console.log(x));
    }

    class CutTheSticks {
        #sticksLengthArray;
        #remainingSticksLengthArray;

        constructor(array) {
            this.#sticksLengthArray = array;
            this.#remainingSticksLengthArray = [array.length];
            this.#cutTheSticks();
        }

            #cutTheSticks() {
                for (let i = 0, n = this.#sticksLengthArray.length; i < n;) {
                    let shortestStickLength = this.#sticksLengthArray[i];

                    i = this.#findFirstElementIndexDifferentOfFirstCurrentShortestStickLengthIndex(i, n);
                    let currentIterationSize = n - i;
                    if (i === n)
                        break;

                    this.#remainingSticksLengthArray.push(currentIterationSize);
                    this.#decreaseSticksLengthsHigherThanCurrentShortestStickLength(i, n, shortestStickLength);
                }
            }

                #findFirstElementIndexDifferentOfFirstCurrentShortestStickLengthIndex(index, n) {
                    let shortestStickLength = this.#sticksLengthArray[index];
                    while (index < n && this.#sticksLengthArray[index] === shortestStickLength)
                        ++index;
                    return index;
                }

                #decreaseSticksLengthsHigherThanCurrentShortestStickLength(index, n, shortestStickLength) {
                    for (let i = index; i < n; ++i)
                        this.#sticksLengthArray[i] -= shortestStickLength;
                }

        remainingSticksLengthArray() {
            return this.#remainingSticksLengthArray;
        }
    }
