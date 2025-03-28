// https://www.hackerrank.com/challenges/30-queues-stacks/problem?isFullScreen=true

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
  let word = readLine();
  let obj = initQueueAndStack(word);
  checkIfPalindrome(obj, word);
}

function initQueueAndStack(word) {
  let obj = new QueueAndStack();
  for (const ch of word) {
    obj.enqueueCharacter(ch);
    obj.pushCharacter(ch);
  }
  return obj;
}

class QueueAndStack {
  #myQueue;
  #myStack;

  constructor() {
    this.#myQueue = [];
    this.#myStack = [];
  }

  enqueueCharacter(ch) {
    this.#myQueue.push(ch);
  }

  pushCharacter(ch) {
    this.#myStack.push(ch);
  }

  dequeueCharacter() {
    return this.#myQueue.shift();
  }

  popCharacter() {
    return this.#myStack.pop();
  }
}

function checkIfPalindrome(obj, word) {
  let isPalindrome = true;

  for (let halfLength = word.length / 2; halfLength-- > 0;)
    if (obj.dequeueCharacter() !== obj.popCharacter()) {
      isPalindrome = false;
      break;
    }

  let notWord = isPalindrome ? ' ' : ' not ';
  console.log('The word, ' + word + ', is' + notWord + 'a palindrome.');
}
