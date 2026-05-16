// https://www.hackerrank.com/challenges/grading/problem?isFullScreen=true

function main() {
  const n = +readLine();
  const grades = readNumbers(n);
  console.log(gradingStudents(grades).join('\n'));
}

function readNumbers(n) {
  return Array(n)
    .fill(0)
    .map((_) => +readLine());
}

// n: length of grades
// T: O(n)
// S: O(1) extra space
function gradingStudents(grades) {
  for (let i = 0, minGrade = 38; i < grades.length; i++) {
    if (grades[i] < minGrade) continue;
    const nextMultiple5 = Math.trunc(grades[i] / 5 + 1) * 5;
    if (nextMultiple5 - grades[i] < 3) grades[i] = nextMultiple5;
  }
  return grades;
}

//////////////////////////////////////////////////

const readline = require('readline');

const rl = readline.createInterface({ input: process.stdin });
let inputLines = [];
rl.on('line', (line) => inputLines.push(line));
rl.on('close', main);

function readLine() {
  return inputLines.shift();
}
