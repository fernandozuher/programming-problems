// https://www.hackerrank.com/challenges/equality-in-a-array/problem?isFullScreen=true

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
    let array = readLine().split(' ').map(Number);
    let frequency = {};
    array.forEach(x => {frequency[x] = (frequency[x] ?? 0) + 1;});
    console.log(equalizeArray(frequency, n));
}

    function equalizeArray(map, n) {
        let maximumQuantityOfEqualElement = Math.max(...Object.values(map));
        let minimumNumberRequiredDeletions = n - maximumQuantityOfEqualElement;
        return minimumNumberRequiredDeletions;
    }
