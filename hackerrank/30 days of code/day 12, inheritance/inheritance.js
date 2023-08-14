// https://www.hackerrank.com/challenges/30-inheritance/problem?isFullScreen=true

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
    const [FIRST_NAME, LAST_NAME, ID] = readLine().split(' ');
    const N_SCORES = +readLine();
    const SCORES = readLine().split(' ').map(Number);

    const STUDENT = new Student(FIRST_NAME, LAST_NAME, N_SCORES, SCORES);
    STUDENT.printPerson();
    console.log('Grade: ' + STUDENT.calculate());
}

    class Person {
        constructor(firstName, lastName, id) {
            this.firstName = firstName;
            this.lastName = lastName;
            this.id = id;
        }

        printPerson() {
            console.log('Name: ' + this.lastName + ', ' + this.firstName + '\nID: ' + this.id)
        }
    }

        class Student extends Person {
            #scores;

            constructor(firstName, lastName, id, scores) {
                super(firstName, lastName, id);
                this.#scores = scores;
            }

            calculate() {
                const SUM_SCORES = this.#scores.reduce((a, b) => a + b, 0);
                const N = this.#scores.length;
                const AVG = SUM_SCORES / N;
            
                if (AVG >= 90 && AVG <= 100)
                    return 'O';
                else if (AVG >= 80 && AVG < 90)
                    return 'E';
                else if (AVG >= 70 && AVG < 80)
                    return 'A';
                else if (AVG >= 55 && AVG < 70)
                    return 'P';
                else if (AVG >= 40 && AVG < 55)
                    return 'D';
                else
                    return 'T';
            }
        }
