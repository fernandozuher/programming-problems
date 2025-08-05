// https://www.hackerrank.com/challenges/strange-advertising/problem?isFullScreen=true

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

//////////////////////////////////////////////////

function main() {
  const days: number = +readLine();
  console.log(viralAdvertising(days));
}

function readLine(): string {
  return inputLines[currentLine++];
}

function viralAdvertising(days: number): number {
  let cumulative = 0;

  for (let shared = 5; days > 0; days--) {
    const liked = Math.trunc(shared / 2);
    cumulative += liked;
    shared = liked * 3;
  }

  return cumulative;
}
