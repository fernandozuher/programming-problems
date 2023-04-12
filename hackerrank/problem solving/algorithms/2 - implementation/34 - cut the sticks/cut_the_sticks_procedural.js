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

    const RESULT = cutTheSticks(ARRAY);
    printArray(RESULT);
}

    function readAnArray() {
        return readLine().split(" ").map(Number);
    }

    function cutTheSticks(array) {
        const SIZE = array.length;
        const REMAINING_STICKS_OF_EACH_ITERATION = initializeResult(SIZE);

        for (let i = 0; i < SIZE; ) {
            const SHORTEST_STICK_LENGTH = array[i];

            i = findFirstElementIndexDifferentOfFirstCurrentShortestStickLengthIndex(i, array);
            const CURRENT_ITERATION_SIZE = SIZE - i;
            if (i === SIZE)
                break;

            REMAINING_STICKS_OF_EACH_ITERATION.push(CURRENT_ITERATION_SIZE);
            decreaseSticksLengthsHigherThanCurrentShortestStickLength(i, array, SHORTEST_STICK_LENGTH);
        }

        return REMAINING_STICKS_OF_EACH_ITERATION;
    }

        function initializeResult(size) {
            const REMAINING_STICKS_OF_EACH_ITERATION = [size];
            return REMAINING_STICKS_OF_EACH_ITERATION;
        }

        function findFirstElementIndexDifferentOfFirstCurrentShortestStickLengthIndex(index, array) {
            const SIZE = array.length;
            const SHORTEST_STICK_LENGTH = array[index];
            while (index < SIZE && array[index] === SHORTEST_STICK_LENGTH)
                index++;
            return index;
        }

        function decreaseSticksLengthsHigherThanCurrentShortestStickLength(index, array, shortestStickLength) {
            for (let i = index, size = array.length; i < size; i++)
                array[i] -= shortestStickLength;
        }

    function printArray(array) {
        array.forEach((element, _) => console.log(element));
    }
