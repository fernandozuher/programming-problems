// https://www.hackerrank.com/challenges/30-class-vs-instance/problem?isFullScreen=true

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
    for (let nTests = parseInt(readLine()); nTests-- > 0;) {
        let age = parseInt(readLine());
        let p = new Person(age);
        p.amIOld();

        for (let i = 3; i--; p.yearPasses());
        p.amIOld();

        console.log('');
    }
}

    class Person {
        #age;

        constructor(initialAge) {
            if (initialAge < 0) {
                this.#age = 0;
                console.log('Age is not valid, setting age to 0.');
            } else
                this.#age = initialAge;
        }

        amIOld() {
            if (this.#age < 13)
                console.log('You are young.');
            else if (this.#age >= 13 && this.#age < 18)
                console.log('You are a teenager.');
            else
                console.log('You are old.');
        }

        yearPasses() {
            ++this.#age;
        }
    }
