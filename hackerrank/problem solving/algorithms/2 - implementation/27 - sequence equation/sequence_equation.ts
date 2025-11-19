// https://www.hackerrank.com/challenges/permutation-equation/problem?isFullScreen=true

process.stdin.resume();
process.stdin.setEncoding('utf-8');

let inputString: string = '';
let inputLines: string[] = [];
let currentLine: number = 0;

process.stdin.on('data', function(inputStdin: string): void {
    inputString += inputStdin;
});

process.stdin.on('end', function(): void {
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
  const arr: number[] = readNumbers();
  for (const x of sequenceEquation(arr)) {
    console.log(x);
  }
}

function readNumbers(): number[] {
  return readLine().split(' ').map(Number);
}

function sequenceEquation(arr: number[]): number[] {
  const valuesToIndex: number[] = Array(arr.length).fill(0);
  let i = 0;
  for (const val of arr) {
    valuesToIndex[val - 1] = i++;
  }

  const res: number[] = Array(arr.length).fill(0);
  i = 0;
  for (const val of valuesToIndex) {
    res[i++] = valuesToIndex[val] + 1;
  }

  return res;
}
