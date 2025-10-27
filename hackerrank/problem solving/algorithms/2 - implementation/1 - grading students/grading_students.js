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

//////////////////////////////////////////////////

function main() {
  const n = +readLine();
  const grades = readNumbers(n);
  const roundedGrades = gradeStudents(grades);
  console.log(roundedGrades.join('\n'));
}

function readLine() {
  return inputLines[currentLine++];
}

function readNumbers(n) {
  return Array(n)
    .fill(0)
    .map((_) => +readLine());
}

function gradeStudents(grades) {
  const minGrade = 38;
  return grades.map((grade) => {
    if (grade < minGrade) return grade;
    const nextMultiple5 = Math.trunc(grade / 5 + 1) * 5;
    return nextMultiple5 - grade < 3 ? nextMultiple5 : grade;
  });
}
