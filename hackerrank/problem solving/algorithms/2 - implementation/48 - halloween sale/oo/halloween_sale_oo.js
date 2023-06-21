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
    const OBJ = new HalloweenSale(GAME_DEFAULT_PRICE, DISCOUNT, GAME_MINIMUM_PRICE, BUDGET);
    console.log(OBJ.getGamesCanBeBoughtQuantity());
}

    function readAnArray() {
        return readLine().split(" ").map(Number);
    }

    class HalloweenSale {
        #gameDefaultPrice;
        #discount;
        #gameMinimumPrice;
        #budget;
        #gamesCanBeBoughtQuantity = 0;

        constructor(gameDefaultPrice, discount, gameMinimumPrice, budget) {
            this.#gameDefaultPrice = gameDefaultPrice;
            this.#discount = discount;
            this.#gameMinimumPrice = gameMinimumPrice;
            this.#budget = budget;

            this.#calculateHowManyGamesCanBeBought();
        }

            #calculateHowManyGamesCanBeBought() {
                for (let currentGamePrice = this.#gameDefaultPrice, currentBudget = this.#budget - this.#gameDefaultPrice; currentBudget >= 0;) {
                    this.#gamesCanBeBoughtQuantity++;
                    currentGamePrice -= this.#discount;
                    currentBudget -= currentGamePrice >= this.#gameMinimumPrice ? currentGamePrice : this.#gameMinimumPrice;
                }
            }

        getGamesCanBeBoughtQuantity() {
            return this.#gamesCanBeBoughtQuantity;
        }
    }
