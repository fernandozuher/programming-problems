// https://www.hackerrank.com/challenges/divisible-sum-pairs/problem?isFullScreen=true

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
    let [n, k] = [...readIntArray()];
    let array = readIntArray();

    array.sort((a, b) => a - b);

    let obj = new SubarrayDivision(array, k);
    console.log(obj.nDivisibleSumPairs());
}

    function readIntArray() {
        return readLine().split(' ').map(Number);
    }

    class SubarrayDivision {
        #array;
        #k;
        #nDivisible;

        constructor(array, k) {
            this.#array = array;
            this.#k = k;
            this.#nDivisible = 0;

            this.#divisibleSumPairs();
        }

            #divisibleSumPairs() {
                for (let i = 0, n = this.#array.length - 1; i < n; ++i)
                    for (let j = i + 1; j < this.#array.length; ++j)
                        if (this.#array[i] <= this.#array[j] && !((this.#array[i] + this.#array[j]) % this.#k))
                            ++this.#nDivisible;
            }
        
        nDivisibleSumPairs() {
            return this.#nDivisible;
        }
    }
