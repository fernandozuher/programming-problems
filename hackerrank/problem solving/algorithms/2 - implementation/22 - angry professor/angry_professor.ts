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

//////////////////////////////////////////////////

function main() {
  const n = +readLine();

  Array(n)
    .fill('')
    .map((_) => {
      const threshold: number = readNumbers()[1];
      const arrivalTimes: number[] = readNumbers();
      return angryProfessor(arrivalTimes, threshold);
    })
    .forEach((cancelled) => console.log(cancelled ? 'YES' : 'NO'));
}

function readLine(): string {
  return inputLines[currentLine++];
}

function readNumbers(): number[] {
  return readLine().split(' ').map(Number);
}

function angryProfessor(arrivalTimes: number[], threshold: number): boolean {
  const count: number = arrivalTimes.filter((t) => t <= 0).length;
  return count < threshold;
}
