// https://www.hackerrank.com/challenges/dynamic-array/problem?isFullScreen=true

function main() {
  const [n, nQueries]: number[] = readNumbers();
  const obj = new DynamicArray(n);

  for (let i = 0; i < nQueries; i++) obj.handleQuery(readNumbers());

  obj.answers().forEach((x) => console.log(x));
}

function readNumbers(): number[] {
  return readLine()
    .split(' ')
    .map((x) => +x);
}

class DynamicArray {
  private readonly n: number;
  private readonly arr: number[][];
  private readonly answersToQueries: number[];
  private lastAnswer: number;

  constructor(n: number) {
    this.n = n;
    this.arr = new Array(n).fill([]).map(() => []);
    this.answersToQueries = [];
    this.lastAnswer = 0;
  }

  public handleQuery(queries: number[]) {
    const [type, x, y]: number[] = queries;
    const index: number = (x ^ this.lastAnswer) % this.n;

    if (type === 1) this.arr[index].push(y);
    else {
      const j: number = y % this.arr[index].length;
      this.lastAnswer = this.arr[index][j];
      this.answersToQueries.push(this.lastAnswer);
    }
  }

  public answers(): number[] {
    return this.answersToQueries;
  }
}

//////////////////////////////////////////////////

import readline = require('readline');

const rl = readline.createInterface({ input: process.stdin });
const inputLines: string[] = [];
rl.on('line', (line: string) => inputLines.push(line));
rl.on('close', main);

function readLine(): string {
  return inputLines.shift()!;
}
