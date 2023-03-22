// Source: https://www.hackerrank.com/challenges/permutation-equation/problem?isFullScreen=true

'use strict';

process.stdin.resume();
process.stdin.setEncoding('utf-8');

let inputString: string = '';
let inputLines: string[] = [];
let currentLine: number = 0;

process.stdin.on('data', function(inputStdin: string): void {
    inputString += inputStdin;
});

process.stdin.on('end', function(): void {
    inputLines = inputString.split('\n');
    inputString = '';

    main();
});

function readLine(): string {
    return inputLines[currentLine++];
}


function main() {
    const SIZE: number = readANumber();
    const ARRAY: Array<number> = readAnArray();

    const PERMUTATED_ARRAY: Array<number> = permutationEquation(ARRAY);
    printArray(PERMUTATED_ARRAY);
}

    function readANumber(): number {
        return +readLine();
    }

    function readAnArray(): Array<number> {
        const ARRAY: Array<number> = readLine().split(" ").map(Number);
        return ARRAY;
    }

    function permutationEquation(array: Array<number>): Array<number> {
        const ARRAY_ELEMENTS_POSITIONS: Array<number> = generateArrayOfElementsPositions(array);
        const PERMUTATED_ARRAY: Array<number> = generatePermutatedArray(ARRAY_ELEMENTS_POSITIONS);
        return PERMUTATED_ARRAY;
    }

        function generateArrayOfElementsPositions(array: Array<number>): Array<number> {
            const arrayElementsPositions: Array<number> = new Array(array.length).fill(0);
            array.forEach((element, i) => {
                arrayElementsPositions[element-1] = i;
            });
            return arrayElementsPositions;
        }

        function generatePermutatedArray(array: Array<number>): Array<number> {
            const permutatedArray: Array<number> = new Array(array.length).fill(0);
            array.forEach((element, i) => {
                permutatedArray[i] = array[element] + 1;
            });
            return permutatedArray;
        }

    function printArray(array: Array<number>) {
        array.forEach(element => console.log(element));
    }
