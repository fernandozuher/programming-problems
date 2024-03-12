// https://www.hackerrank.com/challenges/sparse-arrays/problem?isFullScreen=true

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
    let n = +readLine();
    let input = readInput(n);
    n = +readLine();
    let result = readQueriesAndCountMatches(input, n);
    result.forEach(x => console.log(x));
}

    function readInput(n) {
        let input = {};
        while (n-- > 0) {
            let x = readLine();
            input[x] = (input[x]+1) || 1;
        }
        return input;
    }

    function readQueriesAndCountMatches(input, n) {
        let result = Array(n).fill(0);
        for (let i = 0; i < n; ++i) {
            let query = readLine();
            let count = input[query] || 0;
            result[i] = count;
        }
        return result;
    }
