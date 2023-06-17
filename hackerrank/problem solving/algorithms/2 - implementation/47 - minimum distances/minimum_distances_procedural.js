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
        const ELEMENTS = {};

        for (let i = 0, element; i < array.length; i++) {
            element = array[i];
        
            if (ELEMENTS.hasOwnProperty(element)) {
                let [firstIndex, secondIndex] = ELEMENTS[element]

                if (secondIndex == -1) {
                    ELEMENTS[element][1] = secondIndex = i;
                    const MINIMUM_DISTANCE_OF_CURRENT_ELEMENT = secondIndex - firstIndex;
                    minimumDistance = Math.min(minimumDistance, MINIMUM_DISTANCE_OF_CURRENT_ELEMENT);
                }
            } else
                ELEMENTS[element] = [i, -1];
        }

        return minimumDistance != Number.MAX_SAFE_INTEGER ? minimumDistance : -1;
    }
