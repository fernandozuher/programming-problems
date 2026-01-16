// https://www.hackerrank.com/challenges/angry-professor/problem?isFullScreen=true

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
  const n = +readLine();
  for (let i = 0; i < n; i++) {
    const threshold: number = readNumbers()[1];
    const arrivalTimes: number[] = readNumbers();
    console.log(angryProfessor(arrivalTimes, threshold) ? 'YES' : 'NO');
  }
}

function readNumbers(): number[] {
  return readLine().split(' ').map(Number);
}

// k: length of array arrivalTimes
// T: O(k)
// S: O(1) extra space
function angryProfessor(arrivalTimes: number[], threshold: number): boolean {
  const onTime: number = arrivalTimes.reduce(
    (count, t) => (t <= 0 ? count + 1 : count),
    0,
  );
  return onTime < threshold;
}
