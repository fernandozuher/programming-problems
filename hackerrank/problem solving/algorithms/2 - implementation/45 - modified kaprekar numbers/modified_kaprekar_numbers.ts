// https://www.hackerrank.com/challenges/kaprekar-numbers/problem?isFullScreen=true

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
  let validRange = false;

  for (
    let lower = +readLine(), num = lower, upper = +readLine();
    num <= upper;
    num++
  )
    if (isNumberKaprekar(num)) {
      process.stdout.write(num + ' ');
      validRange = true;
    }

  if (!validRange) console.log('INVALID RANGE');
}

function isNumberKaprekar(n: number): boolean {
  const squareNumber = Math.pow(n, 2);
  const divisor = Math.pow(10, numberDigits(n));
  const leftNumber = Math.trunc(squareNumber / divisor);
  const rightNumber = squareNumber % divisor;
  return n === leftNumber + rightNumber;
}

function numberDigits(n: number): number {
  return n.toString().length;
}
