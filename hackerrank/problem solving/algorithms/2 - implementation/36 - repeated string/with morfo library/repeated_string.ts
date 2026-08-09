// https://www.hackerrank.com/challenges/repeated-string/problem?isFullScreen=true

import { read } from 'morfo';

const str: string = read(String);
const nChars: number = read(Number);
const letter = 'a';
console.log(countInRepeatedString(str, letter, nChars));

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
