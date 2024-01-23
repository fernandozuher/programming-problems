// https://www.hackerrank.com/challenges/electronics-shop/problem?isFullScreen=true

'use strict';

process.stdin.resume();
process.stdin.setEncoding('utf-8');

let inputString = '';
let inputLines = [];
let currentLine = 0;

process.stdin.on('data', function(inputStdin) {
    inputString += inputStdin;
});

process.stdin.on('end', function() {
    inputLines = inputString.split('\n');
    inputString = '';
    main();
});

function readLine() {
    return inputLines[currentLine++];
}

////////////////////////////////////////////////

function main() {
    let [budget, nKeyboardCosts, nUsbDriveCosts] = readIntArray();
    let keyboardCosts = readIntArray();
    let usbDriveCosts = readIntArray();

    keyboardCosts.sort((a, b) => a - b);
    usbDriveCosts.sort((a, b) => a - b);

    let obj = new ElectronicsShop(keyboardCosts, usbDriveCosts, budget);
    console.log(obj.moneyThatCanBeSpent());
}

    function readIntArray() {
        return readLine().split(' ').map(Number);
    }

    class ElectronicsShop {
        #keyboardCosts;
        #usbDriveCosts;
        #budget;
        #moneyThatCanBeSpent;

        constructor(keyboardCosts, usbDriveCosts, budget) {
            this.#keyboardCosts = keyboardCosts;
            this.#usbDriveCosts = usbDriveCosts;
            this.#budget = budget;
            this.#moneyThatCanBeSpent = 0;
            this.#calculateMoneySpent();
        }

            #calculateMoneySpent() {
                for (let i = 0; i < this.#keyboardCosts.length; ++i) {

                    if (this.#isNextCostEqualToCurrentOne(this.#keyboardCosts, i))
                        continue;

                    for (let j = 0; j < this.#usbDriveCosts.length; ++j) {

                        if (this.#isNextCostEqualToCurrentOne(this.#usbDriveCosts, j))
                            continue;

                        let sum = this.#keyboardCosts[i] + this.#usbDriveCosts[j];

                        if (this.#isSumAffordableByBudget(sum))
                            this.#moneyThatCanBeSpent = this.#updateCost(sum);
                        else
                            break;
                    }
                }

                this.#moneyThatCanBeSpent = this.#moneyThatCanBeSpent ? this.#moneyThatCanBeSpent : -1;
            }

                #isNextCostEqualToCurrentOne(deviceCosts, i) {
                    return i < deviceCosts.length - 1 && deviceCosts[i] === deviceCosts[i + 1];
                }

                #isSumAffordableByBudget(sum) {
                    return sum <= this.#budget;
                }

                #updateCost(sum) {
                    return Math.max(sum, this.#moneyThatCanBeSpent);
                }

        moneyThatCanBeSpent() {
            return this.#moneyThatCanBeSpent;
        }
    }
