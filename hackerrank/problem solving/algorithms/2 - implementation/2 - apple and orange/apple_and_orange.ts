// https://www.hackerrank.com/challenges/apple-and-orange/problem?isFullScreen=true

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
  readLine(); // Discard sizes of arrays
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
  return readLine().split(' ').map(Number);
}

// n: length of array fruitTree.fruitDistances
// T: O(n)
// S: O(1) extra space
function countFruitsOnHouse(fruitTree: FruitTree, house: House): number {
  return fruitTree.fruitDistances.filter((distance) =>
    house.contains(fruitTree.treeLocation + distance),
  ).length;
}
