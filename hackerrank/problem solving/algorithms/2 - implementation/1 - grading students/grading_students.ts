// https://www.hackerrank.com/challenges/grading/problem?isFullScreen=true

'use strict';

process.stdin.resume();
process.stdin.setEncoding('utf-8');

let inputString: string = '';
let inputLines: string[] = [];
let currentLine: number = 0;

process.stdin.on('data', function (inputStdin: string): void {
  inputString += inputStdin;
});

process.stdin.on('end', function (): void {
  inputLines = inputString.split('\n');
  inputString = '';
  main();
});

//////////////////////////////////////////////////

function main() {
  const n: number = +readLine();
  const grades: number[] = readNumbers(n);
  const roundedGrades: number[] = gradeStudents(grades);
  console.log(roundedGrades.join('\n'));
}

function readLine(): string {
  return inputLines[currentLine++];
}

function readNumbers(n: number): number[] {
  return Array(n)
    .fill(0)
    .map((_) => +readLine());
}

function gradeStudents(grades: number[]): number[] {
  const minGrade = 38;
  return grades.map((grade) => {
    if (grade < minGrade) return grade;
    const nextMultiple5 = Math.trunc(grade / 5 + 1) * 5;
    return nextMultiple5 - grade < 3 ? nextMultiple5 : grade;
  });
}
