// https://www.hackerrank.com/challenges/sock-merchant/problem?isFullScreen=true

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
    readLine();
    let array = readIntArray();
    console.log(sockMerchant(array));
}

    function readIntArray() {
        return readLine().split(' ').map(Number);
    }
    
    function sockMerchant(socks) {
        let pairs = 0;
        let socksPairing = {};
        for (let sock of socks) {
            if (socksPairing[sock])
                ++pairs;
            socksPairing[sock] = !socksPairing[sock];
        }
        return pairs;
    }
