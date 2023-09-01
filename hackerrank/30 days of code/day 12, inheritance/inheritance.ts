// https://www.hackerrank.com/challenges/30-inheritance/problem?isFullScreen=true

'use strict';

process.stdin.resume();
process.stdin.setEncoding('utf-8');

let inputString: string = '';
let inputLines: string[] = [];
let currentLine: number = 0;

process.stdin.on('data', function(inputStdin: string): void {
    inputString += inputStdin;
});

process.stdin.on('end', function(): void {
    inputLines = inputString.split('\n');
    inputString = '';
    main();
});

function readLine(): string {
    return inputLines[currentLine++];
}

function main() {
    let [firstName, lastName, id]: any[] = readLine().split(' ');
    let nScores: number = +readLine();
    let scores: number[] = readLine().split(' ').map(Number);

    let student = new Student(firstName, lastName, id, scores);
    student.printPerson();
    console.log('Grade: ' + student.calculate());
}

    class Person {
        protected firstName: string;
        protected lastName: string;
        protected id: number; 

        constructor(firstName: string, lastName: string, id: number) {
            this.firstName = firstName;
            this.lastName = lastName;
            this.id = id;
        }

        public printPerson() {
            console.log('Name: ' + this.lastName + ', ' + this.firstName + '\nID: ' + this.id);
        }
    }

        class Student extends Person {
            private scores: number[];

            constructor(firstName: string, lastName: string, id: number, scores: number[]) {
                super(firstName, lastName, id);
                this.scores = scores;
            }

            public calculate() {
                let sumScores: number = this.scores.reduce((a, b) => a + b, 0);
                let n: number = this.scores.length;
                let avg: number = sumScores / n;
            
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
