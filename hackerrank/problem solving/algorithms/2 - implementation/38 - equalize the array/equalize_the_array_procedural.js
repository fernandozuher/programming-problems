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

    const MINIMUM_NUMBER_OF_DELETIONS_REQUIRED = equalizeArray(ARRAY);
    console.log(MINIMUM_NUMBER_OF_DELETIONS_REQUIRED);
}

    function readAnArray()  {
        const ARRAY = readLine().split(" ").map(Number);
        return ARRAY;
    }

    function equalizeArray(array) {
        array.sort((a, b) => a - b);
        const MAXIMUM_QUANTITY_OF_EQUAL_ELEMENT = findMaximumQuantityOfEqualElement(array);
        const MINIMUM_NUMBER_OF_DELETIONS_REQUIRED = array.length - MAXIMUM_QUANTITY_OF_EQUAL_ELEMENT;
        return MINIMUM_NUMBER_OF_DELETIONS_REQUIRED;
    }

    function findMaximumQuantityOfEqualElement(array) {
        let maximumQuantityOfEqualElement = 1;

        for (let i = 1, temporaryQuantityEqualElement = 1, size = array.length; i < size; i++) {

            if (areConsecutiveElementesEqual(array[i - 1], array[i])) {
                temporaryQuantityEqualElement++;
                maximumQuantityOfEqualElement = Math.max(temporaryQuantityEqualElement, maximumQuantityOfEqualElement);
            }
            else
                temporaryQuantityEqualElement = 1;
        }

        return maximumQuantityOfEqualElement;
    }

        function areConsecutiveElementesEqual(element1, element2) {
            return element1 === element2;
        }
