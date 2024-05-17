// https://www.hackerrank.com/challenges/fair-rations/problem?isFullScreen=true
// From ES2022

'use strict';

process.stdin.resume();
process.stdin.setEncoding('utf-8');

let inputString: string = '';
let inputLines: string[] = [];
let currentLine: number = 0;

process.stdin.on('data', function(inputStdin: string): void {
    inputString += inputStdin;
});

process.stdin.on('end', function(): void {
    inputLines = inputString.split('\n');
    inputString = '';
    main();
});

function readLine(): string {
    return inputLines[currentLine++];
}

//////////////////////////////////////////////////

function main() {
    +readLine();
    let nLoavesOfEachPerson: number[] = readLine().split(' ').map(Number);
    let minLoaves: number = findMinLoavesToSatisfyRules(nLoavesOfEachPerson);
    if (minLoaves === -1) console.log("NO"); else console.log(minLoaves);
}

    function findMinLoavesToSatisfyRules(nLoavesOfEachPerson: number[]) {
        let minLoavesToSatisfyRules = 0;

        for (let i = 0, n = nLoavesOfEachPerson.length - 1; i < n; ++i) {
            if (isOdd(nLoavesOfEachPerson[i])) {
                ++nLoavesOfEachPerson[i + 1];
                minLoavesToSatisfyRules += 2;
            }
        }

        return isOdd(nLoavesOfEachPerson.at(-1)) ? -1 : minLoavesToSatisfyRules;
    }

        function isOdd(n: number): boolean {
            return (n & 1) === 1;
        }
