// Source: https://www.hackerrank.com/challenges/jumping-on-the-clouds/problem?isFullScreen=true

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
    const _ = +readLine();
    const CLOUD_ARRAY = readAnArray();
    
    const OBJ = new JumpingOnTheClouds(CLOUD_ARRAY);
    const MINIMUM_NUMBER_OF_JUMPS = OBJ.getMinimumNumberOfJumps();
    console.log(MINIMUM_NUMBER_OF_JUMPS);
}

    function readAnArray() {
        const ARRAY = readLine().split(" ").map(Number);
        return ARRAY;
    }

    class JumpingOnTheClouds {
        #cloudArray;
        #minimumNumberOfJumps;

        constructor(cloudArray) {
            this.#cloudArray = cloudArray;
            this.#minimumNumberOfJumps = 0;

            this.#calculateMinimumNumberOfJumps();
        }

            #calculateMinimumNumberOfJumps() {
                for (let i = 0, size = this.#cloudArray.length - 1; i < size; ) {
                    i = this.#getIndexOfNextJump(i);
                    this.#minimumNumberOfJumps++;
                }
            }

                #getIndexOfNextJump(index) {
                    if (this.#isNextSecondIndexInsideRange(index + 2))
                        index += this.#isNextSecondCloudCumulus(this.#cloudArray[index + 2]) ? 2 : 1;
                    else
                        index++;
                    return index;
                }

                    #isNextSecondIndexInsideRange(index) {
                        return index < this.#cloudArray.length;
                    }

                    #isNextSecondCloudCumulus(typeOfCloud) {
                        return typeOfCloud === 0;
                    }

        getMinimumNumberOfJumps() {
            return this.#minimumNumberOfJumps;
        }
    }
