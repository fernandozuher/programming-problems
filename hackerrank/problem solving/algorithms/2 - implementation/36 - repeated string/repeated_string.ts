// https://www.hackerrank.com/challenges/repeated-string/problem?isFullScreen=true

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
    let inputString: string = readLine();
    let nCharacters: number = +readLine();
    const letter = 'a';
    console.log(countInRepeatedString(inputString, letter, nCharacters));
}

    function countInRepeatedString(inputString: string, letter: string, nCharacters: number) {
        let repeatedEntireString: number = Math.trunc(nCharacters / inputString.length);
        let nSubstring: number = nCharacters % inputString.length;
        let substring: string = inputString.substring(0, nSubstring);

        let quantity: number = count(inputString, letter);
        quantity *= repeatedEntireString;
        quantity += count(substring, letter);

        return quantity;
    }

        function count(inputString: string, letter: string): number {
            return (inputString.match(new RegExp(letter, 'g')) || []).length;
        }
