// https://www.hackerrank.com/challenges/fair-rations/problem?isFullScreen=true

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
  readLine();
  const peopleLoafCounts: number[] = readNumbers();
  const minLoaves: number = minLoavesToSatisfyRules(peopleLoafCounts);
  console.log(minLoaves === -1 ? 'NO' : minLoaves);
}

function readNumbers() {
  return readLine().split(' ').map(Number);
}

function minLoavesToSatisfyRules(peopleLoafCounts: number[]) {
  let loavesGiven = 0;
  let counts = peopleLoafCounts[0];

  for (let i = 1; i < peopleLoafCounts.length; i++)
    if (isOdd(counts)) {
      loavesGiven += 2;
      counts = peopleLoafCounts[i] + 1;
    } else counts = peopleLoafCounts[i];

  return isOdd(counts) ? -1 : loavesGiven;
}

function isOdd(n: number): boolean {
  return (n & 1) === 1;
}
