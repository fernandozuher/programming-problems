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
    let [firstName, lastName, id] = readLine().split(' ');
    let nScores = +readLine();
    let scores = readLine().split(' ').map(Number);

    let student = new Student(firstName, lastName, nScores, scores);
    student.printPerson();
    console.log('Grade: ' + student.calculate());
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
                let sumScores = this.#scores.reduce((a, b) => a + b, 0);
                let n = this.#scores.length;
                let avg = sumScores / n;
            
                if (avg >= 90 && avg <= 100)
                    return 'O';
                else if (avg >= 80 && avg < 90)
                    return 'E';
                else if (avg >= 70 && avg < 80)
                    return 'A';
                else if (avg >= 55 && avg < 70)
                    return 'P';
                else if (avg >= 40 && avg < 55)
                    return 'D';
                else
                    return 'T';
            }
        }
