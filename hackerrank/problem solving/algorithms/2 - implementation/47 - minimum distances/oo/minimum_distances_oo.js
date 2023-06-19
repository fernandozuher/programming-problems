// Source: https://www.hackerrank.com/challenges/minimum-distances/problem?isFullScreen=true

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


const NO_INDEX = -1;

function main() {
    const _ = +readLine();
    const ARRAY = readANumericArray();
    const OBJ = new MinimumDistances(ARRAY);
    console.log(OBJ.getMinimumDistance());
}

    function readANumericArray() {
        return readLine().split(" ").map(Number);
    }

    class MinimumDistances {
        #array;
        #minimumDistance;

        constructor(array) {
            this.#array = array;
            this.#minimumDistance = Number.MAX_SAFE_INTEGER;
            this.#findMinimumDistance();
        }

            #findMinimumDistance() {
                const FIRST_INDEXES_OF_ELEMENTS = {};

                for (let i = 0, element; i < this.#array.length; i++) {
                    element = this.#array[i];
                
                    if (FIRST_INDEXES_OF_ELEMENTS.hasOwnProperty(element)) {
                        let [firstIndex, secondIndex] = FIRST_INDEXES_OF_ELEMENTS[element]

                        if (secondIndex == NO_INDEX) {
                            FIRST_INDEXES_OF_ELEMENTS[element][1] = secondIndex = i;
                            const MINIMUM_DISTANCE_OF_CURRENT_ELEMENT = secondIndex - firstIndex;
                            this.#minimumDistance = Math.min(this.#minimumDistance, MINIMUM_DISTANCE_OF_CURRENT_ELEMENT);
                        }
                    } else
                        FIRST_INDEXES_OF_ELEMENTS[element] = [i, NO_INDEX];
                }

                this.#minimumDistance = this.#minimumDistanceOrNoIndex();
            }

                #minimumDistanceOrNoIndex() {
                    return this.#minimumDistance != Number.MAX_SAFE_INTEGER ? this.#minimumDistance : NO_INDEX;
                }

        getMinimumDistance() {
            return this.#minimumDistance;
        }
    }
