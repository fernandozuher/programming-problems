// https://www.hackerrank.com/challenges/divisible-sum-pairs/problem?isFullScreen=true

'use strict';

process.stdin.resume();
process.stdin.setEncoding('utf-8');

let inputString = '';
let inputLines = [];
let currentLine = 0;

process.stdin.on('data', function (inputStdin) {
    inputString += inputStdin;
});

process.stdin.on('end', function () {
    inputLines = inputString.split('\n');
    inputString = '';
    main();
});

function readLine() {
    return inputLines[currentLine++];
}

//////////////////////////////////////////////////

function main() {
    let [, k] = [...readIntArray()];
    let array = readIntArray();
    array.sort((a, b) => a - b);
    console.log(divisibleSumPairs(array, k));
}

    function readIntArray() {
        return readLine().split(' ').map(Number);
    }
    
    function divisibleSumPairs(array, k) {
        let nDivisibleSumPairs = 0;
    
        for (let i = 0, n = array.length - 1; i < n; ++i)
            for (let j = i + 1; j < array.length; ++j)
                if (array[i] <= array[j] && !((array[i] + array[j]) % k))
                    ++nDivisibleSumPairs;
    
        return nDivisibleSumPairs;
    }
