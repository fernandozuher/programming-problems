// https://www.hackerrank.com/challenges/apple-and-orange/problem?isFullScreen=true

import { read } from 'morfo';

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

const [house, appleTree, orangeTree] = readInput();
console.log(countFruitsOnHouse(appleTree, house));
console.log(countFruitsOnHouse(orangeTree, house));

function readInput() {
  const house = new House(read(Number), read(Number));

  const appleTreeLocation = read(Number);
  const orangeTreeLocation = read(Number);

  const nApples = read(Number);
  const nOranges = read(Number);
  const appleDistances = read(nApples, Number);
  const orangeDistances = read(nOranges, Number);

  const appleTree = new FruitTree(appleTreeLocation, appleDistances);
  const orangeTree = new FruitTree(orangeTreeLocation, orangeDistances);

  return [house, appleTree, orangeTree];
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
