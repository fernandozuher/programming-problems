// https://www.hackerrank.com/challenges/30-binary-search-trees/problem?isFullScreen=true

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
  const root = readTree();
  console.log(getHeight(root));
}

function readTree() {
  let root = null;
  for (let n = +readLine(); n-- > 0;) {
    const data = +readLine();
    root = insertNode(root, data);
  }
  return root;
}

function insertNode(root, data) {
  if (root == null)
    return new Node(data);
  if (data <= root.data)
    root.left = insertNode(root.left, data);
  else
    root.right = insertNode(root.right, data);
  return root;
}

class Node {
  constructor(data) {
    this.data = data;
    this.left = null;
    this.right = null;
  }
}

function getHeight(root) {
  if (root == null)
    return -1;
  const leftHeight = getHeight(root.left);
  const rightHeight = getHeight(root.right);
  return Math.max(leftHeight, rightHeight) + 1;
}
