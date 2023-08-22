// https://www.hackerrank.com/challenges/30-review-loop/problem?isFullScreen=true

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

function main() {
    let n = +readLine();

    for (let i = 0; i < n; i++) {
        let word = readLine();
        let word1 = '', word2 = '';
        let isWord1Turn = true;

        [...word].forEach(ch => {
            isWord1Turn ? (word1 += ch) : (word2 += ch);
            isWord1Turn = !isWord1Turn;
        })

        console.log(`${word1} ${word2}`);
    }
}
