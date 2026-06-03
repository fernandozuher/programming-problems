// https://www.hackerrank.com/challenges/dynamic-array/problem?isFullScreen=true

function main() {
  const [n, nQueries] = readNumbers();
  const obj = new DynamicArray(n);

  for (let i = 0; i < nQueries; i++) obj.handleQuery(readNumbers());

  obj.answers().forEach((x) => console.log(x));
}

function readNumbers() {
  return readLine()
    .split(' ')
    .map((x) => +x);
}

class DynamicArray {
  #n;
  #arr;
  #answers;
  #lastAnswer;

  constructor(n) {
    this.#n = n;
    this.#arr = new Array(n).fill([]).map(() => []);
    this.#answers = [];
    this.#lastAnswer = 0;
  }

  handleQuery(queries) {
    const [type, x, y] = queries;
    const index = (x ^ this.#lastAnswer) % this.#n;

    if (type === 1) this.#arr[index].push(y);
    else {
      const j = y % this.#arr[index].length;
      this.#lastAnswer = this.#arr[index][j];
      this.#answers.push(this.#lastAnswer);
    }
  }

  answers() {
    return this.#answers;
  }
}

////////////////////////////////////////////////

const readline = require('readline');

const rl = readline.createInterface({ input: process.stdin });
const inputLines = [];
rl.on('line', (line) => inputLines.push(line));
rl.on('close', main);

function readLine() {
  return inputLines.shift();
}
