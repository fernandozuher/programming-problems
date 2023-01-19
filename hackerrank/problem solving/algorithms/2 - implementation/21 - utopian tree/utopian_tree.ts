// Source: https://www.hackerrank.com/challenges/utopian-tree/problem?isFullScreen=true

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
    const nTestCases = readLineAsNumber();
    const nTestCasesCycles = readCycles(nTestCases);
    const result = new Result(nTestCasesCycles);
}

    function readLineAsNumber() {
        const number = parseInt(readLine());
        return number;
    }

    function readCycles(nTestCases: number): number[] {
        let nTestCasesCycles = [...Array(nTestCases)].map(readLineAsNumber);
        return nTestCasesCycles;
    }

    class Result {
        private _nTestCasesCycles: number[];
        private _treesHeights: number[];

        constructor(nTestCasesCycles: number[]) {
            this._nTestCasesCycles = [...nTestCasesCycles];
            this._treesHeights = Array(nTestCasesCycles.length);

            this._utopianTree();
            this.printTreesHeights();
        }

            private _utopianTree() {
                for (let i = 0, n = this._treesHeights.length; i < n; i++)
                    this._treesHeights[i] = this._calculateHeight(this._nTestCasesCycles[i]);
            }

                private _calculateHeight(cycles: number): number {
                    let height = 1;
                    for (let cycle = 1; cycle <= cycles; cycle++)
                        height = this._isCycleHappeningDuringSpring(cycle) ? height * 2: height + 1;
                    return height;
                }

                    private _isCycleHappeningDuringSpring(cycle: number): boolean {
                        return (cycle & 1) == 1;
                    }

            printTreesHeights() {
                for (let height of this._treesHeights) console.log(height);
            }
    }
