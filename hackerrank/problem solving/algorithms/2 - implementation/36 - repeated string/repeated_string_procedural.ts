// Source: https://www.hackerrank.com/challenges/repeated-string/problem?isFullScreen=true

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
    const INPUT_STRING: string = readLine();
    const N_CHARACTERS: number = +readLine();

    const QUANTITY_OF_A: number = findQuantityOfAInRepeatedString(INPUT_STRING, N_CHARACTERS);
    console.log(QUANTITY_OF_A);
}

    function findQuantityOfAInRepeatedString(inputString: string, nCharacters: number): number {
        let quantityOfA: number = findQuantityOfAInString(inputString);
        quantityOfA *= findQuantityOfRepeatedEntireString(nCharacters, inputString.length);
        quantityOfA += findQuantityOfRemainingA(nCharacters, inputString);

        return quantityOfA;
    }

        function findQuantityOfAInString(inputString: string): number {
            let quantityOfA: number = 0;

            for (let character of inputString)
                if (character === 'a')
                    quantityOfA++;

            return quantityOfA;
        }

        function findQuantityOfRepeatedEntireString(nCharacters: number, sizeString: number): number {
            const N_STRINGS: number = Math.trunc(nCharacters / sizeString);
            return N_STRINGS;
        }

        function findQuantityOfRemainingA(nCharacters: number, inputString: string): number {
            const N_REMAINING_CHARACTERS_OF_STRING: number = nCharacters % inputString.length;

            if (N_REMAINING_CHARACTERS_OF_STRING == 0)
                return 0;

            const SUB_STRING: string = inputString.substring(0, N_REMAINING_CHARACTERS_OF_STRING);
            return findQuantityOfAInString(SUB_STRING);
        }
