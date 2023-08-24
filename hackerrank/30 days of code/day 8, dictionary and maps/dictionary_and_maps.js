// https://www.hackerrank.com/challenges/30-dictionaries-and-maps/problem?isFullScreen=true

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
    let phoneBook = {};

    while (n-- > 0) {
        const [NAME, PHONE] = readLine().split(' ');
        phoneBook[NAME] = PHONE;
    }

    for (let name; name = readLine();) {
        if (phoneBook[name])
            console.log(`${name}=${phoneBook[name]}`)
        else
            console.log('Not found');
    }
}
