// Source: https://www.hackerrank.com/challenges/sock-merchant/problem?isFullScreen=true

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
    readLineAsNumberArray();
    const socks = readLineAsNumberArray();

    const result = new Result(socks);
}

    function readLineAsNumberArray() {
        const numbers = readLine().split(" ").map(Number);
        return numbers;
    }

    class Result {
        #socks;
        #pairs;

        constructor(socks) {
            this.#socks = [...socks];
            this.#pairs = 0;

            this.#sockMerchant();
            this.printResult();
        }

            #sockMerchant() {
                let socksPairing = {};

                for (let sock of this.#socks) {
                    if (socksPairing[sock])
                        this.#pairs++;
                    socksPairing[sock] = !socksPairing[sock];
                }
            }
        
            printResult() {
                console.log(this.#pairs);
            }
    }
