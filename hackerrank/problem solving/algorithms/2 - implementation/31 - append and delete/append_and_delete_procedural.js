// Source: https://www.hackerrank.com/challenges/append-and-delete/problem?isFullScreen=true

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
    const INITIAL_STRING = readLine();
    const FINAL_STRING = readLine();
    const NUMBER_OF_OPERATIONS = +readLine();

    const RESPONSE = appendAndDelete(INITIAL_STRING, FINAL_STRING, NUMBER_OF_OPERATIONS);
    printOutput(RESPONSE);
}

    function appendAndDelete(initialString, finalString, numberOfOperations) {
        const COMMON_PREFIX_SIZE_BETWEEN_STRINGS = findCommonPrefixSizeBetweenStrings(initialString, finalString);

        const SIZE_OF_DIFFERENT_CHARACTERS_FROM_INITIAL_STRING = initialString.length - COMMON_PREFIX_SIZE_BETWEEN_STRINGS;
        const SIZE_OF_DIFFERENT_CHARACTERS_FROM_FINAL_STRING = finalString.length - COMMON_PREFIX_SIZE_BETWEEN_STRINGS;

        const MINIMAL_QUANTITY_OF_OPERATIONS_TO_REPLACE_STRING = SIZE_OF_DIFFERENT_CHARACTERS_FROM_INITIAL_STRING + SIZE_OF_DIFFERENT_CHARACTERS_FROM_FINAL_STRING;
        numberOfOperations -= MINIMAL_QUANTITY_OF_OPERATIONS_TO_REPLACE_STRING;

        return areOperationsSuitableToReplaceString(numberOfOperations, COMMON_PREFIX_SIZE_BETWEEN_STRINGS);
    }

        function findCommonPrefixSizeBetweenStrings(initialString, finalString) {
            let size = 0;
            while (size != initialString.length && size != finalString.length && initialString[size] === finalString[size])
                size++;
            return size;
        }

        function areOperationsSuitableToReplaceString(numberOfOperations, commonPrefixSizeBetweenStrings) {
            if (numberOfOperations < 0 ||
                (areOperationsBiggerThanZeroAndOdd(numberOfOperations) &&
                    areNotOperationsEnoughToRemoveAndReplaceCommonPrefix(numberOfOperations, commonPrefixSizeBetweenStrings)))
                return false;
            return true;
        }

            function areOperationsBiggerThanZeroAndOdd(numberOfOperations) {
                return numberOfOperations > 0 && numberOfOperations%2 === 1;
            }

            function areNotOperationsEnoughToRemoveAndReplaceCommonPrefix(numberOfOperations, commonPrefixSizeBetweenStrings) {
                return numberOfOperations < commonPrefixSizeBetweenStrings*2;
            }

    function printOutput(response) {
        console.log(response ? "Yes" : "No");
    }
