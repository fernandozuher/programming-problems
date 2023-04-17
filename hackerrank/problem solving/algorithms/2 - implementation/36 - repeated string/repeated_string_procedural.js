// Source: https://www.hackerrank.com/challenges/repeated-string/problem?isFullScreen=true

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
    const INPUT_STRING = readLine();
    const N_CHARACTERS = +readLine();

    const QUANTITY_OF_A = findQuantityOfAInRepeatedString(INPUT_STRING, N_CHARACTERS);
    console.log(QUANTITY_OF_A);
}

    function findQuantityOfAInRepeatedString(inputString, nCharacters) {
        let quantityOfA = findQuantityOfAInString(inputString);
        quantityOfA *= findQuantityOfRepeatedEntireString(nCharacters, inputString.length);
        quantityOfA += findQuantityOfRemainingA(nCharacters, inputString);

        return quantityOfA;
    }

        function findQuantityOfAInString(inputString) {
            let quantityOfA = 0;

            for (let character of inputString)
                if (character === 'a')
                    quantityOfA++;

            return quantityOfA;
        }

        function findQuantityOfRepeatedEntireString(nCharacters, sizeString) {
            const N_STRINGS = Math.trunc(nCharacters / sizeString);
            return N_STRINGS;
        }

        function findQuantityOfRemainingA(nCharacters, inputString) {
            const N_REMAINING_CHARACTERS_OF_STRING = nCharacters % inputString.length;

            if (N_REMAINING_CHARACTERS_OF_STRING == 0)
                return 0;

            const SUB_STRING = inputString.substring(0, N_REMAINING_CHARACTERS_OF_STRING);
            return findQuantityOfAInString(SUB_STRING);
        }
