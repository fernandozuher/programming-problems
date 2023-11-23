// https://www.hackerrank.com/challenges/grading/problem?isFullScreen=true

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
    let n: number = +readLine();
    let array: number[] = readIntArray(n);
    printArray(gradingStudents(array));
}

    function readIntArray(n: number): number[] {
        return Array(n).fill(0).map(_ => +readLine());
    }

    function gradingStudents(grades: number[]): number[] {
        let newGrades: number[] = Array(grades.length).fill(0);

        for (let i = 0, minGrade = 38; i < grades.length; ++i) {

            if (grades[i] < minGrade || isZeroRemainder(grades[i])) newGrades[i] = grades[i];
            else {
                let quocient: number = Math.floor((grades[i] / 5));
                let nextMultiple5: number = (quocient + 1) * 5;
                let difference: number = nextMultiple5 - grades[i];
                let result: number = difference < 3 ? nextMultiple5 : grades[i];
                newGrades[i] = result;
            }
        }

        return newGrades;
    }

        function isZeroRemainder(grade: number): boolean {
            return grade % 5 === 0;
        }

    function printArray(array: number[]) {
        array.forEach(x => console.log(x));
    }
