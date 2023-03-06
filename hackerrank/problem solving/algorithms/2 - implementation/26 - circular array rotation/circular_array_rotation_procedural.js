// Source: https://www.hackerrank.com/challenges/circular-array-rotation/problem?isFullScreen=true

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
    let input = readInput();
    input = reduceInputRotations(input);
    input = rotateInputArray(input);
    printRotatedArrayElementsAccordingToQueries(input);
}

    function readInput() {
        const [ARRAY_SIZE, ROTATION_COUNT, QUERIES_SIZE] = readLineAsNumericArray();
        const ARRAY = readLineAsNumericArray();
        const QUERIES = readQueries(QUERIES_SIZE);
        const INPUT = [ARRAY, ARRAY_SIZE, ROTATION_COUNT, QUERIES, QUERIES_SIZE];
        return INPUT;
    }

        function readLineAsNumericArray() {
            const ARRAY = readLine().split(" ").map(Number);
            return ARRAY;
        }

        function readQueries(size) {
            const ARRAY = new Array(size).fill().map(element => +readLine());
            return ARRAY;
        }

    function reduceInputRotations(input) {
        const ARRAY_SIZE = input[1];
        let rotationCount = input[2];

        if (ARRAY_SIZE > 1)
            input[2] = rotationCount = rotationCount >= ARRAY_SIZE ? rotationCount % ARRAY_SIZE : rotationCount;
        else
            input[2] = rotationCount = 0;

        return input;
    }

    function rotateInputArray(input) {
        const ARRAY = input[0];
        const ARRAY_SIZE = input[1];
        const ROTATION_COUNT = input[2];

        const FIRST_PART_NEW_ARRAY = ARRAY.slice(ARRAY_SIZE - ROTATION_COUNT, ARRAY_SIZE);
        const SECOND_PART_NEW_ARRAY = ARRAY.slice(0, ARRAY_SIZE - ROTATION_COUNT);
        const NEW_ARRAY = [...FIRST_PART_NEW_ARRAY, ...SECOND_PART_NEW_ARRAY];

        input[0] = NEW_ARRAY;
        return input;
    }

    function printRotatedArrayElementsAccordingToQueries(input) {
        const ARRAY = input[0];
        const QUERIES = input[3];
        QUERIES.forEach(query => console.log(ARRAY[query]));
    }
