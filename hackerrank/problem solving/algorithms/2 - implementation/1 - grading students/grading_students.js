// https://www.hackerrank.com/challenges/grading/problem?isFullScreen=true

process.stdin.resume();
process.stdin.setEncoding('utf-8');

let inputString = '';
let inputLines = [];
let currentLine = 0;

process.stdin.on('data', function (inputStdin) {
  inputString += inputStdin;
});

process.stdin.on('end', function () {
  inputLines = inputString.split('\n');
  inputString = '';
  main();
});

function readLine() {
  return inputLines[currentLine++];
}

//////////////////////////////////////////////////

function main() {
  const n = +readLine();
  const grades = readNumbers(n);
  const roundedGrades = gradingStudents(grades);
  console.log(roundedGrades.join('\n'));
}

function readNumbers(n) {
  return Array(n)
    .fill(0)
    .map((_) => +readLine());
}

// n: length of array grades
// T: O(n)
// S: O(1) extra space
function gradingStudents(grades) {
  for (let i = 0, minGrade = 38; i < grades.length; i++) {
    if (grades[i] >= minGrade) {
      const nextMultiple5 = Math.trunc(grades[i] / 5 + 1) * 5;
      if (nextMultiple5 - grades[i] < 3) grades[i] = nextMultiple5;
    }
  }
  return grades;
}
