// https://www.hackerrank.com/challenges/bon-appetit/problem?isFullScreen=true

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

function main() {
    let [n, itemAnnaDidntConsume] = readIntArray();    
    let costOfEachMeal = readIntArray();
    let brianChargedAnna = +readLine();

    let obj = new BillDivision(costOfEachMeal, itemAnnaDidntConsume, brianChargedAnna);
    printOutput(obj.brianOvercharged());
}

    function readIntArray() {
        return readLine().split(' ').map(Number);
    }

    class BillDivision {
        #costOfEachMeal;
        #itemAnnaDidntConsume;
        #brianChargedAnna;
        #brianOverchargedAnna;

        constructor(costOfEachMeal, itemAnnaDidntConsume, brianChargedAnna) {
            this.#costOfEachMeal = costOfEachMeal;
            this.#itemAnnaDidntConsume = itemAnnaDidntConsume;
            this.#brianChargedAnna = brianChargedAnna;
            this.#brianOverchargedAnna = 0;

            this.#bonAppetit();
        }

            #bonAppetit() {
                let annaCost = this.#calculateAnnaCost();
                this.#calculateHowMuchBrianOverchargedAnna(annaCost);
            }

                #calculateAnnaCost() {
                    let sum = this.#costOfEachMeal.reduce((a, b) => a + b, 0);
                    let annaCost = (sum - this.#costOfEachMeal[this.#itemAnnaDidntConsume]) / 2;
                    return annaCost;
                }

                #calculateHowMuchBrianOverchargedAnna(annaCost) {
                    if (annaCost !== this.#brianChargedAnna)
                        this.#brianOverchargedAnna = this.#brianChargedAnna - annaCost;
                }
        
            brianOvercharged() {
                return this.#brianOverchargedAnna;
            }
    }

    function printOutput(charged) {
        console.log(charged || "Bon Appetit");
    }
