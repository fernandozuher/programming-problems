// https://www.hackerrank.com/challenges/the-birthday-bar/problem?isFullScreen=true

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
  readLine();
  const chocolateSquares: number[] = readNumbers();
  const dayMonth: number[] = readNumbers();
  console.log(birthday(chocolateSquares, dayMonth));
}

function readNumbers(): number[] {
  return readLine().split(' ').map(Number);
}

function birthday(chocolateSquares: number[], dayMonth: number[]): number {
  const [day, month]: number[] = dayMonth;
  if (month > chocolateSquares.length) return 0;

  let sum: number = chocolateSquares.slice(0, month)
    .reduce((a, b) => a + b, 0);
  let waysBarCanBeDivided: number = Number(sum === day);

  for (let i = month; i < chocolateSquares.length; i++) {
    sum += chocolateSquares[i] - chocolateSquares[i - month];
    if (sum === day) waysBarCanBeDivided++;
  }

  return waysBarCanBeDivided;
}
