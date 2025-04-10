// https://www.hackerrank.com/challenges/30-binary-search-trees/problem?isFullScreen=true

'use strict';

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
  const root: MyNode | null = readTree();
  console.log(getHeight(root));
}

type MyNode = {
  data: number;
  left: MyNode | null;
  right: MyNode | null;
};

function readTree(): MyNode | null {
  let root: MyNode | null = null;
  for (let n: number = +readLine(); n-- > 0;) {
    const data: number = +readLine();
    root = insertNode(root, data);
  }
  return root;
}

function insertNode(root: MyNode | null, data: number): MyNode {
  if (root == null)
    return { data, left: null, right: null };
  if (data <= root.data)
    root.left = insertNode(root.left, data);
  else
    root.right = insertNode(root.right, data);
  return root;
}

function getHeight(root: MyNode | null): number {
  if (root == null) return -1;
  const leftHeight = getHeight(root.left);
  const rightHeight = getHeight(root.right);
  return Math.max(leftHeight, rightHeight) + 1;
}
