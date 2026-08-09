// https://www.hackerrank.com/challenges/fair-rations/problem?isFullScreen=true

import { skipInputLn, readLn } from 'morfo';

function main() {
  skipInputLn();
  const peopleLoafCounts = readLn(Number);
  const minLoaves = minLoavesToSatisfyRules(peopleLoafCounts);
  console.log(minLoaves === -1 ? 'NO' : minLoaves);
}

// n: length of peopleLoafCounts
// T: O(n)
// S: O(1) extra space
function minLoavesToSatisfyRules(peopleLoafCounts) {
  let loavesGiven = 0;
  let counts = peopleLoafCounts[0];

  for (let i = 1; i < peopleLoafCounts.length; i++)
    if (isOdd(counts)) {
      loavesGiven += 2;
      counts = peopleLoafCounts[i] + 1;
    } else counts = peopleLoafCounts[i];

  return isOdd(counts) ? -1 : loavesGiven;
}

function isOdd(n) {
  return (n & 1) === 1;
}

main();
