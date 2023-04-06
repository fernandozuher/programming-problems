// Source: https://www.hackerrank.com/challenges/append-and-delete/problem?isFullScreen=true

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
    const INITIAL_STRING: string = readLine();
    const FINAL_STRING: string = readLine();
    const NUMBER_OF_OPERATIONS: number = +readLine();

    const RESPONSE: boolean = appendAndDelete(INITIAL_STRING, FINAL_STRING, NUMBER_OF_OPERATIONS);
    printOutput(RESPONSE);
}

    function appendAndDelete(initialString: string, finalString: string, numberOfOperations: number): boolean {
        const COMMON_PREFIX_SIZE_BETWEEN_STRINGS: number = findCommonPrefixSizeBetweenStrings(initialString, finalString);

        const SIZE_OF_DIFFERENT_CHARACTERS_FROM_INITIAL_STRING: number = initialString.length - COMMON_PREFIX_SIZE_BETWEEN_STRINGS;
        const SIZE_OF_DIFFERENT_CHARACTERS_FROM_FINAL_STRING: number = finalString.length - COMMON_PREFIX_SIZE_BETWEEN_STRINGS;

        const MINIMAL_QUANTITY_OF_OPERATIONS_TO_REPLACE_STRING: number = SIZE_OF_DIFFERENT_CHARACTERS_FROM_INITIAL_STRING + SIZE_OF_DIFFERENT_CHARACTERS_FROM_FINAL_STRING;
        numberOfOperations -= MINIMAL_QUANTITY_OF_OPERATIONS_TO_REPLACE_STRING;

        return areOperationsSuitableToReplaceString(numberOfOperations, COMMON_PREFIX_SIZE_BETWEEN_STRINGS);
    }

        function findCommonPrefixSizeBetweenStrings(initialString: string, finalString: string): number {
            let size: number = 0;
            while (size != initialString.length && size != finalString.length && initialString[size] === finalString[size])
                size++;
            return size;
        }

        function areOperationsSuitableToReplaceString(numberOfOperations: number, commonPrefixSizeBetweenStrings: number): boolean {
            if (numberOfOperations < 0 ||
                (areOperationsBiggerThanZeroAndOdd(numberOfOperations) &&
                    areNotOperationsEnoughToRemoveAndReplaceCommonPrefix(numberOfOperations, commonPrefixSizeBetweenStrings)))
                return false;
            return true;
        }

            function areOperationsBiggerThanZeroAndOdd(numberOfOperations: number): boolean {
                return numberOfOperations > 0 && numberOfOperations%2 === 1;
            }

            function areNotOperationsEnoughToRemoveAndReplaceCommonPrefix(numberOfOperations: number, commonPrefixSizeBetweenStrings: number): boolean {
                return numberOfOperations < commonPrefixSizeBetweenStrings*2;
            }

    function printOutput(response: boolean) {
        console.log(response ? "Yes" : "No");
    }
