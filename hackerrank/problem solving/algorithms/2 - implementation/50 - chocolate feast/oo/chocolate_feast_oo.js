// Source: https://www.hackerrank.com/challenges/chocolate-feast/problem?isFullScreen=true

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
    const N_TEST_CASES = +readLine();
    const OUTPUT = solveTestCases(N_TEST_CASES);
    OUTPUT.forEach(_  => console.log(_));
}

    function solveTestCases(nTestCases) {
        const OUTPUT = Array(nTestCases).fill(0);

        for (let i = 0; i < nTestCases; i++) {
            const [AMOUNT_OF_MONEY, CHOCOLATE_BAR_COST, N_WRAPPERS_TO_TURN_IN_BAR] = readLine().split(" ").map(Number);
            const OBJ = new ChocolateFeast(AMOUNT_OF_MONEY, CHOCOLATE_BAR_COST, N_WRAPPERS_TO_TURN_IN_BAR);
            OUTPUT[i] = OBJ.getEatenChocolates();
        }

        return OUTPUT;
    }

    class ChocolateFeast {
        #amountOfMoney;
        #chocolateBarCost;
        #nWrappersToTurnInBar;
        #eatenChocolates;

        constructor(amountOfMoney, chocolateBarCost, nWrappersToTurnInBar) {
            this.#amountOfMoney = amountOfMoney;
            this.#chocolateBarCost = chocolateBarCost;
            this.#nWrappersToTurnInBar = nWrappersToTurnInBar;
            this.#eatenChocolates = 0;

            this.#calculateHowManyChocolatesCanBeEaten();
        }

            #calculateHowManyChocolatesCanBeEaten() {
                this.#eatenChocolates = Math.trunc(this.#amountOfMoney / this.#chocolateBarCost);

                for (let availableWrappers = this.#eatenChocolates; availableWrappers >= this.#nWrappersToTurnInBar;) {
                    const CHOCOLATES_FOR_FREE = Math.trunc(availableWrappers / this.#nWrappersToTurnInBar);
                    availableWrappers = availableWrappers - (CHOCOLATES_FOR_FREE * this.#nWrappersToTurnInBar) + CHOCOLATES_FOR_FREE;
                    this.#eatenChocolates += CHOCOLATES_FOR_FREE;
                }
            }

        getEatenChocolates() {
            return this.#eatenChocolates;
        }
    }
