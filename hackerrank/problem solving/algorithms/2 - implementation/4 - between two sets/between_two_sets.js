// Source: https://www.hackerrank.com/challenges/between-two-sets/problem?isFullScreen=true

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

class Result {
    
    #setA;
    #setB;
    #potentialFactors;
    #totalFactors;
    
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
            for (const elementB of this.#setB)
                for (const [i, potentialFactor] of this.#potentialFactors.entries())
                    if (potentialFactor && elementB % potentialFactor)
                        this.#potentialFactors[i] = 0;
        }

        #countFactors() {
            this.#totalFactors = this.#potentialFactors.reduce((previousResult, item) => item != 0 ? ++previousResult : previousResult, 0);
        }

    constructor(setA, setB) {
        this.#setA = [...setA];
        this.#setB = [...setB];

        this.#potentialFactors = new Array();
        this.#totalFactors = 0;
        this.#findFactors();
        this.printResult();
    }
    
        printResult() {
            console.log(this.#totalFactors);
        }
}

function readLineAsNumericArray() {
    const numbers = readLine().split(" ").map(Number);
    return numbers;
}

function main() {
    readLineAsNumericArray();
    const setA = readLineAsNumericArray();
    const setB = readLineAsNumericArray();
    const result = new Result(setA, setB);
}