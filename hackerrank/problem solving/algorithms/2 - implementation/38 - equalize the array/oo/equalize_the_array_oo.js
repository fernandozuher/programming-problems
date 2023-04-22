// Source: https://www.hackerrank.com/challenges/equality-in-a-array/problem?isFullScreen=true

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
    const _ = +readLine();
    const ARRAY = readAnArray();

    const OBJ = new EqualizeTheArray(ARRAY);
    const MINIMUM_NUMBER_OF_DELETIONS_REQUIRED = OBJ.getMinimumNumberOfDeletionsRequired();
    console.log(MINIMUM_NUMBER_OF_DELETIONS_REQUIRED);
}

    function readAnArray()  {
        const ARRAY = readLine().split(" ").map(Number);
        return ARRAY;
    }

    class EqualizeTheArray {
        #array;
        #minimumNumberOfDeletionsRequired;

        constructor(array) {
            array.sort((a, b) => a - b);
            this.#array = array;
            this.#equalizeArray();
        }
        
            #equalizeArray() {
                const MAXIMUM_QUANTITY_OF_EQUAL_ELEMENT = this.#findMaximumQuantityOfEqualElement();
                this.#minimumNumberOfDeletionsRequired = this.#array.length - MAXIMUM_QUANTITY_OF_EQUAL_ELEMENT;
            }

                #findMaximumQuantityOfEqualElement() {
                    let maximumQuantityOfEqualElement = 1;

                    for (let i = 1, temporaryQuantityEqualElement = 1, size = this.#array.length; i < size; i++) {

                        if (this.#areConsecutiveElementesEqual(this.#array[i - 1], this.#array[i])) {
                            temporaryQuantityEqualElement++;
                            maximumQuantityOfEqualElement = Math.max(temporaryQuantityEqualElement, maximumQuantityOfEqualElement);
                        }
                        else
                            temporaryQuantityEqualElement = 1;
                    }

                    return maximumQuantityOfEqualElement;
                }

                    #areConsecutiveElementesEqual(element1, element2) {
                        return element1 === element2;
                    }

        getMinimumNumberOfDeletionsRequired() {
            return this.#minimumNumberOfDeletionsRequired;
        }
    }
