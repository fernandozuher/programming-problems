// https://www.hackerrank.com/challenges/30-linked-list/problem?isFullScreen=true

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
  let n = +readLine();
  let list = initializeList(n);
  list.display();
}

function initializeList(n) {
  let list = new LinkedList();
  while (n--) list.insert(+readLine());
  return list;
}

class LinkedList {
  #head;

  constructor() {
    this.#head = null;
  }

  insert(data) {
    let tail = this.#tailNode();
    if (tail) tail.next = new INode(data);
    else this.#head = new INode(data);
  }

  #tailNode() {
    let tail = this.#head;
    for (; tail && tail.next; tail = tail.next);
    return tail;
  }

  display() {
    for (let node = this.#head; node; node = node.next)
      process.stdout.write(node.data + ' ');
  }
}

class INode {
  constructor(data, next = null) {
    this.data = data;
    this.next = next;
  }
}
