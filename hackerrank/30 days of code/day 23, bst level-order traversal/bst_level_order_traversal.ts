// https://www.hackerrank.com/challenges/30-binary-trees/problem?isFullScreen=true

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
  levelOrder(root);
}

type MyNode = {
  data: number;
  left: MyNode | null;
  right: MyNode | null;
};

function readTree(): MyNode | null {
  let root: MyNode | null = null;
  for (let n: number = +readLine(); n-- > 0; ) {
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

function levelOrder(root: MyNode | null) {
  if (!root) return;

  let myQueue: MyNode[] = [];
  myQueue.push(root);
  for (let i = 0; i < myQueue.length; i++) {
    process.stdout.write(myQueue[i].data + ' ');
    if (myQueue[i].left)
      myQueue.push(<MyNode>myQueue[i].left);
    if (myQueue[i].right)
      myQueue.push(<MyNode>myQueue[i].right);
  }
}
