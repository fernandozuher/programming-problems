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
  console.log(binary.maxConsecutiveOnesFromBinary());
}

class IntToBinary {
  private readonly binary: string;
  private readonly maxConsecutiveOnes: number;

  public constructor(n: number) {
    this.binary = n.toString(2);
    this.maxConsecutiveOnes = this.findMaxConsecutiveOnesFromBinary();
  }

  private findMaxConsecutiveOnesFromBinary(): number {
    let max1Bits = 0;
    for (let i = 0; i < this.binary.length; i++)
      if (this.binary[i] === '1') {
        let nBits = this.sizeOfNextRangeOfBits1(i);
        max1Bits = Math.max(nBits, max1Bits);
        i += nBits;
      }
    return max1Bits;
  }

  private sizeOfNextRangeOfBits1(beginIndex: number): number {
    let nextAfterLastIndex: number =
      this.findNextAfterLastIndexOfConsecutive1s(beginIndex);
    return nextAfterLastIndex - beginIndex;
  }

  private findNextAfterLastIndexOfConsecutive1s(beginIndex: number): number {
    let nextAfterLastIndex: number = this.binary
      .substring(beginIndex)
      .indexOf('0');
    return nextAfterLastIndex === -1
      ? this.binary.length
      : nextAfterLastIndex + beginIndex; // + begin_index because index was found from that, not from index 0
  }

  public maxConsecutiveOnesFromBinary(): number {
    return this.maxConsecutiveOnes;
  }
}
