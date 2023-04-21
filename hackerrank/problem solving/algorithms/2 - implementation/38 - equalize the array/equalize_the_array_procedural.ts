// Source: https://www.hackerrank.com/challenges/equality-in-a-array/problem?isFullScreen=true

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
    const _: number = +readLine();
    const ARRAY: Array<number> = readAnArray();

    const MINIMUM_NUMBER_OF_DELETIONS_REQUIRED: number = equalizeArray(ARRAY);
    console.log(MINIMUM_NUMBER_OF_DELETIONS_REQUIRED);
}

    function readAnArray(): Array<number>  {
        const ARRAY: Array<number> = readLine().split(" ").map(Number);
        return ARRAY;
    }

    function equalizeArray(array: Array<number>): number {
        array.sort((a, b) => a - b);
        const MAXIMUM_QUANTITY_OF_EQUAL_ELEMENT: number = findMaximumQuantityOfEqualElement(array);
        const MINIMUM_NUMBER_OF_DELETIONS_REQUIRED: number = array.length - MAXIMUM_QUANTITY_OF_EQUAL_ELEMENT;
        return MINIMUM_NUMBER_OF_DELETIONS_REQUIRED;
    }

    function findMaximumQuantityOfEqualElement(array: Array<number>): number {
        let maximumQuantityOfEqualElement: number = 1;

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

        function areConsecutiveElementesEqual(element1: number, element2: number): boolean {
            return element1 === element2;
        }
