// https://www.hackerrank.com/challenges/bon-appetit/problem?isFullScreen=true

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
    let [n, itemAnnaDidntConsume]: number[] = [...readIntArray()];
    let costOfEachMeal: number[] = readIntArray();
    let brianChargedAnna: number = +readLine();

    let obj = new BillDIvision(costOfEachMeal, itemAnnaDidntConsume, brianChargedAnna);
    printOutput(obj.brianOvercharged())
}

    function readIntArray(): number[] {
        return readLine().split(' ').map(Number);
    }

    class BillDIvision {
        private costOfEachMeal: number[];
        private itemAnnaDidntConsume: number;
        private brianChargedAnna: number;
        private brianOverchargedAnna: number;

        constructor(costOfEachMeal: number[], itemAnnaDidntConsume: number, brianChargedAnna: number) {
            this.costOfEachMeal = costOfEachMeal;
            this.itemAnnaDidntConsume = itemAnnaDidntConsume;
            this.brianChargedAnna = brianChargedAnna;
            this.brianOverchargedAnna = 0;

            this.bonAppetit();
        }

            private bonAppetit() {
                let annaCost: number = this.calculateAnnaCost();
                this.calculateHowMuchBrianChargedAnna(annaCost);
            }

                private calculateAnnaCost(): number {
                    let sum: number = this.costOfEachMeal.reduce((a, b) => a + b, 0);
                    let annaCost: number = (sum - this.costOfEachMeal[this.itemAnnaDidntConsume]) / 2;
                    return annaCost;
                }

                private calculateHowMuchBrianChargedAnna(annaCost: number) {
                    if (annaCost !== this.brianChargedAnna)
                        this.brianOverchargedAnna = this.brianChargedAnna - annaCost;
                }

            public brianOvercharged(): number {
                return this.brianOverchargedAnna;
            }
    }

    function printOutput(charged: number) {
        console.log(charged || "Bon Appetit");
    }
