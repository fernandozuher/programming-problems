// https://www.hackerrank.com/challenges/circular-array-rotation/problem?isFullScreen=true

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
    let [n, rotationCount, nQueries]: number[] = readIntArray();
    let array: number[] = readIntArray();
    let queries: number[] = readLines(nQueries);

    let obj = new CircularArrayRotation(array, rotationCount);
    printArrayAccordingToIndexFromAnotherArray(obj.rotatedArray(), queries);
}

    function readIntArray(): number[] {
        return readLine().split(' ').map(Number);
    }

    function readLines(n: number): number[] {
        return Array(n).fill(0).map(_ => +readLine());
    }

    function printArrayAccordingToIndexFromAnotherArray(array1: number[], array2: number[]) {
        array2.forEach(i => console.log(array1[i]));
    }

    class CircularArrayRotation {
        private array: number[];
        private rotationCount: number;

        constructor(array: number[], rotationCount: number) {
            this.array = array;
            this.rotationCount = rotationCount
            this.reduceRotations();
            this.rotateArray();
        }
        
            private reduceRotations() {
                if (this.array.length > 1)
                    this.rotationCount = this.rotationCount >= this.array.length ? this.rotationCount % this.array.length : this.rotationCount;
                else
                    this.rotationCount = 0;
            }

            private rotateArray() {
                let firstPartNewArray: number[] = this.array.slice(this.array.length - this.rotationCount, this.array.length);
                let secondPartNewArray: number[] = this.array.slice(0, this.array.length - this.rotationCount);
                this.array = [...firstPartNewArray, ...secondPartNewArray];
            }

        public rotatedArray(): number[] {
            return this.array;
        }
    }
