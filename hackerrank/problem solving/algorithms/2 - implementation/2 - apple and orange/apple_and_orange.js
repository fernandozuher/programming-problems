// https://www.hackerrank.com/challenges/apple-and-orange/problem?isFullScreen=true

'use strict';

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

//////////////////////////////////////////////////

function main() {
  const [house, appleTree, orangeTree] = readInput();
  console.log(countFruitsOnHouse(appleTree, house));
  console.log(countFruitsOnHouse(orangeTree, house));
}

function readInput() {
  let house = new House(...readNumbers());

  let [appleTreeLocation, orangeTreeLocation] = [...readNumbers()];
  readLine(); // Discard sizes of arrays
  let appleDistances = readNumbers();
  let orangeDistances = readNumbers();

  let appleTree = new FruitTree(appleTreeLocation, appleDistances);
  let orangeTree = new FruitTree(orangeTreeLocation, orangeDistances);

  return [house, appleTree, orangeTree];
}

class House {
  constructor(start, end) {
    this.start = start;
    this.end = end;
  }

  contains(position) {
    return this.start <= position && position <= this.end;
  }
}

class FruitTree {
  constructor(treeLocation, fruitDistances) {
    this.treeLocation = treeLocation;
    this.fruitDistances = fruitDistances;
  }
}

function readNumbers() {
  return readLine().split(' ').map(Number);
}

function countFruitsOnHouse(fruitTree, house) {
  return fruitTree.fruitDistances
    .map((distance) => fruitTree.treeLocation + distance)
    .filter((position) => house.contains(position)).length;
}
