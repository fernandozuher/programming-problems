// Source: https://www.hackerrank.com/challenges/strange-advertising/problem?isFullScreen=true

'use strict';

process.stdin.resume();
process.stdin.setEncoding('utf-8');

let inputString = '';
let currentLine = 0;

process.stdin.on('data', function(inputStdin) {
    inputString += inputStdin;
});

process.stdin.on('end', function() {
    inputString = inputString.split('\n');
    main();
});

function readLine() {
    return inputString[currentLine++];
}


function main() {
    const days = +readLine();
    const cumulativeLikes = viralAdvertising(days);
    console.log(cumulativeLikes);
}

    function viralAdvertising(days) {
        let [shared, liked, cumulative] = [5, 0, 0];

        for (let _ = 0; _ < days; _++) {
            liked = Math.trunc(shared / 2);
            cumulative += liked;
            shared = liked * 3;
        }

        return cumulative;
    }
