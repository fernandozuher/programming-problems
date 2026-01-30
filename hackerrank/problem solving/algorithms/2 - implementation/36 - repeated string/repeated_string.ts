// https://www.hackerrank.com/challenges/repeated-string/problem?isFullScreen=true

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
  const inputString: string = readLine();
  const nCharacters: number = +readLine();
  const letter = 'a';
  console.log(countInRepeatedString(inputString, letter, nCharacters));
}

// n: length of inputString
// T: O(n)
// S: O(1) extra space
function countInRepeatedString(
  inputString: string,
  letter: string,
  nCharacters: number,
) {
  const fullRepeats: number = Math.trunc(nCharacters / inputString.length);
  const nSubstring: number = nCharacters % inputString.length;

  let count: number = countChar(inputString, inputString.length, letter);
  count *= fullRepeats;
  return count + count_char(inputString, nSubstring, letter);
}

function countChar(inputString: string, n: number, letter: string): number {
  let count = 0;
  for (let i = 0; i < n; i++) {
    if (inputString[i] === letter) count++;
  }
  return count;
}
