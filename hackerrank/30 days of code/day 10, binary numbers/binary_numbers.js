// https://www.hackerrank.com/challenges/30-binary-numbers/problem?isFullScreen=true

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
  let binary = new IntToBinary(n);
  console.log(binary.maxConsecutiveOnesFromBinary());
}

class IntToBinary {
  #binary = '';
  #maxConsecutiveOnes = 0;

  constructor(n) {
    this.#binary = n.toString(2);
    this.#maxConsecutiveOnes = this.#findMaxConsecutiveOnesFromBinary();
  }

  #findMaxConsecutiveOnesFromBinary() {
    let max1Bits = 0;
    for (let i = 0; i < this.#binary.length; i++)
      if (this.#binary[i] === '1') {
        let nBits = this.#sizeOfNextRangeOfBits1(i);
        max1Bits = Math.max(nBits, max1Bits);
        i += nBits;
      }
    return max1Bits;
  }

  #sizeOfNextRangeOfBits1(beginIndex) {
    let nextAfterLastIndex =
      this.#findNextAfterLastIndexOfConsecutive1s(beginIndex);
    return nextAfterLastIndex - beginIndex;
  }

  #findNextAfterLastIndexOfConsecutive1s(beginIndex) {
    let nextAfterLastIndex = this.#binary.substring(beginIndex).indexOf('0');
    return nextAfterLastIndex === -1
      ? this.#binary.length
      : nextAfterLastIndex + beginIndex; // + begin_index because index was found from that, not from index 0
  }

  maxConsecutiveOnesFromBinary() {
    return this.#maxConsecutiveOnes;
  }
}
