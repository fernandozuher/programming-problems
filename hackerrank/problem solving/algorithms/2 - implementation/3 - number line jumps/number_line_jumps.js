// https://www.hackerrank.com/challenges/kangaroo/problem?isFullScreen=true

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
    let array = readIntArray();
    console.log(kangaroo(array));
}

    function readIntArray() {
        return readLine().split(' ').map(Number);
    }

    function kangaroo(array) {
        let [x1, v1, x2, v2] = [...array];
        if (v2 >= v1) return 'NO';
        for (; x1 < x2; x1 += v1, x2 += v2);
        return x1 === x2 ? 'YES' : 'NO';
    }
