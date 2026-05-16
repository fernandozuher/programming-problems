// https://www.hackerrank.com/challenges/climbing-the-leaderboard/problem?isFullScreen=true

function main() {
  readLine();
  const ranked = removeDuplicates(readNumbers());
  readLine();
  const player = readNumbers();
  for (const x of climbingLeaderboard(ranked, player)) console.log(x);
}

function readNumbers() {
  return readLine()
    .split(' ')
    .map((x) => +x);
}

// n: length of arr
// k: length of distinct numbers in arr
// k <= n
// T: O(n)
// S: O(k) extra space
function removeDuplicates(numbers) {
  return [...new Set(numbers)];
}

// n1: length of player, output
// n2: length of ranked
// T: O(n1 + n2)
// S: O(n1) extra space
function climbingLeaderboard(ranked, player) {
  let i = ranked.length - 1;
  return player.map((score) => {
    while (i >= 0 && score >= ranked[i]) i--;
    return i + 2;
  });
}

////////////////////////////////////////////////

const readline = require('readline');

const rl = readline.createInterface({ input: process.stdin });
let inputLines = [];
rl.on('line', (line) => inputLines.push(line));
rl.on('close', main);

function readLine() {
  return inputLines.shift();
}
