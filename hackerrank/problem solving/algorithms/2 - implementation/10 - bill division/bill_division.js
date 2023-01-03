// Source: https://www.hackerrank.com/challenges/bon-appetit/problem?isFullScreen=true

'use strict';
const fs = require('fs');
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
    const input1 = readLineAsNumberArray();
    const itemAnnaDidntConsume = input1[1];
    
    const costOfEachMeal = readLineAsNumberArray();
    const brianChargedAnna = readLineAsNumberArray();

    const result = new Result(costOfEachMeal, itemAnnaDidntConsume, brianChargedAnna[0]);
}

    function readLineAsNumberArray() {
        const numbers = readLine().split(" ").map(Number);
        return numbers;
    }

    class Result {
        #costOfEachMeal;
        #itemAnnaDidntConsume;
        #brianChargedAnna;
        #brianOverchargedAnna;

        constructor(costOfEachMeal, itemAnnaDidntConsume, brianChargedAnna) {
            this.#costOfEachMeal = costOfEachMeal;
            this.#itemAnnaDidntConsume = itemAnnaDidntConsume;
            this.#brianChargedAnna = brianChargedAnna;
            this.#brianOverchargedAnna = "";

            this.#bonAppetit();
            this.printResult();
        }

            #bonAppetit() {
                const annaCost = this.#calculateAnnaCost();
                this.#brianOverchargedAnna = this.#checkIfBrianOverchargedAnna(annaCost);
            }

                #calculateAnnaCost() {
                    const sum = this.#costOfEachMeal.reduce((a, b) => a + b, 0);
                    const annaCost = (sum - this.#costOfEachMeal[this.#itemAnnaDidntConsume]) / 2;
                    return annaCost;
                }

                #checkIfBrianOverchargedAnna(annaCost) {
                    if (annaCost === this.#brianChargedAnna)
                        return "Bon Appetit";
                    else {
                        const brianOverchargedAnna = this.#brianChargedAnna - annaCost;
                        return brianOverchargedAnna.toString();
                    }
                }
        
            printResult() {
                console.log(this.#brianOverchargedAnna);
            }
    }
