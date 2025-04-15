// https://www.hackerrank.com/challenges/30-linked-list-deletion/problem?isFullScreen=true

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
  const head: MyNode | null = readList();
  removeConsecutiveDuplicates(head);
  display(head);
}

type MyNode = {
  data: number;
  next?: MyNode | null;
};

function readList(): MyNode | null {
  let n: number = +readLine();
  let head: MyNode | null = null;
  let tail: MyNode | null = null;

  while (n--) {
    let newNode: MyNode = { data: +readLine() };
    if (!head) head = tail = newNode;
    else {
      tail.next = newNode;
      tail = newNode;
    }
  }
  return head;
}

function removeConsecutiveDuplicates(head: MyNode | null) {
  for (let node = head; node?.next; )
    if (node.data === node.next.data) node.next = node.next.next;
    else node = node.next;
}

function display(head: MyNode | null) {
  for (let node = head; node; node = node.next)
    process.stdout.write(node.data + ' ');
}
