// https://www.hackerrank.com/challenges/crush/problem?isFullScreen=true

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
    let [n, nQueries] = readIntArray();
    console.log(arrayManipulation(n, nQueries));
}

    function readIntArray() {
        return readLine().split(' ').map(Number);
    }

    function arrayManipulation(n, nQueries) {
        // n + 2 = 1-indexed array + range-end
        let array = new Array(n + 2).fill(0);

        while (nQueries--) {
            let [b, e, summand] = readIntArray();
            array[b] += summand;
            array[e + 1] -= summand;
        }

        let sum = 0, max = 0;
        for (const x of array) {
            if (x == 0)
                continue;
            sum += x;
            max = Math.max(max, sum);
        }

        return max;
    }
