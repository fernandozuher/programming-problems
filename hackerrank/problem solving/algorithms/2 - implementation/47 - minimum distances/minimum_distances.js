// https://www.hackerrank.com/challenges/minimum-distances/problem?isFullScreen=true

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
    console.log(findMinimumDistance(ARRAY));
}

    function readANumericArray() {
        return readLine().split(" ").map(Number);
    }

    function findMinimumDistance(array) {
        let minimumDistance = Number.MAX_SAFE_INTEGER;
        const FIRST_INDEXES_OF_ELEMENTS = {};

        for (let i = 0, element; i < array.length; i++) {
            element = array[i];
        
            if (FIRST_INDEXES_OF_ELEMENTS.hasOwnProperty(element)) {
                let [firstIndex, secondIndex] = FIRST_INDEXES_OF_ELEMENTS[element]

                if (secondIndex == NO_INDEX) {
                    FIRST_INDEXES_OF_ELEMENTS[element][1] = secondIndex = i;
                    const MINIMUM_DISTANCE_OF_CURRENT_ELEMENT = secondIndex - firstIndex;
                    minimumDistance = Math.min(minimumDistance, MINIMUM_DISTANCE_OF_CURRENT_ELEMENT);
                }
            } else
                FIRST_INDEXES_OF_ELEMENTS[element] = [i, NO_INDEX];
        }

        return minimumDistanceOrNoIndex(minimumDistance);
    }

        function minimumDistanceOrNoIndex(minimumDistance) {
            return minimumDistance != Number.MAX_SAFE_INTEGER ? minimumDistance : NO_INDEX;
        }
