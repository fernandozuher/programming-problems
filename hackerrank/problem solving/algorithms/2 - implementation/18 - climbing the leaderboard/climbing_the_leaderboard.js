// https://www.hackerrank.com/challenges/climbing-the-leaderboard/problem?isFullScreen=true

'use strict';

process.stdin.resume();
process.stdin.setEncoding('utf-8');

let inputString = '';
let inputLines = [];
let currentLine = 0;

process.stdin.on('data', function(inputStdin) {
    inputString += inputStdin;
});

process.stdin.on('end', function() {
    inputLines = inputString.split('\n');
    inputString = '';
    main();
});

function readLine() {
    return inputLines[currentLine++];
}

////////////////////////////////////////////////

function main() {
    let n = +readLine();
    let ranked = readIntArray();
    ranked = removeDuplicates(ranked);

    n = +readLine();
    let player = readIntArray();

    let obj = new ClimbingTheLeaderboard(ranked, player);
    obj.playerRank().forEach(x => console.log(x));
}

    function readIntArray() {
        return readLine().split(' ').map(Number);
    }

    function removeDuplicates(array) {
        return [...new Set(array)];
    }

    function binarySearchDescendingOrder(array, low, high, key) {
        if (high >= low) {
            let middle = low + Math.trunc((high - low) / 2);

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
        #ranked;
        #player;
        #playerRank;

        constructor(ranked, player) {
            this.#ranked = ranked;
            this.#player = player;
            this.#playerRank = [];
            this.#climbingLeaderboard();
        }

            #climbingLeaderboard() {
                for (const [i, playerScore] of this.#player.entries()) {
                    let index = binarySearchDescendingOrder(this.#ranked, 0, this.#ranked.length - 1, playerScore);
                    this.#playerRank[i] = ++index;
                }
            }

        playerRank() {
            return this.#playerRank;
        }
    }
