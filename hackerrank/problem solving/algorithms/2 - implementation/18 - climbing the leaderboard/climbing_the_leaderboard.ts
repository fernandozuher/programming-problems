// Source: https://www.hackerrank.com/challenges/climbing-the-leaderboard/problem?isFullScreen=true

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
    readLineAsNumberArray();
    const ranked: number[] = readLineAsNumberArray();

    readLineAsNumberArray();
    const player: number[] = readLineAsNumberArray();

    const result = new Result(ranked, player);
}

    function readLineAsNumberArray() {
        const inputLine = readLine().split(" ").map(Number);
        return inputLine;
    }

    class Result {
        private _ranked: number[];
        private _player: number[];
        private _playerRank: number[];

        constructor(ranked: number[], player: number[]) {
            this._ranked = [...ranked];
            this._player = [...player];
            this._playerRank = [];

            this._removeDuplicatesFromRankedArray();
            this._climbingLeaderboard();
            this.printResult();
        }

            private _removeDuplicatesFromRankedArray() {
                this._ranked = [...new Set(this._ranked)];
            }

            private _climbingLeaderboard() {
                for (const [i, playerScore] of this._player.entries()) {
                    let index = this._binarySearchDescendingOrder(0, this._ranked.length - 1, playerScore);
                    this._playerRank[i] = ++index;
                }
            }

                private _binarySearchDescendingOrder(low: number, high: number, key: number): number {
                    if (high >= low) {
                        const middle: number = low + Math.trunc((high - low) / 2);

                        if (key === this._ranked[middle])
                            return middle;
                        else if (key > this._ranked[middle])
                            return this._binarySearchDescendingOrder(low, middle - 1, key);
                        else
                            return this._binarySearchDescendingOrder(middle + 1, high, key);
                    }
                    return low;
                }

            printResult() {
                for (const playerRank of this._playerRank)
                    console.log(playerRank);
            }
    }
