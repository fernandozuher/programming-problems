// https://www.hackerrank.com/challenges/utopian-tree/problem?isFullScreen=true

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

//////////////////////////////////////////////////

function main() {
    let n = +readLine();
    let testCases = readLines(n);
    let obj = new UtopianTree(testCases);
    obj.treesHeights().forEach(x => console.log(x));
}

    function readLines(n) {
        return Array(n).fill(0).map(_ => +readLine());
    }

    class UtopianTree {
        #testCases;
        #treesHeights;

        constructor(testCases) {
            this.#testCases = testCases;
            this.#treesHeights = Array(testCases.length).fill(0);
            this.#calculateTreesHeights();
        }

            #calculateTreesHeights() {
                for (let i = 0, n = this.#treesHeights.length; i < n; ++i)
                    this.#treesHeights[i] = this.#calculateHeight(this.#testCases[i]);
            }

                #calculateHeight(cycles) {
                    let height = 1;
                    for (let cycle = 1; cycle <= cycles; ++cycle)
                        height = this.#isCycleHappeningDuringSpring(cycle) ? height * 2 : height + 1;
                    return height;
                }

                    #isCycleHappeningDuringSpring(cycle) {
                        return cycle & 1;
                    }

        treesHeights() {
            return this.#treesHeights;
        }
    }
