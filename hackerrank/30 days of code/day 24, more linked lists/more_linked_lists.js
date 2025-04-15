// https://www.hackerrank.com/challenges/30-linked-list-deletion/problem?isFullScreen=true

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
  const head = readList();
  removeConsecutiveDuplicates(head);
  display(head);
}

function readList() {
  let n = +readLine();
  let head = null;
  let tail = null;

  while (n--) {
    let newNode = new MyNode(+readLine());
    if (!head) head = tail = newNode;
    else {
      tail.next = newNode;
      tail = newNode;
    }
  }
  return head;
}

class MyNode {
  constructor(data) {
    this.data = data;
    this.next = null;
  }
}

function removeConsecutiveDuplicates(head) {
  for (let node = head; node?.next; )
    if (node.data === node.next.data) node.next = node.next.next;
    else node = node.next;
}

function display(head) {
  for (let node = head; node; node = node.next)
    process.stdout.write(node.data + ' ');
}
