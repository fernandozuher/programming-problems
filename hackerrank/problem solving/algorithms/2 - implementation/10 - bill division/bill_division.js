// https://www.hackerrank.com/challenges/bon-appetit/problem?isFullScreen=true

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
    let [, itemAnnaDidntConsume] = readIntArray();
    let costOfEachMeal = readIntArray();
    let brianChargedAnna = +readLine();
    let input = [itemAnnaDidntConsume, costOfEachMeal, brianChargedAnna];

    let obj = new BillDivision(input);
    obj.bonAppetit();
    printOutput(obj.brianOverchargedAnna());
}

function readIntArray() {
    return readLine().split(' ').map(Number);
}

    class BillDivision {
        #itemAnnaDidntConsume;
        #costOfEachMeal;
        #brianChargedAnna;
        #brianOvercharged;

        constructor(input) {
            [this.#itemAnnaDidntConsume, this.#costOfEachMeal, this.#brianChargedAnna] = input
            this.#brianOvercharged = 0;
        }

        bonAppetit() {
            let annaCost = this.#calculateAnnaCost();
            this.#howMuchBrianOverchargedAnna(annaCost);
        }

            #calculateAnnaCost() {
                let sum = this.#costOfEachMeal.reduce((a, b) => a + b, 0);
                return (sum - this.#costOfEachMeal[this.#itemAnnaDidntConsume]) / 2;
            }

            #howMuchBrianOverchargedAnna(annaCost) {
                if (annaCost !== this.#brianChargedAnna)
                    this.#brianOvercharged = this.#brianChargedAnna - annaCost;
            }

        brianOverchargedAnna() {
            return this.#brianOvercharged;
        }
    }

    function printOutput(charged) {
        console.log(charged || "Bon Appetit");
    }
