// https://www.hackerrank.com/challenges/apple-and-orange/problem?isFullScreen=true

class House {
  private readonly start: number;
  private readonly end: number;

  constructor(start: number, end: number) {
    this.start = start;
    this.end = end;
  }

  contains(position: number): boolean {
    return this.start <= position && position <= this.end;
  }
}

type FruitTree = {
  treeLocation: number;
  fruitDistances: number[];
};

function main() {
  const [house, appleTree, orangeTree] = readInput();
  console.log(countFruitsOnHouse(appleTree, house));
  console.log(countFruitsOnHouse(orangeTree, house));
}

function readInput(): [House, FruitTree, FruitTree] {
  const [houseStart, houseEnd] = readNumbers();
  const house = new House(houseStart, houseEnd);

  const [appleTreeLocation, orangeTreeLocation] = readNumbers();
  readLine(); // Discard array sizes
  const appleDistances: number[] = readNumbers();
  const orangeDistances: number[] = readNumbers();

  const appleTree: FruitTree = {
    treeLocation: appleTreeLocation,
    fruitDistances: appleDistances,
  };
  const orangeTree: FruitTree = {
    treeLocation: orangeTreeLocation,
    fruitDistances: orangeDistances,
  };

  return [house, appleTree, orangeTree];
}

function readNumbers(): number[] {
  return readLine()
    .split(' ')
    .map((x) => +x);
}

// n: length of fruitTree.fruitDistances
// T: O(n)
// S: O(1) extra space
function countFruitsOnHouse(fruitTree: FruitTree, house: House): number {
  return fruitTree.fruitDistances.reduce(
    (count, distance) =>
      count + +house.contains(fruitTree.treeLocation + distance),
    0,
  );
}

//////////////////////////////////////////////////

import readline = require('readline');

const rl = readline.createInterface({ input: process.stdin });
let inputLines: string[] = [];
rl.on('line', (line: string) => inputLines.push(line));
rl.on('close', main);

function readLine(): string {
  return inputLines.shift()!;
}
