// https://www.hackerrank.com/challenges/between-two-sets/problem?isFullScreen=true

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
    readIntArray();
    let setA = readIntArray();
    let setB = readIntArray();
    let obj = new BetweenTwoSets(setA, setB);
    obj.findFactors();
    console.log(obj.totalFactors());
}

    function readIntArray() {
        return readLine().split(' ').map(Number);
    }

    class BetweenTwoSets {
        #setA;
        #setB;
        #potentialFactors;
        #factors;

        constructor(setA, setB) {
            this.#setA = setA;
            this.#setB = setB;
            this.#potentialFactors = [];
            this.#factors = 0;
        }

        findFactors() {
            this.#findNumbersDivisibleBySetA();
            this.#findFactorsOfSetB();
            this.#countFactors();
        }

            #findNumbersDivisibleBySetA() {
                for (let potentialFactor = this.#setA.at(-1); potentialFactor <= this.#setB[0]; potentialFactor += this.#setA.at(-1)) {
                    let isARealPotentialFactor = true;

                    for (let elementA of this.#setA) if (potentialFactor % elementA) {
                        isARealPotentialFactor = false;
                        break;
                    }

                    if (isARealPotentialFactor) this.#potentialFactors.push(potentialFactor);
                }
            }

            #findFactorsOfSetB() {
                for (let x of this.#setB)
                    for (let [i, potentialFactor] of this.#potentialFactors.entries())
                        if (potentialFactor && x % potentialFactor)
                            this.#potentialFactors[i] = 0;
            }

            #countFactors() {
                this.#factors = this.#potentialFactors.filter(x => x).length;
            }

        totalFactors() {
            return this.#factors;
        }
    }
