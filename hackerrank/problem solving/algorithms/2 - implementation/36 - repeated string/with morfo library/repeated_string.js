// https://www.hackerrank.com/challenges/repeated-string/problem?isFullScreen=true

import { count, idiv, read } from 'morfo';

const str = read(String);
const nChars = read(Number);
const letter = 'a';
console.log(countInRepeatedString(str, letter, nChars));

// n: length of str
// T: O(n)
// S: O(1) extra space
function countInRepeatedString(str, letter, nChars) {
  const fullRepeats = idiv(nChars, str.length);
  const nSubstr = nChars % str.length;
  return (
    count(str, letter) * fullRepeats + count(str.slice(0, nSubstr), letter)
  );
}
