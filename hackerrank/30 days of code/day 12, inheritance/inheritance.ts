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
    const [FIRST_NAME, LAST_NAME, ID]: any[] = readLine().split(' ');
    const N_SCORES: number = +readLine();
    const SCORES: number[] = readLine().split(' ').map(Number);

    const STUDENT = new Student(FIRST_NAME, LAST_NAME, ID, SCORES);
    STUDENT.printPerson();
    console.log('Grade: ' + STUDENT.calculate());
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
                const SUM_SCORES: number = this.scores.reduce((a, b) => a + b, 0);
                const N: number = this.scores.length;
                const AVG: number = SUM_SCORES / N;
            
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
