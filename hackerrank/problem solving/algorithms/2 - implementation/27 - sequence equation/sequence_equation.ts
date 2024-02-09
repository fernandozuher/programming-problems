// https://www.hackerrank.com/challenges/permutation-equation/problem?isFullScreen=true

'use strict';

process.stdin.resume();
process.stdin.setEncoding('utf-8');

let inputString: string = '';
let inputLines: string[] = [];
let currentLine: number = 0;

process.stdin.on('data', function(inputStdin: string): void {
    inputString += inputStdin;
});

process.stdin.on('end', function(): void {
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
    let array: number[] = readIntArray();
    let obj = new SequenceEquation(array);
    obj.permutatedArray().forEach(x => console.log(x));
}

    function readIntArray(): number[] {
        return readLine().split(' ').map(Number);
    }

    class SequenceEquation {
        private array: number[];
        private elementsPositionsArray: number[];
        private permutArray: number[];

        constructor(array: number[]) {
            this.array = array;
            this.elementsPositionsArray = Array(array.length).fill(0);
            this.permutArray = Array(array.length).fill(0);
            this.generateElementsPositionsArray();
            this.generatePermutatedArray();
        }

            private generateElementsPositionsArray() {
                this.array.forEach((element, i) => {
                    this.elementsPositionsArray[element-1] = i;
                });
            }

            private generatePermutatedArray() {
                this.elementsPositionsArray.forEach((element, i) => {
                    this.permutArray[i] = this.elementsPositionsArray[element] + 1;
                });
            }

        public permutatedArray(): number[] {
            return this.permutArray;
        }
    }
