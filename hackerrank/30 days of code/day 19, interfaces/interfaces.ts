// https://www.hackerrank.com/challenges/30-interfaces/problem?isFullScreen=true

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
    let n = +readLine();
    let calc = new Calculator();
    console.log(`I implemented: AdvancedArithmetic \n${calc.divisorSum(n)}`);
}

    interface AdvancedArithmetic {
        divisorSum(n: number): number;
    }

        class Calculator implements AdvancedArithmetic {
            public divisorSum(n: number): number {
                let sum = 0;
                for (let i = 1; i <= n / 2; i++)
                    if (!(n % i))
                        sum += i;
                return sum + n;
            }
        }
