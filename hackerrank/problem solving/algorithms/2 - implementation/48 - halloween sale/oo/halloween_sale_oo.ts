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
    const OBJ: HalloweenSale = new HalloweenSale(GAME_DEFAULT_PRICE, DISCOUNT, GAME_MINIMUM_PRICE, BUDGET);
    console.log(OBJ.getGamesCanBeBoughtQuantity());
}

    function readAnArray(): Array<number> {
        return readLine().split(" ").map(Number);
    }

    class HalloweenSale {
        private gameDefaultPrice: number;
        private discount: number;
        private gameMinimumPrice: number;
        private budget: number;
        private gamesCanBeBoughtQuantity: number = 0;

        public constructor(gameDefaultPrice: number, discount: number, gameMinimumPrice: number, budget: number) {
            this.gameDefaultPrice = gameDefaultPrice;
            this.discount = discount;
            this.gameMinimumPrice = gameMinimumPrice;
            this.budget = budget;

            this.calculateHowManyGamesCanBeBought();
        }

            private calculateHowManyGamesCanBeBought() {
                for (let currentGamePrice = this.gameDefaultPrice, currentBudget = this.budget - this.gameDefaultPrice; currentBudget >= 0;) {
                    this.gamesCanBeBoughtQuantity++;
                    currentGamePrice -= this.discount;
                    currentBudget -= currentGamePrice >= this.gameMinimumPrice ? currentGamePrice : this.gameMinimumPrice;
                }
            }

        public getGamesCanBeBoughtQuantity(): number {
            return this.gamesCanBeBoughtQuantity;
        }
    }
