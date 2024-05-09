// https://www.hackerrank.com/challenges/chocolate-feast/problem?isFullScreen=true

'use strict';

process.stdin.resume();
process.stdin.setEncoding('utf-8');

let inputString: string = '';
let inputLines: string[] = [];
let currentLine: number = 0;

process.stdin.on('data', function (inputStdin: string): void {
    inputString += inputStdin;
});

process.stdin.on('end', function (): void {
    inputLines = inputString.split('\n');
    inputString = '';
    main();
});

function readLine(): string {
    return inputLines[currentLine++];
}

//////////////////////////////////////////////////

function main() {
    let n: number = +readLine();
    let output = Array(n).fill(0).map(_ => {
        const [amountOfMoney, chocolateBarCost, nWrappersToTurnInBar] = readLine().split(' ').map(Number);
        return howManyChocolatesCanBeEaten(amountOfMoney, chocolateBarCost, nWrappersToTurnInBar);
    });

    output.forEach(x => console.log(x));
}

    function howManyChocolatesCanBeEaten(amountOfMoney: number, chocolateBarCost: number, nWrappersToTurnInBar: number): number {
        let eatenChocolates: number = Math.trunc(amountOfMoney / chocolateBarCost);

        for (let availableWrappers = eatenChocolates; availableWrappers >= nWrappersToTurnInBar;) {
            const chocolatesForFree = Math.trunc(availableWrappers / nWrappersToTurnInBar);
            availableWrappers = availableWrappers - (chocolatesForFree * nWrappersToTurnInBar) + chocolatesForFree;
            eatenChocolates += chocolatesForFree;
        }

        return eatenChocolates;
    }
