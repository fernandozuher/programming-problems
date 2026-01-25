// https://www.hackerrank.com/challenges/extra-long-factorials/problem?isFullScreen=true

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
  console.log(factorial(n).toString());
}

// T: O(n)
// S: O(1) extra space (excluding the size of the resulting integer)
function factorial(n: number): BigInt {
  let res = BigInt(1);
  for (let i = BigInt(1); i <= n; i++) res *= i;
  return res;
}
