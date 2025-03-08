// https://www.hackerrank.com/challenges/30-binary-numbers/problem?isFullScreen=true

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
  let n: number = +readLine();
  let binary = new IntToBinary(n);
  console.log(binary.sizeWidestRangeBitsOne());
}

class IntToBinary {
  private readonly binary: string;
  private readonly sizeWidestRangeBits1: number;

  constructor(n: number) {
    this.binary = n.toString(2);
    this.sizeWidestRangeBits1 = this.findSizeWidestRangeBits1();
  }

  private findSizeWidestRangeBits1(): number {
    let sizeWidestRange = 0;
    for (let i = 0; i < this.binary.length; i++)
      if (this.binary[i] === '1') {
        let sizeRange: number = this.findSizeRangeBits1(i);
        sizeWidestRange = Math.max(sizeRange, sizeWidestRange);
        i += sizeRange;
      }
    return sizeWidestRange;
  }

  private findSizeRangeBits1(beginIndex: number): number {
    let index = this.findBit0(beginIndex);
    return index === -1 ? this.binary.length - beginIndex : index;
  }

  private findBit0(beginIndex: number): number {
    return this.binary.substring(beginIndex).indexOf('0');
  }

  sizeWidestRangeBitsOne() {
    return this.sizeWidestRangeBits1;
  }
}
