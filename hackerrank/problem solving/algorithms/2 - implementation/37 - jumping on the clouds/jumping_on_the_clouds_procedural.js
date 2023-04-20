// Source: https://www.hackerrank.com/challenges/jumping-on-the-clouds/problem?isFullScreen=true

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
    const CLOUD_ARRAY = readAnArray();
    const MINIMUM_NUMBER_OF_JUMPS = calculateMinimumNumberOfJumps(CLOUD_ARRAY);
    console.log(MINIMUM_NUMBER_OF_JUMPS);
}

    function readAnArray() {
        const ARRAY = readLine().split(" ").map(Number);
        return ARRAY;
    }

    function calculateMinimumNumberOfJumps(array) {
        let jumps = 0;

        for (let i = 0, size = array.length - 1; i < size; ) {
            i = getIndexOfNextJump(i, array);
            jumps++;
        }

        return jumps;
    }

        function getIndexOfNextJump(index, array) {
            if (isNextSecondIndexInsideRange(index + 2, array.length))
                index += isNextSecondCloudCumulus(array[index + 2]) ? 2 : 1;
            else
                index++;
            return index;
        }

            function isNextSecondIndexInsideRange(index, size) {
                return index < size;
            }

            function isNextSecondCloudCumulus(typeOfCloud) {
                return typeOfCloud === 0;
            }
