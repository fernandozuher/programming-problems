// https://www.hackerrank.com/challenges/30-running-time-and-complexity/problem?isFullScreen=true

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
    for (let n = +readLine(); n--;) {
        let number: number = +readLine();

        if (number == 1) {
            console.log("Not prime");
            continue;
        }

        let i = 2,
            limit = Math.sqrt(number);

        for (; i <= limit; ++i)
            if (!(number % i)) {
                console.log("Not prime");
                break;
            }

        if (i > limit)
            console.log("Prime");
    }
}
