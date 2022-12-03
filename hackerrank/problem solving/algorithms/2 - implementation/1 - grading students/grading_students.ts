'use strict';

import { WriteStream, createWriteStream } from "fs";
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

/*
 * Complete the 'gradingStudents' function below.
 *
 * The function is expected to return an INTEGER_ARRAY.
 * The function accepts INTEGER_ARRAY grades as parameter.
 */

function isZeroRemainder(grade: number): boolean {
    return grade % 5 === 0;
}

function gradingStudents(grades: number[]): number[] {
    const N = grades.length;
    const newGrades: number[] = new Array(N);
    
    for (let i = 0, minGrade = 38; i < N; i++) {
        
        if (grades[i] < minGrade || isZeroRemainder(grades[i]))
            newGrades[i] = grades[i];
        else {
            const quocient = Math.floor(grades[i] / 5);
            const nextMultiple5 = (quocient + 1) * 5;
            const difference = nextMultiple5 - grades[i];
            
            const result = difference < 3 ? nextMultiple5 : grades[i];
            newGrades[i] = result;
        }
    }
    return newGrades;
}

function main() {
    const ws: WriteStream = createWriteStream(process.env['OUTPUT_PATH']);

    const gradesCount: number = parseInt(readLine().trim(), 10);

    let grades: number[] = [];

    for (let i: number = 0; i < gradesCount; i++) {
        const gradesItem: number = parseInt(readLine().trim(), 10);

        grades.push(gradesItem);
    }

    const result: number[] = gradingStudents(grades);

    ws.write(result.join('\n') + '\n');

    ws.end();
}
