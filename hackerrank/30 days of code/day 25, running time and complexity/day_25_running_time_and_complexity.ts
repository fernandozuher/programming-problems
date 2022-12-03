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
    let n = +readLine()

    for (let number; n-- && (number = +readLine()); ) {
        if (number == 1) {
            console.log("Not prime")
            continue
        }

        let i = 2, limit = Math.sqrt(number);
        for (; i <= limit; i++)
            if (!(number % i)) {
                console.log("Not prime")
                break
            }

        if (i > limit)
            console.log("Prime")
    }
}