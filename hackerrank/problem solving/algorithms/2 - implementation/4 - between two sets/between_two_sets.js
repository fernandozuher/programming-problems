// Source: https://www.hackerrank.com/challenges/between-two-sets/problem?isFullScreen=true

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
    readIntArray();
    let setA = readIntArray();
    let setB = readIntArray();
    let result = new Result(setA, setB);
    console.log(result.totalFactors());
}

    function readIntArray() {
        return readLine().split(' ').map(Number);
    }

    class Result {
        #setA;
        #setB;
        #potentialFactors;
        #factors;

        constructor(setA, setB) {
            this.#setA = [...setA];
            this.#setB = [...setB];
            this.#potentialFactors = [];
            this.#factors = 0;

            this.#findFactors();
        }
        
            #findFactors() {
                this.#findNumbersDivisibleBySetA();
                this.#findFactorsOfSetB();
                this.#countFactors();
            }

                #findNumbersDivisibleBySetA() {
                    let lastElementOfSetA = this.#setA[this.#setA.length - 1];

                    for (let potentialFactor = lastElementOfSetA; potentialFactor <=this.#setB[0]; potentialFactor += lastElementOfSetA) {
                        let isARealPotentialFactor = true;

                        for (let elementA of this.#setA)
                            if (potentialFactor % elementA) {
                                isARealPotentialFactor = false;
                                break;
                            }

                        if (isARealPotentialFactor)
                            this.#potentialFactors.push(potentialFactor);
                    }
                }

                #findFactorsOfSetB() {
                    for (let elementB of this.#setB)
                        for (let [i, potentialFactor] of this.#potentialFactors.entries())
                            if (potentialFactor && elementB % potentialFactor)
                                this.#potentialFactors[i] = 0;
                }

                #countFactors() {
                    this.#factors = this.#potentialFactors.reduce((sum, item) => item != 0 ? ++sum : sum, 0);
                }
            
            totalFactors() {
                return this.#factors;
            }
    }
