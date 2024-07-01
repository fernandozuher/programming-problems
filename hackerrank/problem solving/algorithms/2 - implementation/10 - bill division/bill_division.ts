// https://www.hackerrank.com/challenges/bon-appetit/problem?isFullScreen=true

'use strict';

process.stdin.resume();
process.stdin.setEncoding('utf-8');

let inputString: string = '';
let inputLines: string[] = [];
let currentLine: number = 0;

process.stdin.on('data', function (inputStdin: string): void {
    inputString += inputStdin;
});

process.stdin.on('end', function (): void {
    inputLines = inputString.split('\n');
    inputString = '';
    main();
});

function readLine(): string {
    return inputLines[currentLine++];
}

//////////////////////////////////////////////////

function main() {
    let [, itemAnnaDidntConsume]: number[] = readIntArray();
    let costOfEachMeal: number[] = readIntArray();
    let brianChargedAnna: number = +readLine();
    let data: Input = {itemAnnaDidntConsume, costOfEachMeal, brianChargedAnna};

    let obj = new BillDivision(data);
    obj.bonAppetit();
    printOutput(obj.brianOverchargedAnna());
}

    interface Input {
        itemAnnaDidntConsume: number;
        costOfEachMeal: number[];
        brianChargedAnna: number;
    }

    function readIntArray(): number[] {
        return readLine().split(' ').map(Number);
    }

    class BillDivision {
        private readonly itemAnnaDidntConsume: number;
        private readonly costOfEachMeal: number[];
        private readonly brianChargedAnna: number;
        private brianOvercharged: number;

        constructor(data: Input) {
            this.itemAnnaDidntConsume = data.itemAnnaDidntConsume;
            this.costOfEachMeal = data.costOfEachMeal;
            this.brianChargedAnna = data.brianChargedAnna;
            this.brianOvercharged = 0;
        }

        bonAppetit() {
            let annaCost: number = this.calculateAnnaCost();
            this.howMuchBrianOverchargedAnna(annaCost);
        }

            private calculateAnnaCost(): number {
                let sum: number = this.costOfEachMeal.reduce((a, b) => a + b, 0);
                return (sum - this.costOfEachMeal[this.itemAnnaDidntConsume]) / 2;
            }

            private howMuchBrianOverchargedAnna(annaCost: number) {
                if (annaCost !== this.brianChargedAnna)
                    this.brianOvercharged = this.brianChargedAnna - annaCost;
            }

        brianOverchargedAnna(): number {
            return this.brianOvercharged;
        }
    }

    function printOutput(charged: number) {
        console.log(charged || "Bon Appetit");
    }
