// https://www.hackerrank.com/challenges/30-queues-stacks/problem?isFullScreen=true

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
  let word: string = readLine();
  let obj: QueueAndStack = initQueueAndStack(word);
  checkIfPalindrome(obj, word);
}

function initQueueAndStack(word: string): QueueAndStack {
  let obj = new QueueAndStack();
  for (const ch of word) {
    obj.enqueueCharacter(ch);
    obj.pushCharacter(ch);
  }
  return obj;
}

class QueueAndStack {
  private myQueue: string[];
  private myStack: string[];

  constructor() {
    this.myQueue = [];
    this.myStack = [];
  }

  enqueueCharacter(ch: string) {
    this.myQueue.push(ch);
  }

  pushCharacter(ch: string) {
    this.myStack.push(ch);
  }

  dequeueCharacter(): string | undefined {
    return this.myQueue.shift();
  }

  popCharacter(): string | undefined {
    return this.myStack.pop();
  }
}

function checkIfPalindrome(obj: QueueAndStack, word: string) {
  let isPalindrome = true;

  for (let halfLength: number = word.length / 2; halfLength-- > 0; )
    if (obj.dequeueCharacter() !== obj.popCharacter()) {
      isPalindrome = false;
      break;
    }

  let notWord = isPalindrome ? ' ' : ' not ';
  console.log('The word, ' + word + ', is' + notWord + 'a palindrome.');
}
