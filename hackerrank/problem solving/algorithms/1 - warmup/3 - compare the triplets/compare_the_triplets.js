// https://www.hackerrank.com/challenges/compare-the-triplets/problem?isFullScreen=true

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
    let array1 = readIntArray();
    let array2 = readIntArray();
    let [player1, player2] = compareTriplets(array1, array2);
    console.log(player1, player2);
}

    function readIntArray() {
        return readLine().split(' ').map(Number);
    }

    function compareTriplets(array1, array2) {
        let [player1, player2] = [0, 0];

        for (let i in array1)
            if (array1[i] > array2[i])
                ++player1;
            else if (array2[i] > array1[i])
                ++player2;

        return [player1, player2];
    }
