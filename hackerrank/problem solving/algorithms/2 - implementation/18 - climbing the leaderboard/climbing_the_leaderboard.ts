// https://www.hackerrank.com/challenges/climbing-the-leaderboard/problem?isFullScreen=true

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

////////////////////////////////////////////////

function main() {
  readLine();
  const ranked: number[] = removeDuplicates(readNumbers());
  readLine();
  const player: number[] = readNumbers();
  console.log(climbingLeaderboard(ranked, player).join('\n'));
}

function readLine(): string {
  return inputLines[currentLine++];
}

function readNumbers(): number[] {
  return readLine().split(' ').map(Number);
}

function removeDuplicates(numbers: number[]): number[] {
  return [...new Set(numbers)];
}

function climbingLeaderboard(ranked: number[], player: number[]): number[] {
  const playerRanks: number[] = Array(player.length).fill(0);
  let i: number = ranked.length - 1;

  for (let j in player) {
    while (i >= 0 && player[j] >= ranked[i]) i--;
    playerRanks[j] = i + 2;
  }

  return playerRanks;
}
