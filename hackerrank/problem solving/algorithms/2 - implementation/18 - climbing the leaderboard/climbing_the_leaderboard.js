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

function climbingLeaderboard(ranked, player) {
  const playerRanks = Array(player.length).fill(0);
  let i = ranked.length - 1;

  for (let j in player) {
    while (i >= 0 && player[j] >= ranked[i]) i--;
    playerRanks[j] = i + 2;
  }

  return playerRanks;
}
