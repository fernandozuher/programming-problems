// https://www.hackerrank.com/challenges/apple-and-orange/problem?isFullScreen=true

import { countIf, read } from 'morfo';

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

const [house, appleTree, orangeTree] = readInput();
console.log(countFruitsOnHouse(appleTree, house));
console.log(countFruitsOnHouse(orangeTree, house));

function readInput(): [House, FruitTree, FruitTree] {
  const house = new House(read(Number), read(Number));

  const [appleTreeLocation, orangeTreeLocation]: [number, number] = read(
    Number,
    Number,
  );

  const [nApples, nOranges]: [number, number] = read(Number, Number);
  const appleDistances: number[] = read(nApples, Number);
  const orangeDistances: number[] = read(nOranges, Number);

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

// n: length of fruitTree.fruitDistances
// T: O(n)
// S: O(1) extra space
function countFruitsOnHouse(fruitTree: FruitTree, house: House): number {
  return countIf(fruitTree.fruitDistances, (distance) =>
    house.contains(fruitTree.treeLocation + distance),
  );
}
