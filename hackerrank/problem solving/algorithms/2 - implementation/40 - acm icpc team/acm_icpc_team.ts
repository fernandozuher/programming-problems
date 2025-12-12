// https://www.hackerrank.com/challenges/acm-icpc-team/problem?isFullScreen=true

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
  const [attendees, _] = readNumbers();
  const binaries: string[] = readBinaries(attendees);
  for (const x of acmTeam(binaries))
    console.log(x);
}

function readNumbers(): number[] {
  return readLine().split(' ').map(Number);
}

function readBinaries(n: number): string[] {
  return new Array(n).fill(null).map(readLine);
}

function acmTeam(binaries: string[]): number[] {
  let maxSubjects = 0;
  let teamsWithMax = 0;

  for (const [i, a] of binaries.slice(0, -1).entries())
    for (const b of binaries.slice(i + 1)) {
      const knownSubjects = countSubjectsKnownBy2Teams(a, b);

      if (knownSubjects > maxSubjects) {
        maxSubjects = knownSubjects;
        teamsWithMax = 1;
      } else if (knownSubjects === maxSubjects) teamsWithMax++;
    }

  return [maxSubjects, teamsWithMax];
}

function countSubjectsKnownBy2Teams(a: string, b: string): number {
  let count = 0;

  [...a].forEach((ch1, i) => {
    let ch2 = b[i];
    if (ch1 === '1' || ch2 === '1') count++;
  });

  return count;
}
