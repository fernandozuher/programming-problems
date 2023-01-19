// Source: https://www.hackerrank.com/challenges/utopian-tree/problem?isFullScreen=true
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
    const nTestCases = readLineAsNumber();
    const nTestCasesCycles = readCycles(nTestCases);
    const result = new Result(nTestCasesCycles);
}

    function readLineAsNumber() {
        const number = parseInt(readLine());
        return number;
    }

    function readCycles(nTestCases) {
        let nTestCasesCycles = [...Array(nTestCases)].map(readLineAsNumber);
        return nTestCasesCycles;
    }

    class Result {
        #nTestCasesCycles;
        #treesHeights;

        constructor(nTestCasesCycles) {
            this.#nTestCasesCycles = [...nTestCasesCycles];
            this.#treesHeights = Array(nTestCasesCycles.length);

            this.#utopianTree();
            this.printTreesHeights();
        }

            #utopianTree() {
                for (let i = 0, n = this.#treesHeights.length; i < n; i++)
                    this.#treesHeights[i] = this.#calculateHeight(this.#nTestCasesCycles[i]);
            }

                #calculateHeight(cycles) {
                    let height = 1;
                    for (let cycle = 1; cycle <= cycles; cycle++)
                        height = this.#isCycleHappeningDuringSpring(cycle) ? height * 2 : height + 1;
                    return height;
                }

                    #isCycleHappeningDuringSpring(cycle) {
                        return cycle & 1;
                    }

            printTreesHeights() {
                for (let height of this.#treesHeights) console.log(height);
            }
    }
