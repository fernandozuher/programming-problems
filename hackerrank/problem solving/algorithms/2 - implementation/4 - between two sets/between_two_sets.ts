// https://www.hackerrank.com/challenges/between-two-sets/problem?isFullScreen=true

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
  const a: number[] = readNumbers();
  const b: number[] = readNumbers();
  console.log(betweenTwoSets(a, b));
}

function readNumbers(): number[] {
  return readLine().split(' ').map(Number);
}

function betweenTwoSets(a: number[], b: number[]): number {
  const lcmOfA: number = lcmArray(a);
  const gcdOfB: number = gcdArray(b);

  let count = 0;
  for (let i = lcmOfA; i <= gcdOfB; i += lcmOfA) {
    if (gcdOfB % i === 0) count++;
  }
  return count;
}

function lcmArray(arr: number[]): number {
  return arr.reduce(lcm);
}

function lcm(a: number, b: number): number {
  return (a * b) / gcd(a, b);
}

function gcdArray(arr: number[]): number {
  return arr.reduce(gcd);
}

function gcd(a: number, b: number): number {
  while (b !== 0) {
    const t = b;
    b = a % b;
    a = t;
  }
  return a;
}
