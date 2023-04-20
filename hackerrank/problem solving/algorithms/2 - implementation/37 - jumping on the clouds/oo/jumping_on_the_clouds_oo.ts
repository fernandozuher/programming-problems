// Source: https://www.hackerrank.com/challenges/jumping-on-the-clouds/problem?isFullScreen=true

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
    const _: number = +readLine();
    const CLOUD_ARRAY: Array<number> = readAnArray();
    
    const OBJ: JumpingOnTheClouds = new JumpingOnTheClouds(CLOUD_ARRAY);
    const MINIMUM_NUMBER_OF_JUMPS: number = OBJ.getMinimumNumberOfJumps();
    console.log(MINIMUM_NUMBER_OF_JUMPS);
}

    function readAnArray() {
        const ARRAY: Array<number> = readLine().split(" ").map(Number);
        return ARRAY;
    }

    class JumpingOnTheClouds {
       private _cloudArray: Array<number>;
       private _minimumNumberOfJumps: number;

        public constructor(cloudArray: Array<number>) {
            this._cloudArray = cloudArray;
            this._minimumNumberOfJumps = 0;

            this._calculateMinimumNumberOfJumps();
        }

           private _calculateMinimumNumberOfJumps() {
                for (let i = 0, size = this._cloudArray.length - 1; i < size; ) {
                    i = this._getIndexOfNextJump(i);
                    this._minimumNumberOfJumps++;
                }
            }

               private _getIndexOfNextJump(index: number) {
                    if (this._isNextSecondIndexInsideRange(index + 2))
                        index += this._isNextSecondCloudCumulus(this._cloudArray[index + 2]) ? 2 : 1;
                    else
                        index++;
                    return index;
                }

                   private _isNextSecondIndexInsideRange(index: number) {
                        return index < this._cloudArray.length;
                    }

                   private _isNextSecondCloudCumulus(typeOfCloud: number) {
                        return typeOfCloud === 0;
                    }

        getMinimumNumberOfJumps(): number {
            return this._minimumNumberOfJumps;
        }
    }
