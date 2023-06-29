// Source: https://www.hackerrank.com/challenges/fair-rations/problem?isFullScreen=true

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
    const _ = readLine();
    const N_LOAVES_OF_EACH_PERSON = readLine().split(" ").map(Number);
    console.log(findMinLoavesToSatisfyRules(N_LOAVES_OF_EACH_PERSON));
}

    function findMinLoavesToSatisfyRules(nLoavesOfEachPerson) {
        let minLoavesToSatisfyRules = 0;

        for (let i = 0, size = nLoavesOfEachPerson.length - 1; i < size; i++)
            if (nLoavesOfEachPerson[i] % 2) {
                nLoavesOfEachPerson[i]++;
                nLoavesOfEachPerson[i + 1]++;
                minLoavesToSatisfyRules += 2;
            }

        return nLoavesOfEachPerson[nLoavesOfEachPerson.length - 1] % 2 ? "NO" : minLoavesToSatisfyRules.toString();
    }
