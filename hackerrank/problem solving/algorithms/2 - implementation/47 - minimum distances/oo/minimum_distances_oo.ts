// Source: https://www.hackerrank.com/challenges/minimum-distances/problem?isFullScreen=true

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


const NO_INDEX = -1;

function main() {
    const _: number = +readLine();
    const ARRAY: Array<number> = readANumericArray();
    const OBJ = new MinimumDistances(ARRAY);
    console.log(OBJ.getMinimumDistance());
}

    function readANumericArray(): Array<number> {
        return readLine().split(" ").map(Number);
    }

    class MinimumDistances {
        private array: Array<number>;
        private minimumDistance: number;

        public constructor(array: Array<number>) {
            this.array = array;
            this.minimumDistance = Number.MAX_SAFE_INTEGER;
            this.findMinimumDistance();
        }

            private findMinimumDistance() {
                const FIRST_INDEXES_OF_ELEMENTS: {[key: number]: Array<number>} = {};

                for (let i = 0, element; i < this.array.length; i++) {
                    element = this.array[i];
                
                    if (FIRST_INDEXES_OF_ELEMENTS.hasOwnProperty(element)) {
                        let [firstIndex, secondIndex]: Array<number> = FIRST_INDEXES_OF_ELEMENTS[element];

                        if (secondIndex == NO_INDEX) {
                            FIRST_INDEXES_OF_ELEMENTS[element][1] = secondIndex = i;
                            const MINIMUM_DISTANCE_OF_CURRENT_ELEMENT: number = secondIndex - firstIndex;
                            this.minimumDistance = Math.min(this.minimumDistance, MINIMUM_DISTANCE_OF_CURRENT_ELEMENT);
                        }
                    } else
                        FIRST_INDEXES_OF_ELEMENTS[element] = [i, NO_INDEX];
                }

                this.minimumDistance = this.minimumDistanceOrNoIndex();
            }

                private minimumDistanceOrNoIndex(): number {
                    return this.minimumDistance != Number.MAX_SAFE_INTEGER ? this.minimumDistance : NO_INDEX;
                }

        public getMinimumDistance(): number {
            return this.minimumDistance;
        }
    }
