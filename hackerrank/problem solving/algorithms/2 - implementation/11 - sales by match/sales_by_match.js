// https://www.hackerrank.com/challenges/sock-merchant/problem?isFullScreen=true

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
    let n = +readLine();
    let array = readIntArray();
    let obj = new SalesByMatch(array);
    console.log(obj.pairs());
}

    function readIntArray() {
        return readLine().split(' ').map(Number);
    }

    class SalesByMatch {
        #socks;
        #pairs;

        constructor(socks) {
            this.#socks = socks;
            this.#pairs = 0;
            this.#sockMerchant();
        }

        #sockMerchant() {
            let socksPairing = {};
            for (let sock of this.#socks) {
                if (socksPairing[sock])
                    ++this.#pairs;
                socksPairing[sock] = !socksPairing[sock];
            }
        }

        pairs() {
            return this.#pairs;
        }
    }
