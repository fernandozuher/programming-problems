// https://www.hackerrank.com/challenges/climbing-the-leaderboard/problem?isFullScreen=true

process.stdin.resume();
process.stdin.setEncoding('utf-8');

let inputString = '';
let inputLines = [];
let currentLine = 0;

process.stdin.on('data', function (inputStdin) {
  inputString += inputStdin;
});

process.stdin.on('end', function () {
  inputLines = inputString.split('\n');
  inputString = '';
  main();
});

function readLine() {
  return inputLines[currentLine++];
}

////////////////////////////////////////////////

function main() {
  readLine();
  const ranked = removeDuplicates(readNumbers());
  readLine();
  const player = readNumbers();
  console.log(climbingLeaderboard(ranked, player).join('\n'));
}

function readNumbers() {
  return readLine().split(' ').map(Number);
}

function removeDuplicates(numbers) {
  return [...new Set(numbers)];
}

// n: length of array player and returned output array
// m: length of array ranked
// T: O(n + m)
// S: O(n) extra space
function climbingLeaderboard(ranked, player) {
  let i = ranked.length - 1;
  return player.map((score) => {
    while (i >= 0 && score >= ranked[i]) i--;
    return i + 2;
  });
}
