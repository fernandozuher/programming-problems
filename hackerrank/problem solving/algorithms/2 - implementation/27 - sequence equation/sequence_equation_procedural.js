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
        const ELEMENTS_POSITIONS_ARRAY = generateElementsPositionsArray(array);
        const PERMUTATED_ARRAY = generatePermutatedArray(ELEMENTS_POSITIONS_ARRAY);
        return PERMUTATED_ARRAY;
    }

        function generateElementsPositionsArray(array) {
            const elementsPositionsArray = new Array(array.length).fill(0);
            array.forEach((element, i) => {
                elementsPositionsArray[element-1] = i;
            });
            return elementsPositionsArray;
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
