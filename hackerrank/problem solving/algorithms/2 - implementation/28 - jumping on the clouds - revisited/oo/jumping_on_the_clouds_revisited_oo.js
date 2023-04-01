// Source: https://www.hackerrank.com/challenges/jumping-on-the-clouds-revisited/problem?isFullScreen=true

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
    let array = readAnArray();
    const _SIZE_ARRAY = array[0];
    const JUMP_LENGTH = array[1];
    array = readAnArray();

    const OBJ = new JumpingOnTheClouds(array, JUMP_LENGTH);
    console.log(OBJ.getRemainingEnergy());
}

    function readAnArray() {
        const ARRAY = readLine().split(" ").map(Number);
        return ARRAY;
    }

    class JumpingOnTheClouds {
        #array;
        #jumpLength;
        #energy;

        constructor(array, jumpLength) {
            this.#array = array;
            this.#jumpLength = jumpLength;
            this.#energy = 100;

            this.#jumpOnClouds();
        }

        #jumpOnClouds() {
            for (let cloudIndex = 0; true; ) {
                this.#energy -= this.#spentEnergyAccordingToTypeOfCloud(this.#array[cloudIndex]);
                cloudIndex = this.#generateNewCloudIndex(cloudIndex);
                if (this.#isCloudIndexBackToFirstCloud(cloudIndex)) {
                    break;
                }
            }
        }

            #spentEnergyAccordingToTypeOfCloud(cloudType) {
                return cloudType == 0 ? 1 : 3;
            }

            #generateNewCloudIndex(cloudIndex) {
                return (cloudIndex + this.#jumpLength) % this.#array.length;
            }

            #isCloudIndexBackToFirstCloud(cloudIndex) {
                return cloudIndex == 0;
            }

        getRemainingEnergy() {
            return this.#energy;
        }
    }
