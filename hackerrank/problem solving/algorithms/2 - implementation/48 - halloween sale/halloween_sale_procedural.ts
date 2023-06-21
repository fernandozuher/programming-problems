// Source: https://www.hackerrank.com/challenges/halloween-sale/problem?isFullScreen=true

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


function main() {
    const [GAME_DEFAULT_PRICE, DISCOUNT, GAME_MINIMUM_PRICE, BUDGET]: Array<number> = readAnArray();
    console.log(howManyGamesCanBeBought(GAME_DEFAULT_PRICE, DISCOUNT, GAME_MINIMUM_PRICE, BUDGET));
}

    function readAnArray(): Array<number> {
        return readLine().split(" ").map(Number);
    }

    function howManyGamesCanBeBought(gameDefaultPrice: number, discount: number, gameMinimumPrice: number, budget: number): number {
        let gamesCanBeBoughtQuantity: number = 0;

        for (let currentGamePrice = gameDefaultPrice, currentBudget = budget - gameDefaultPrice; currentBudget >= 0;) {
            gamesCanBeBoughtQuantity++;
            currentGamePrice -= discount;
            currentBudget -= currentGamePrice >= gameMinimumPrice ? currentGamePrice : gameMinimumPrice;
        }

        return gamesCanBeBoughtQuantity;
    }
