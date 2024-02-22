// https://www.hackerrank.com/challenges/sherlock-and-squares/problem?isFullScreen=true

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

//////////////////////////////////////////////////

function main() {
    let n = +readLine();
    let output = new Array(n).fill(0);

    for (let i in output) {
        let [begin, end] = readIntArray();
        let obj = new SherlockAndSquares(begin, end);
        output[i] = obj.squareIntegers();
    }

    output.forEach(x => console.log(x));
}

    function readIntArray() {
        return readLine().split(" ").map(Number);
    }

    class SherlockAndSquares {
        #begin;
        #end;
        #squareIntegers;

        constructor(begin, end) {
            this.#begin = begin;
            this.#end = end;
            this.#squareIntegers = 0;
            this.#calculateQuantityOfSquareIntegersInRange();
        }

            #calculateQuantityOfSquareIntegersInRange() {
                let firstSquareInteger = this.#findFirstSquareInteger();
                for (let number = firstSquareInteger; this.#isPowerOf2LessThanOrEqualToLimit(number); ++number)
                   ++this.#squareIntegers;
            }

                #findFirstSquareInteger() {
                    let squareRoot = Math.sqrt(this.#begin);
                    let integerPart = Math.trunc(squareRoot);
                    return squareRoot === integerPart ? integerPart : integerPart + 1;
                }

                #isPowerOf2LessThanOrEqualToLimit(x) {
                    return Math.pow(x, 2) <= this.#end;
                }

        squareIntegers() {
            return this.#squareIntegers;
        }
    }
