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

function countInRepeatedString(
  inputString: string,
  letter: string,
  nCharacters: number,
) {
  const fullRepeats: number = Math.trunc(nCharacters / inputString.length);
  const nSubstring: number = nCharacters % inputString.length;
  const substring: string = inputString.substring(0, nSubstring);

  let quantity: number = count(inputString, letter);
  quantity *= fullRepeats;
  return quantity + count(substring, letter);
}

function count(inputString: string, letter: string): number {
  return (inputString.match(new RegExp(letter, 'g')) || []).length;
}
