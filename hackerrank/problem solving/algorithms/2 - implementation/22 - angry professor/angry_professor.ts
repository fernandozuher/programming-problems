// Source: https://www.hackerrank.com/challenges/angry-professor/problem?isFullScreen=true

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


function main() {
    const inputLine: number[] = readLineAsNumberArray();
    const nTestCases: number = inputLine[0];
    const results: boolean[] = Array(nTestCases).fill(false);

    for (const i in results) {
        const angryProfessor = new AngryProfessor();
        results[i] = angryProfessor.getCancelledClass();
    }

    for (const result of results)
        console.log(result ? "YES" : "NO");
}

    function readLineAsNumberArray(): number[] {
        const inputLine = readLine().split(" ").map(Number);
        return inputLine;
    }

    class AngryProfessor {
        _cancellationThreshold: number;
        _studentsArrivalTime: number[];
        _cancelledClass: boolean;

        constructor() {
            const inputLine: number[] = readLineAsNumberArray();
            this._cancellationThreshold = inputLine[1];
            this._studentsArrivalTime = readLineAsNumberArray();

            this._angryProfessor();
        }

            _angryProfessor() {
                this._cancelledClass = this._countEarlyArrivalTime() < this._cancellationThreshold;
            }

                _countEarlyArrivalTime(): number {
                    let earlyArrivalTimeCount: number = 0;

                    for (const studentArrivalTime of this._studentsArrivalTime)
                        if (studentArrivalTime <= 0)
                            earlyArrivalTimeCount++;

                    return earlyArrivalTimeCount;
                }

        getCancelledClass(): boolean {
            return this._cancelledClass;
        }
    }
