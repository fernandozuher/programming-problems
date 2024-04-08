// https://www.hackerrank.com/challenges/repeated-string/problem?isFullScreen=true

'use strict';

process.stdin.resume();
process.stdin.setEncoding('utf-8');

let inputString = '';
let inputLines = [];
let currentLine = 0;

process.stdin.on('data', function(inputStdin) {
    inputString += inputStdin;
});

process.stdin.on('end', function() {
    inputLines = inputString.split('\n');
    inputString = '';
    main();
});

function readLine() {
    return inputLines[currentLine++];
}

//////////////////////////////////////////////////

function main() {
    let inputString = readLine();
    let nCharacters = +readLine();
    const letter = 'a';
    console.log(countInRepeatedString(inputString, letter, nCharacters));
}

    function countInRepeatedString(inputString, letter, nCharacters) {
        let repeatedEntireString = Math.trunc(nCharacters / inputString.length);
        let nSubstring = nCharacters % inputString.length;
        let substring = inputString.substring(0, nSubstring);

        let quantity = count(inputString, letter);
        quantity *= repeatedEntireString;
        quantity += count(substring, letter);

        return quantity;
    }

        function count(inputString, letter) {
            return (inputString.match(new RegExp(letter, 'g')) || []).length;
        }
