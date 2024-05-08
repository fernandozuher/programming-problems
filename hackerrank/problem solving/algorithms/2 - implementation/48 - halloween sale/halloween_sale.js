// https://www.hackerrank.com/challenges/halloween-sale/problem?isFullScreen=true

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
    const [gameDefaultPrice, discount, minimumPriceGame, budget] = readIntArray();
    console.log(howManyGamesCanBeBought(gameDefaultPrice, discount, minimumPriceGame, budget));
}

    function readIntArray() {
        return readLine().split(' ').map(Number);
    }

    function howManyGamesCanBeBought(defaultPriceGame, discount, minimumPriceGame, budget) {
        let gamesCanBeBoughtQuantity = 0;

        for (let currentPriceGame = defaultPriceGame, currentBudget = budget - defaultPriceGame; currentBudget >= 0;) {
            ++gamesCanBeBoughtQuantity;
            currentPriceGame -= discount;
            currentBudget -= Math.max(currentPriceGame, minimumPriceGame);
        }

        return gamesCanBeBoughtQuantity;
    }
