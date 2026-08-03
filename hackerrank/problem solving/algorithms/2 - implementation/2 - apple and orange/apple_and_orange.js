// https://www.hackerrank.com/challenges/apple-and-orange/problem?isFullScreen=true

class House {
  #start;
  #end;

  constructor(start, end) {
    this.#start = start;
    this.#end = end;
  }

  contains(position) {
    return this.#start <= position && position <= this.#end;
  }
}

class FruitTree {
  constructor(treeLocation, fruitDistances) {
    this.treeLocation = treeLocation;
    this.fruitDistances = fruitDistances;
  }
}

function main() {
  const [house, appleTree, orangeTree] = readInput();
  console.log(countFruitsOnHouse(appleTree, house));
  console.log(countFruitsOnHouse(orangeTree, house));
}

function readInput() {
  const house = new House(...readNums());

  const [appleTreeLocation, orangeTreeLocation] = [...readNums()];
  readLine(); // Discard array sizes
  const appleDistances = readNums();
  const orangeDistances = readNums();

  const appleTree = new FruitTree(appleTreeLocation, appleDistances);
  const orangeTree = new FruitTree(orangeTreeLocation, orangeDistances);

  return [house, appleTree, orangeTree];
}

function readNums() {
  return readLine().split(' ').map(Number);
}

// n: length of fruitTree.fruitDistances
// T: O(n)
// S: O(1) extra space
function countFruitsOnHouse(fruitTree, house) {
  return fruitTree.fruitDistances.reduce(
    (count, distance) =>
      count + +house.contains(fruitTree.treeLocation + distance),
    0,
  );
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
