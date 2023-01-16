// Source: https://www.hackerrank.com/challenges/climbing-the-leaderboard/problem?isFullScreen=true

'use strict';

process.stdin.resume();
process.stdin.setEncoding('utf-8');

let inputString = '';
let currentLine = 0;

process.stdin.on('data', function(inputStdin) {
    inputString += inputStdin;
});

process.stdin.on('end', function() {
    inputString = inputString.split('\n');
    main();
});

function readLine() {
    return inputString[currentLine++];
}


function main() {
    readLineAsNumberArray();
    const ranked = readLineAsNumberArray();

    readLineAsNumberArray();
    const player = readLineAsNumberArray();

    const result = new Result(ranked, player);
}

    function readLineAsNumberArray() {
        const inputLine = readLine().split(" ").map(Number);
        return inputLine;
    }

    class Result {
        #ranked;
        #player;
        #playerRank;

        constructor(ranked, player) {
            this.#ranked = [...ranked];
            this.#player = [...player];
            this.#playerRank = [];

            this.#removeDuplicatesFromRankedArray();
            this.#climbingLeaderboard();
            this.printResult();
        }

            #removeDuplicatesFromRankedArray() {
                this.#ranked = [...new Set(this.#ranked)];
            }

            #climbingLeaderboard() {
                for (const [i, playerScore] of this.#player.entries()) {
                    let index = this.#binarySearchDescendingOrder(0, this.#ranked.length - 1, playerScore);
                    this.#playerRank[i] = ++index;
                }
            }

                #binarySearchDescendingOrder(low, high, key) {
                    if (high >= low) {
                        const middle = low + Math.trunc((high - low) / 2);

                        if (key === this.#ranked[middle])
                            return middle;
                        else if (key > this.#ranked[middle])
                            return this.#binarySearchDescendingOrder(low, middle - 1, key);
                        else
                            return this.#binarySearchDescendingOrder(middle + 1, high, key);
                    }
                    return low;
                }

            printResult() {
                for (const playerRank of this.#playerRank)
                    console.log(playerRank);
            }
    }
