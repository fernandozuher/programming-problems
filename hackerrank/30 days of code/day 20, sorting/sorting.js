// https://www.hackerrank.com/challenges/30-sorting/problem?isFullScreen=true

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
    let _ = +readLine();
    let array = readLine().split(' ').map(Number);

    console.log(`Array is sorted in ${bubbleSort(array)} swaps.`);
    console.log(`First Element: ${array[0]}`);
    console.log(`Last Element: ${array[array.length - 1]}`);
}

    function bubbleSort(a) {
        let numberOfSwaps = 0;

        for (let n = a.length - 1; n; --n) {
            for (let i = 0; i < n; ++i)
                if (a[i] > a[i + 1]) {
                    [a[i], a[i+1]] = [a[i+1], a[i]];
                    ++numberOfSwaps;
                }

            if (!numberOfSwaps)
                break;
        }

        return numberOfSwaps;
    }
