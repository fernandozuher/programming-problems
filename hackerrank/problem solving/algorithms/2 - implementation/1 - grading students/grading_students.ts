// https://www.hackerrank.com/challenges/grading/problem?isFullScreen=true

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

function readLine(): string {
  return inputLines[currentLine++];
}

//////////////////////////////////////////////////

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

// n: length of array grades
// T: O(n)
// S: O(1) extra space
function gradingStudents(grades: number[]): number[] {
  for (let i = 0, minGrade = 38; i < grades.length; i++) {
    if (grades[i] >= minGrade) {
      const nextMultiple5 = Math.trunc(grades[i] / 5 + 1) * 5;
      if (nextMultiple5 - grades[i] < 3) grades[i] = nextMultiple5;
    }
  }
  return grades;
}
