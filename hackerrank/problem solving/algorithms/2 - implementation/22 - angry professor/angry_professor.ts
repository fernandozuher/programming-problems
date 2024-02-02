// https://www.hackerrank.com/challenges/angry-professor/problem?isFullScreen=true

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

//////////////////////////////////////////////////

function main() {
    let n: number = +readLine();
    let cancelledClasses: boolean[] = Array(n).fill(false);

    for (const i in cancelledClasses) {
        let [nStudentsArrivalTime, cancellationThreshold]: number[] = readIntArray();
        let studentsArrivalTime: number[] = readIntArray();
        let obj = new AngryProfessor(studentsArrivalTime, cancellationThreshold);
        cancelledClasses[i] = obj.cancelledClass();
    }

    for (const cancelled of cancelledClasses)
        console.log(cancelled ? 'YES' : 'NO');
}

    function readIntArray(): number[] {
        return readLine().split(' ').map(Number);
    }

    class AngryProfessor {
        private studentsArrivalTime: number[];
        private cancellationThreshold: number;
        private cancelled: boolean;

        constructor(studentsArrivalTime: number[], cancellationThreshold: number) {
            this.studentsArrivalTime = studentsArrivalTime;
            this.cancellationThreshold = cancellationThreshold;
            this.cancelled = false;
            this.checkIfClassIsCancelled();
        }

            private checkIfClassIsCancelled() {
                this.cancelled = this.countEarlyArrivalTime() < this.cancellationThreshold;
            }

                private countEarlyArrivalTime() {
                    let earlyArrivalTimeCount = 0;

                    for (const arrivalTime of this.studentsArrivalTime)
                        if (arrivalTime <= 0)
                            ++earlyArrivalTimeCount;

                    return earlyArrivalTimeCount;
                }

        public cancelledClass(): boolean {
            return this.cancelled;
        }
    }
