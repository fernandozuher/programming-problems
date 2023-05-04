// Source: https://www.hackerrank.com/challenges/kaprekar-numbers/problem?isFullScreen=true

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
    const LOWER_LIMIT: number = +readLine();
    const UPPER_LIMIT: number = +readLine();

    const OUTPUT: Array<number> = findKaprekarNumbersInRange(LOWER_LIMIT, UPPER_LIMIT);
    printOutput(OUTPUT);
}

    function findKaprekarNumbersInRange(lowerLimit: number, upperLimit: number): Array<number> {
        let kaprekarNumbers = Array();

        for (let number = lowerLimit; number <= upperLimit; number++) {
            const POTENTIAL_KAPREKAR_NUMBER: number = calculatePotentialKaprekarNumber(number)
            if (number == POTENTIAL_KAPREKAR_NUMBER)
                kaprekarNumbers.push(number);
        }

        return kaprekarNumbers;
    }

        function calculatePotentialKaprekarNumber(number: number): number {
            const SQUARE_NUMBER_IN_STRING: string = Math.pow(number, 2).toString();
            const LENGTH_OF_NUMBER_IN_STRING: number = number.toString().length;

            const LEFT_NUMBER_IN_STRING: string = getLeftNumberInString(SQUARE_NUMBER_IN_STRING, LENGTH_OF_NUMBER_IN_STRING);
            const RIGHT_NUMBER_IN_STRING: string = getRightNumberInString(SQUARE_NUMBER_IN_STRING, LENGTH_OF_NUMBER_IN_STRING);

            const POTENTIAL_KAPREKAR_NUMBER: number = sumNumbersInStrings(LEFT_NUMBER_IN_STRING, RIGHT_NUMBER_IN_STRING);

            return POTENTIAL_KAPREKAR_NUMBER;
        }

            function getLeftNumberInString(squareNumberInString: string, lengthOfNumberInString: number): string {
                const DIGITS_TO_SKIP: number = 0;
                const DIGITS_TO_TAKE: number = squareNumberInString.length - lengthOfNumberInString;
                const NUMBER_IN_STRING: string = squareNumberInString.substring(DIGITS_TO_SKIP, DIGITS_TO_TAKE);
                return NUMBER_IN_STRING;
            }

            function getRightNumberInString(squareNumberInString: string, lengthOfNumberInString: number): string {
                const DIGITS_TO_SKIP: number = squareNumberInString.length - lengthOfNumberInString;
                const NUMBER_IN_STRING: string = squareNumberInString.substring(DIGITS_TO_SKIP);
                return NUMBER_IN_STRING;
            }

            function sumNumbersInStrings(leftStringNumber: string, rightStringNumber: string): number {
                if (leftStringNumber.length > 0 && rightStringNumber.length > 0)
                    return parseInt(leftStringNumber) + parseInt(rightStringNumber);
                else if (leftStringNumber.length == 0)
                    return parseInt(rightStringNumber);
                else if (rightStringNumber.length == 0)
                    return parseInt(leftStringNumber);

                return 0;
            }

    function printOutput(array: Array<number>) {
        if (array.length > 0)
            console.log(...array);
        else
            console.log("INVALID RANGE");
    }
