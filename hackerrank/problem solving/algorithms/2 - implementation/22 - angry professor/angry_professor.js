// https://www.hackerrank.com/challenges/angry-professor/problem?isFullScreen=true

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
    let cancelledClasses = Array(n).fill(false);

    for (const i in cancelledClasses) {
        let [nStudentsArrivalTime, cancellationThreshold] = readIntArray();
        let studentsArrivalTime = readIntArray();
        let obj = new AngryProfessor(studentsArrivalTime, cancellationThreshold);
        cancelledClasses[i] = obj.cancelledClass();
    }

    for (const cancelled of cancelledClasses)
        console.log(cancelled ? 'YES' : 'NO');
}

    function readIntArray() {
        return readLine().split(' ').map(Number);
    }

    class AngryProfessor {
        #studentsArrivalTime;
        #cancellationThreshold;
        #cancelledClass;

        constructor(studentsArrivalTime, cancellationThreshold) {
            this.#studentsArrivalTime = studentsArrivalTime;
            this.#cancellationThreshold = cancellationThreshold;
            this.#cancelledClass = false;
            this.#checkIfClassIsCancelled();
        }

            #checkIfClassIsCancelled() {
                this.#cancelledClass = this.#countEarlyArrivalTime() < this.#cancellationThreshold;
            }

                #countEarlyArrivalTime() {
                    let earlyArrivalTimeCount = 0;

                    for (const arrivalTime of this.#studentsArrivalTime)
                        if (arrivalTime <= 0)
                            ++earlyArrivalTimeCount;

                    return earlyArrivalTimeCount;
                }

        cancelledClass() {
            return this.#cancelledClass;
        }
    }
