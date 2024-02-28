// https://www.hackerrank.com/challenges/cut-the-sticks/problem?isFullScreen=true

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
    array.sort((a, b) => a - b);

    let obj = new CutTheSticks(array);
    printArray(obj.remainingSticksArray());
}

    function readIntArray(): number[] {
        return readLine().split(' ').map(Number);
    }

    function printArray(array: number[]) {
        array.forEach(x => console.log(x));
    }

    class CutTheSticks {
        private sticksLengthArray: number[];
        private remainingSticksLengthArray: number[];

        constructor(array: number[]) {
            this.sticksLengthArray = array;
            this.remainingSticksLengthArray = [array.length];
            this.cutTheSticks();
        }

            private cutTheSticks() {
                for (let i = 0, n = this.sticksLengthArray.length; i < n;) {
                    let shortestStickLength: number = this.sticksLengthArray[i];

                    i = this.findFirstElementIndexDifferentOfFirstCurrentShortestStickLengthIndex(i, n);
                    let currentIterationSize: number = n - i;
                    if (i === n)
                        break;

                    this.remainingSticksLengthArray.push(currentIterationSize);
                    this.decreaseSticksLengthsHigherThanCurrentShortestStickLength(i, n, shortestStickLength);
                }
            }

                private findFirstElementIndexDifferentOfFirstCurrentShortestStickLengthIndex(index: number, n: number): number {
                    let shortestStickLength = this.sticksLengthArray[index];
                    while (index < n && this.sticksLengthArray[index] === shortestStickLength)
                        ++index;
                    return index;
                }

                private decreaseSticksLengthsHigherThanCurrentShortestStickLength(index: number, n: number, shortestStickLength: number) {
                    for (let i = index; i < n; ++i)
                        this.sticksLengthArray[i] -= shortestStickLength;
                }

        remainingSticksArray(): number[] {
            return this.remainingSticksLengthArray;
        }
    }
