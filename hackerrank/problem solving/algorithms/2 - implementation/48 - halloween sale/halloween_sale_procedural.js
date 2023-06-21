// Source: https://www.hackerrank.com/challenges/halloween-sale/problem?isFullScreen=true

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
    const [GAME_DEFAULT_PRICE, DISCOUNT, GAME_MINIMUM_PRICE, BUDGET] = readAnArray();
    console.log(howManyGamesCanBeBought(GAME_DEFAULT_PRICE, DISCOUNT, GAME_MINIMUM_PRICE, BUDGET));
}

    function readAnArray() {
        return readLine().split(" ").map(Number);
    }

    function howManyGamesCanBeBought(gameDefaultPrice, discount, gameMinimumPrice, budget) {
        let gamesCanBeBoughtQuantity = 0;

        for (let currentGamePrice = gameDefaultPrice, currentBudget = budget - gameDefaultPrice; currentBudget >= 0;) {
            gamesCanBeBoughtQuantity++;
            currentGamePrice -= discount;
            currentBudget -= currentGamePrice >= gameMinimumPrice ? currentGamePrice : gameMinimumPrice;
        }

        return gamesCanBeBoughtQuantity;
    }
