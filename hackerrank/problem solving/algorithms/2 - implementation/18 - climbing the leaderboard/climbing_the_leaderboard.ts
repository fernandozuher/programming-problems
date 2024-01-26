// https://www.hackerrank.com/challenges/climbing-the-leaderboard/problem?isFullScreen=true

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

////////////////////////////////////////////////

function main() {
    let n: number = +readLine();
    let ranked: number[] = readIntArray();
    ranked = removeDuplicates(ranked);

    n = +readLine();
    let player: number[] = readIntArray();

    let obj = new ClimbingTheLeaderboard(ranked, player);
    obj.rank().forEach(x => console.log(x));
}

    function readIntArray(): number[] {
        return readLine().split(' ').map(Number);
    }

    function removeDuplicates(array: number[]): number[] {
        return [...new Set(array)];
    }

    function binarySearchDescendingOrder(array: number[], low: number, high: number, key: number): number {
        if (high >= low) {
            let middle: number = low + Math.trunc((high - low) / 2);

            if (key === array[middle])
                return middle;
            else if (key > array[middle])
                return binarySearchDescendingOrder(array, low, middle - 1, key);
            else
                return binarySearchDescendingOrder(array, middle + 1, high, key);
        }
        return low;
    }

    class ClimbingTheLeaderboard {
        private ranked: number[];
        private player: number[];
        private playerRank: number[];

        constructor(ranked: number[], player: number[]) {
            this.ranked = ranked;
            this.player = player;
            this.playerRank = [];
            this.climbingLeaderboard();
        }

            private climbingLeaderboard() {
                for (const [i, playerScore] of this.player.entries()) {
                    let index = binarySearchDescendingOrder(this.ranked, 0, this.ranked.length - 1, playerScore);
                    this.playerRank[i] = ++index;
                }
            }

        public rank(): number[] {
            return this.playerRank;
        }
    }
