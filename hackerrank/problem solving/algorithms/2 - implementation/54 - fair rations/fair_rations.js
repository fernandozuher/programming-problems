// https://www.hackerrank.com/challenges/fair-rations/problem?isFullScreen=true
// From ES2022

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

        for (let i = 0, n = nLoavesOfEachPerson.length - 1; i < n; ++i) {
            if (isOdd(nLoavesOfEachPerson[i])) {
                ++nLoavesOfEachPerson[i + 1];
                minLoavesToSatisfyRules += 2;
            }
        }

        return isOdd(nLoavesOfEachPerson.at(-1)) ? -1 : minLoavesToSatisfyRules;
    }

        function isOdd(n) {
            return n & 1;
        }
