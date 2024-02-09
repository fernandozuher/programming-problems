// https://www.hackerrank.com/challenges/jumping-on-the-clouds-revisited/problem?isFullScreen=true

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
    let [n, jumpLength] = readIntArray();
    let array = readIntArray();
    let obj = new JumpingOnTheClouds(array, jumpLength);
    console.log(obj.remainingEnergy());
}

    function readIntArray() {
        return readLine().split(' ').map(Number);
    }

    class JumpingOnTheClouds {
        #clouds;
        #jumpLength;
        #energy;

        constructor(clouds, jumpLength) {
            this.#clouds = clouds;
            this.#jumpLength = jumpLength;
            this.#energy = 100;
            this.#calculateRemainingEnergy();
        }

            #calculateRemainingEnergy() {
                for (let cloudIndex = 0; true;) {
                    this.#energy -= this.#spentEnergyAccordingToTypeOfCloud(this.#clouds[cloudIndex]);
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
                    return (cloudIndex + this.#jumpLength) % this.#clouds.length;
                }

                #isCloudIndexBackToFirstCloud(cloudIndex) {
                    return cloudIndex == 0;
                }

        remainingEnergy() {
            return this.#energy;
        }
    }
