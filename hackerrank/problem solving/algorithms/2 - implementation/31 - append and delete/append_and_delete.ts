// https://www.hackerrank.com/challenges/append-and-delete/problem?isFullScreen=true

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
  const initialString: string = readLine();
  const finalString: string = readLine();
  const nOperations: number = +readLine();
  console.log(
    appendAndDelete(initialString, finalString, nOperations) ? 'Yes' : 'No',
  );
}

function appendAndDelete(s1: string, s2: string, nOps: number): boolean {
  const prefixLen: number = commonPrefixLength(s1, s2);
  const totalOpsNeeded: number =
    s1.length - prefixLen + (s2.length - prefixLen);
  const canRemoveAll: boolean = nOps >= s1.length + s2.length;
  return (
    canRemoveAll ||
    (nOps >= totalOpsNeeded && (nOps - totalOpsNeeded) % 2 === 0)
  );
}

function commonPrefixLength(s1: string, s2: string): number {
  const minLen: number = Math.min(s1.length, s2.length);
  for (let i = 0; i < minLen; i++)
    if (s1[i] !== s2[i]) return i;
  return minLen;
}
