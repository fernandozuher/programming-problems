// https://www.hackerrank.com/challenges/30-more-exceptions/problem?isFullScreen=true

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
    for (let calc = new Calculator(), nTests = +readLine(); nTests--;) {
        let [n, p] = readLine().split(' ').map(Number);
        try {
            console.log(calc.power(n, p));
        }
        catch (e) {
            console.log(e);
        }
    }
}

    function Calculator() {
        this.power = (n, p) => {
            if (n < 0 || p < 0)
                throw 'n and p should be non-negative';
            return Math.pow(n, p);
        };
    }
