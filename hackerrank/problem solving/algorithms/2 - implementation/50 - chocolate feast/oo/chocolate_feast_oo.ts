// Source: https://www.hackerrank.com/challenges/chocolate-feast/problem?isFullScreen=true

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
    const N_TEST_CASES: number = +readLine();
    const OUTPUT: Array<number> = solveTestCases(N_TEST_CASES);
    OUTPUT.forEach(_  => console.log(_));
}

    function solveTestCases(nTestCases: number): Array<number> {
        const OUTPUT: Array<number> = Array(nTestCases).fill(0);

        for (let i = 0; i < nTestCases; i++) {
            const [AMOUNT_OF_MONEY, CHOCOLATE_BAR_COST, N_WRAPPERS_TO_TURN_IN_BAR]: Array<number> = readLine().split(" ").map(Number);
            const OBJ: ChocolateFeast = new ChocolateFeast(AMOUNT_OF_MONEY, CHOCOLATE_BAR_COST, N_WRAPPERS_TO_TURN_IN_BAR);
            OUTPUT[i] = OBJ.getEatenChocolates();
        }

        return OUTPUT;
    }

    class ChocolateFeast {
        private amountOfMoney: number;
        private chocolateBarCost: number;
        private nWrappersToTurnInBar: number;
        private eatenChocolates: number;

        constructor(amountOfMoney: number, chocolateBarCost: number, nWrappersToTurnInBar: number) {
            this.amountOfMoney = amountOfMoney;
            this.chocolateBarCost = chocolateBarCost;
            this.nWrappersToTurnInBar = nWrappersToTurnInBar;
            this.eatenChocolates = 0;

            this.calculateHowManyChocolatesCanBeEaten();
        }

            private calculateHowManyChocolatesCanBeEaten() {
                this.eatenChocolates = Math.trunc(this.amountOfMoney / this.chocolateBarCost);

                for (let availableWrappers = this.eatenChocolates; availableWrappers >= this.nWrappersToTurnInBar;) {
                    const CHOCOLATES_FOR_FREE = Math.trunc(availableWrappers / this.nWrappersToTurnInBar);
                    availableWrappers = availableWrappers - (CHOCOLATES_FOR_FREE * this.nWrappersToTurnInBar) + CHOCOLATES_FOR_FREE;
                    this.eatenChocolates += CHOCOLATES_FOR_FREE;
                }
            }

        getEatenChocolates(): number {
            return this.eatenChocolates;
        }
    }
