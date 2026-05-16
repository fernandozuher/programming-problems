// https://www.hackerrank.com/challenges/repeated-string/problem?isFullScreen=true

function main() {
  const str: string = readLine();
  const nChars: number = +readLine();
  const letter = 'a';
  console.log(countInRepeatedString(str, letter, nChars));
}

// n: length of str
// T: O(n)
// S: O(1) extra space
function countInRepeatedString(
  str: string,
  letter: string,
  nChars: number,
): number {
  const fullRepeats: number = Math.trunc(nChars / str.length);
  const nSubstr: number = nChars % str.length;

  let count: number = countChar(str, str.length, letter);
  count *= fullRepeats;
  return count + countChar(str, nSubstr, letter);
}

function countChar(str: string, n: number, letter: string): number {
  let count = 0;
  for (let i = 0; i < n; i++) if (str[i] === letter) count++;
  return count;
}

//////////////////////////////////////////////////

import readline = require('readline');

const rl = readline.createInterface({ input: process.stdin });
let inputLines: string[] = [];
rl.on('line', (line: string) => inputLines.push(line));
rl.on('close', main);

function readLine(): string {
  return inputLines.shift()!;
}
