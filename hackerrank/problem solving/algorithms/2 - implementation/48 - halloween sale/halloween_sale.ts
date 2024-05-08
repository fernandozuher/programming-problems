// https://www.hackerrank.com/challenges/halloween-sale/problem?isFullScreen=true

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
    const [gameDefaultPrice, discount, minimumPriceGame, budget]: number[] = readIntArray();
    console.log(howManyGamesCanBeBought(gameDefaultPrice, discount, minimumPriceGame, budget));
}

    function readIntArray(): number[] {
        return readLine().split(' ').map(Number);
    }

    function howManyGamesCanBeBought(defaultPriceGame: number, discount: number, minimumPriceGame: number, budget: number): number {
        let gamesCanBeBoughtQuantity = 0;

        for (let currentPriceGame = defaultPriceGame, currentBudget = budget - defaultPriceGame; currentBudget >= 0;) {
            ++gamesCanBeBoughtQuantity;
            currentPriceGame -= discount;
            currentBudget -= Math.max(currentPriceGame, minimumPriceGame);
        }

        return gamesCanBeBoughtQuantity;
    }
