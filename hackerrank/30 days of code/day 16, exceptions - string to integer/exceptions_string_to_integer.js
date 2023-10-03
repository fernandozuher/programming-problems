// https://www.hackerrank.com/challenges/30-exceptions-string-to-integer/problem?isFullScreen=true

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
    let s = readLine();

    try {
        let error = () => {throw "Bad String"};
        let num = parseInt(s) ? parseInt(s) : error();
        console.log(num);
    } 
    catch (e) {
        console.log(e);
    }
}
