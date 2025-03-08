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
  console.log(binary.sizeWidestRangeBitsOne());
}

class IntToBinary {
  #binary;
  #sizeWidestRangeBits1;

  constructor(n) {
    this.#binary = n.toString(2);
    this.#sizeWidestRangeBits1 = this.#findSizeWidestRangeBits1();
  }

  #findSizeWidestRangeBits1() {
    let sizeWidestRange = 0;
    for (let i = 0; i < this.#binary.length; i++)
      if (this.#binary[i] === '1') {
        let sizeRange = this.#findSizeRangeBits1(i);
        sizeWidestRange = Math.max(sizeRange, sizeWidestRange);
        i += sizeRange;
      }
    return sizeWidestRange;
  }

  #findSizeRangeBits1(beginIndex) {
    let index = this.#findBit0(beginIndex);
    return index === -1 ? this.#binary.length - beginIndex : index;
  }

  #findBit0(beginIndex) {
    return this.#binary.substring(beginIndex).indexOf('0');
  }

  sizeWidestRangeBitsOne() {
    return this.#sizeWidestRangeBits1;
  }
}
