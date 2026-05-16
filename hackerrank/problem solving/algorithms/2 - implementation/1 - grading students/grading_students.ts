// https://www.hackerrank.com/challenges/grading/problem?isFullScreen=true

function main() {
  const n: number = +readLine();
  const grades: number[] = readNumbers(n);
  console.log(gradingStudents(grades).join('\n'));
}

function readNumbers(n: number): number[] {
  return Array(n)
    .fill(0)
    .map((_) => +readLine());
}

// n: length of grades
// T: O(n)
// S: O(1) extra space
function gradingStudents(grades: number[]): number[] {
  for (let i = 0, minGrade = 38; i < grades.length; i++) {
    if (grades[i] < minGrade) continue;
    const nextMultiple5 = Math.trunc(grades[i] / 5 + 1) * 5;
    if (nextMultiple5 - grades[i] < 3) grades[i] = nextMultiple5;
  }
  return grades;
}

//////////////////////////////////////////////////

import readline = require('readline');

const rl = readline.createInterface({ input: process.stdin });
let inputLines: string[] = [];
rl.on('line', (line: string) => inputLines.push(line));
rl.on('close', main);

function readLine(): string {
  return inputLines.shift()!;
}
