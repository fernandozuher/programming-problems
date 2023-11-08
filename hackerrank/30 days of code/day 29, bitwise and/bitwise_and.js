// https://www.hackerrank.com/challenges/30-bitwise-and/problem?isFullScreen=true

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
    while (n--) {
        let [count, lim] = readLine().split(' ').map(Number);
        console.log(bitwiseAnd(count, lim));
    }
}

    function bitwiseAnd(n, k) {
        let maximumValueLessThanK = 0;

        for (let i = 1; i <= n; ++i)
            for (let j = i + 1, operation; j <= n; ++j) {
                operation = i & j;

                if (operation < k && operation > maximumValueLessThanK) {
                    if (operation == k - 1) return operation;
                    else maximumValueLessThanK = operation;
                }
            }

        return maximumValueLessThanK;
    }
