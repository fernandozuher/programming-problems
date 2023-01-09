// Source: https://www.hackerrank.com/challenges/electronics-shop/problem?isFullScreen=true

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
    const inputLine = readLineAsNumberArray();
    const budget = inputLine[0];
    const keyboardCosts = readLineAsNumberArray();
    const usbDriveCosts = readLineAsNumberArray();

    keyboardCosts.sort((a, b) => a - b);
    usbDriveCosts.sort((a, b) => a - b);

    const result = new Result(keyboardCosts, usbDriveCosts, budget);
}

    function readLineAsNumberArray() {
        const inputLine = readLine().split(" ").map(Number);
        return inputLine;
    }

    class Result {
        #keyboardCosts;
        #usbDriveCosts;
        #budget;
        #canBeSpent;

        constructor(keyboardCosts, usbDriveCosts, budget) {
            this.#keyboardCosts = [...keyboardCosts];
            this.#usbDriveCosts = [...usbDriveCosts];
            this.#budget = budget;
            this.#canBeSpent = 0;

            this.#getMoneySpent();
            this.printResult();
        }

            #getMoneySpent() {
                for (let i = 0; i < this.#keyboardCosts.length; i++) {
                    
                    if (this.#isNextCostEqualToCurrentOne(this.#keyboardCosts, i))
                        continue;

                    for (let j = 0; j < this.#usbDriveCosts.length; j++) {
                        
                        if (this.#isNextCostEqualToCurrentOne(this.#usbDriveCosts, j))
                            continue;

                        const sum = this.#keyboardCosts[i] + this.#usbDriveCosts[j];

                        if (this.#isSumInsideBudget(sum))
                            this.#canBeSpent = this.#updateCost(sum);
                        else
                            break;
                    }
                }

                this.#canBeSpent = this.#canBeSpent ? this.#canBeSpent : -1;
            }

                #isNextCostEqualToCurrentOne(deviceCosts, currentIndex) {
                    return currentIndex < deviceCosts.length - 1 && deviceCosts[currentIndex] === deviceCosts[currentIndex + 1];
                }

                #isSumInsideBudget(sum) {
                    return sum <= this.#budget;
                }

                #updateCost(sum) {
                    return Math.max(sum, this.#canBeSpent);
                }

            printResult() {
                console.log(this.#canBeSpent);
            }
    }
