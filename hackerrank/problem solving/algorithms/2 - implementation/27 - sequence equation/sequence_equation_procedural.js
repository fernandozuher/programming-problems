// Source: https://www.hackerrank.com/challenges/permutation-equation/problem?isFullScreen=true

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
    const SIZE = readANumber();
    const ARRAY = readAnArray();

    const PERMUTATED_ARRAY = permutationEquation(ARRAY);
    printArray(PERMUTATED_ARRAY);
}

    function readANumber() {
        return +readLine();
    }

    function readAnArray() {
        const ARRAY = readLine().split(" ").map(Number);
        return ARRAY;
    }

    function permutationEquation(array) {
        const ARRAY_ELEMENTS_POSITIONS = generateArrayOfElementsPositions(array);
        const PERMUTATED_ARRAY = generatePermutatedArray(ARRAY_ELEMENTS_POSITIONS);
        return PERMUTATED_ARRAY;
    }

        function generateArrayOfElementsPositions(array) {
            const arrayElementsPositions = new Array(array.length).fill(0);
            array.forEach((element, i) => {
                arrayElementsPositions[element-1] = i;
            });
            return arrayElementsPositions;
        }

        function generatePermutatedArray(array) {
            const permutatedArray = new Array(array.length).fill(0);
            array.forEach((element, i) => {
                permutatedArray[i] = array[element] + 1;
            });
            return permutatedArray;
        }

    function printArray(array) {
        array.forEach(element => console.log(element));
    }
