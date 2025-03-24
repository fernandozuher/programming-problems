// https://www.hackerrank.com/challenges/30-linked-list/problem?isFullScreen=true

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
  let n = +readLine();
  let list: LinkedList = initializeList(n);
  list.display();
}

function initializeList(n: number): LinkedList {
  let list = new LinkedList();
  while (n--) list.insert(+readLine());
  return list;
}

class LinkedList {
  private head: INode | null;

  constructor() {
    this.head = null;
  }

  public insert(data: number) {
    let tail: INode | null = this.tailNode();
    if (tail) tail.next = { data };
    else this.head = { data };
  }

  private tailNode(): INode | null {
    let tail = this.head;
    for (; tail && tail.next; tail = tail.next);
    return tail;
  }

  public display() {
    for (let node = this.head; node; node = node.next)
      process.stdout.write(node.data + ' ');
  }
}

interface INode {
  data: number;
  next?: INode;
}
