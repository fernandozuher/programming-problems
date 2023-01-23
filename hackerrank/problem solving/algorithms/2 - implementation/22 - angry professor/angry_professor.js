// Source: https://www.hackerrank.com/challenges/angry-professor/problem?isFullScreen=true

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
    const inputLine = readLineAsNumberArray();
    const nTestCases = inputLine[0];
    const results = Array(nTestCases).fill(0);

    for (const i in results) {
        const angryProfessor = new AngryProfessor();
        results[i] = angryProfessor.getCancelledClass();
    }

    for (const result of results)
        console.log(result ? "YES" : "NO");
}

    function readLineAsNumberArray() {
        const inputLine = readLine().split(" ").map(Number);
        return inputLine;
    }

    class AngryProfessor {
        #cancellationThreshold;
        #studentsArrivalTime;
        #cancelledClass;

        constructor() {
            const inputLine = readLineAsNumberArray();
            this.#cancellationThreshold = inputLine[1];
            this.#studentsArrivalTime = readLineAsNumberArray();

            this.#angryProfessor();
        }

            #angryProfessor() {
                this.#cancelledClass = this.#countEarlyArrivalTime() < this.#cancellationThreshold;
            }

                #countEarlyArrivalTime() {
                    let earlyArrivalTimeCount = 0;

                    for (const studentArrivalTime of this.#studentsArrivalTime)
                        if (studentArrivalTime <= 0)
                            earlyArrivalTimeCount++;

                    return earlyArrivalTimeCount;
                }

        getCancelledClass() {
            return this.#cancelledClass;
        }
    }
