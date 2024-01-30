// https://www.hackerrank.com/challenges/utopian-tree/problem?isFullScreen=true

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
    let testCases: number[] = readLines(n);
    let obj = new UtopianTree(testCases);
    obj.treesHeights().forEach(x => console.log(x));
}

    function readLines(n: number): number[] {
        return [...Array(n).fill(0)].map(_ => +readLine());
    }

    class UtopianTree {
        private testCases: number[];
        private heights: number[];

        constructor(testCases: number[]) {
            this.testCases = testCases;
            this.heights = Array(testCases.length).fill(0);
            this.calculateTreesHeights();
        }

            private calculateTreesHeights() {
                for (let i = 0, n = this.heights.length; i < n; ++i)
                    this.heights[i] = this.calculateHeight(this.testCases[i]);
            }

                private calculateHeight(cycles: number) {
                    let height: number = 1;
                    for (let cycle = 1; cycle <= cycles; ++cycle)
                        height = this.isCycleHappeningDuringSpring(cycle) ? height * 2 : height + 1;
                    return height;
                }

                    private isCycleHappeningDuringSpring(cycle: number): boolean {
                        return (cycle & 1) === 1;
                    }

        public treesHeights(): number[] {
            return this.heights;
        }
    }
