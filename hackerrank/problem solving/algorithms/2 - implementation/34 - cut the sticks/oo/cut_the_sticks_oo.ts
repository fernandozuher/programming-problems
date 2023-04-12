// Source: https://www.hackerrank.com/challenges/cut-the-sticks/problem?isFullScreen=true

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


function main() {
    const _SIZE: number = +readLine();
    const ARRAY: Array<number> = readAnArray();
    ARRAY.sort((a, b) => a - b);

    const OBJ: CutTheSticks = new CutTheSticks(ARRAY);
    const RESULT: Array<number> = OBJ.getRemainingSticksLengthArray();
    printArray(RESULT);
}

    function readAnArray(): Array<number> {
        return readLine().split(" ").map(Number);
    }

    function printArray(array: Array<number>) {
        array.forEach((element, _) => console.log(element));
    }

    class CutTheSticks {
        _sticksLengthArray: Array<number>;
        _sizeSticksLengthArray: number;
        _remainingSticksLengthArray: Array<number>;

        public constructor(array: Array<number>) {
            this._sticksLengthArray = array;
            this._sizeSticksLengthArray = array.length;
            this._initializeRemainingSticksLengthArray();
            this._cutTheSticks();
        }

            private _initializeRemainingSticksLengthArray() {
                this._remainingSticksLengthArray = [this._sizeSticksLengthArray];
            }

            private _cutTheSticks() {
                for (let i = 0; i < this._sizeSticksLengthArray; ) {
                    const SHORTEST_STICK_LENGTH: number = this._sticksLengthArray[i];

                    i = this._findFirstElementIndexDifferentOfFirstCurrentShortestStickLengthIndex(i);
                    const CURRENT_ITERATION_SIZE: number = this._sizeSticksLengthArray - i;
                    if (i === this._sizeSticksLengthArray)
                        break;

                    this._remainingSticksLengthArray.push(CURRENT_ITERATION_SIZE);
                    this._decreaseSticksLengthsHigherThanCurrentShortestStickLength(i, SHORTEST_STICK_LENGTH);
                }
            }

                private _findFirstElementIndexDifferentOfFirstCurrentShortestStickLengthIndex(index: number): number {
                    const SHORTEST_STICK_LENGTH: number = this._sticksLengthArray[index];
                    while (index < this._sizeSticksLengthArray && this._sticksLengthArray[index] === SHORTEST_STICK_LENGTH)
                        index++;
                    return index;
                }

                private _decreaseSticksLengthsHigherThanCurrentShortestStickLength(index: number, shortestStickLength: number) {
                    for (let i = index; i < this._sizeSticksLengthArray; i++)
                        this._sticksLengthArray[i] -= shortestStickLength;
                }

        public getRemainingSticksLengthArray() {
            return this._remainingSticksLengthArray;
        }
    }
