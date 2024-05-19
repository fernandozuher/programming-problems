// https://www.hackerrank.com/challenges/fair-rations/problem?isFullScreen=true

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
    +readLine();
    let nLoavesOfEachPerson = readLine().split(' ').map(Number);
    let minLoaves = findMinLoavesToSatisfyRules(nLoavesOfEachPerson);
    if (minLoaves === -1) console.log("NO"); else console.log(minLoaves);
}

    function findMinLoavesToSatisfyRules(nLoavesOfEachPerson) {
        let minLoavesToSatisfyRules = 0;
        let loaves = nLoavesOfEachPerson[0];

        for (let x of nLoavesOfEachPerson.slice(1)) {
            if (isOdd(loaves)) {
                loaves = x + 1;
                minLoavesToSatisfyRules += 2;
            }
            else
                loaves = x;
        }

        return isOdd(loaves) ? -1 : minLoavesToSatisfyRules;
    }

        function isOdd(n) {
            return n & 1;
        }
