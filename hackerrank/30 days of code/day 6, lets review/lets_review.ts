// https://www.hackerrank.com/challenges/30-review-loop/problem?isFullScreen=true

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
    let n: number = +readLine();

    for (let i = 0; i < n; i++) {
        let word: string = readLine();
        let word1: string = '', word2: string = '';
        let isWord1Turn: boolean = true;

        [...word].forEach(ch => {
            isWord1Turn ? (word1 += ch) : (word2 += ch);
            isWord1Turn = !isWord1Turn;
        })

        console.log(`${word1} ${word2}`);
    }
}
