// https://www.hackerrank.com/challenges/minimum-distances/problem?isFullScreen=true

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

const NO_INDEX = -1;

function main() {
    +readLine();
    let array = readIntArray();
    console.log(findMinimumDistance(array));
}

    function readIntArray() {
        return readLine().split(' ').map(Number);
    }

    function findMinimumDistance(array) {
        let minimumDistance = Number.MAX_SAFE_INTEGER;
        let first_indexes_of_elements = {};

        for (let i = 0, element; i < array.length; ++i) {
            element = array[i];
        
            if (first_indexes_of_elements.hasOwnProperty(element)) {
                let [firstIndex, secondIndex] = first_indexes_of_elements[element]

                if (secondIndex === NO_INDEX) {
                    first_indexes_of_elements[element][1] = secondIndex = i;
                    let minimum_distance_OF_current_element = secondIndex - firstIndex;
                    minimumDistance = Math.min(minimumDistance, minimum_distance_OF_current_element);
                }
            } else
                first_indexes_of_elements[element] = [i, NO_INDEX];
        }

        return minimumDistance !== Number.MAX_SAFE_INTEGER ? minimumDistance : NO_INDEX;
    }
