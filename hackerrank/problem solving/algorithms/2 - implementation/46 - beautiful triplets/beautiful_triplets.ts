// https://www.hackerrank.com/challenges/beautiful-triplets/problem?isFullScreen=true

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
  const [, beautifulDifference]: number[] = readNumbers();
  const arr: number[] = readNumbers();
  console.log(findBeautifulTriplets(arr, beautifulDifference));
}

function readNumbers(): number[] {
  return readLine().split(' ').map(Number);
}

function findBeautifulTriplets(
  arr: number[],
  beautifulDifference: number,
): number {
  const values: Set<number> = new Set(arr);
  const doubleBD: number = 2 * beautifulDifference;

  return arr.filter(
    (x: number) =>
      values.has(x + beautifulDifference) &&
      values.has(x + doubleBD),
  ).length;
}
