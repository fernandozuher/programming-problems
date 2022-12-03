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
    let n: number = parseInt(readLine().trim(), 10);

    let max_ones = 0, ones
        
    for (ones = 0; n > 0; n = Math.floor(n/2)) {
        if (n % 2)
            ++ones
        else {
            if (ones > max_ones)
                max_ones = ones
            ones = 0
        }
    }

    console.log(ones > max_ones ? ones : max_ones)
}
