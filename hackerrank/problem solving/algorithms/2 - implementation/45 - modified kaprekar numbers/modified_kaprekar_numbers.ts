// https://www.hackerrank.com/challenges/kaprekar-numbers/problem?isFullScreen=true

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

//////////////////////////////////////////////////

function main() {
    let validRange = false;

    for (let lowerLimit = +readLine(), number = lowerLimit, upperLimit = +readLine(); number <= upperLimit; ++number) {
        if (isNumberKaprekar(number)) {
            process.stdout.write(number + ' ');
            validRange = true;
        }
    }

    if (!validRange) console.log("INVALID RANGE");
}

    function isNumberKaprekar(number: number): boolean {
        let squareNumber = Math.pow(number, 2);
        let divisor = Math.pow(10, numberDigits(number));
        let leftNumber = Math.trunc(squareNumber / divisor);
        let rightNumber = squareNumber % divisor;
        return number === leftNumber + rightNumber;
    }

        function numberDigits(n: number): number {
            if (n < 10) return 1;
            if (n < 100) return 2;
            if (n < 1000) return 3;
            if (n < 10000) return 4;
            if (n < 100000) return 5;
            if (n < 1000000) return 6;
            if (n < 10000000) return 7;
            return 8;
        }
