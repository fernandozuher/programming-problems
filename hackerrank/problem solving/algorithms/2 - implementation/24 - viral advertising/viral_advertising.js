// https://www.hackerrank.com/challenges/strange-advertising/problem?isFullScreen=true

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
    let days = +readLine();
    console.log(viralAdvertising(days));
}

    function viralAdvertising(days) {
        let [shared, liked, cumulative] = [5, 0, 0];

        while (days--) {
            liked = Math.trunc(shared / 2);
            cumulative += liked;
            shared = liked * 3;
        }

        return cumulative;
    }
