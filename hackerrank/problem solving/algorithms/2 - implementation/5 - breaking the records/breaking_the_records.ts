// https://www.hackerrank.com/challenges/breaking-best-and-worst-records/problem?isFullScreen=true

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
    +readLine();
    let array: number[] = readIntArray();
    let records = new BreakingBestAndWorstRecords(array);
    console.log(`${records.mostPointsRecords()} ${records.leastPointsRecords()}`);
}

    function readIntArray(): number[] {
        return readLine().split(' ').map(Number);
    }

    class BreakingBestAndWorstRecords {
        private scores: number[];
        private breakingMostPointsRecords: number;
        private breakingLeastPointsRecords: number;

        public constructor(array: number[]) {
            this.scores = [...array];
            this.breakingMostPointsRecords = 0;
            this.breakingLeastPointsRecords = 0;
            this.breakingRecords();
        }

            private breakingRecords() {
                let mostPoints = this.scores[0];
                let leastPoints = this.scores[0];

                for (const score of this.scores)
                    if (score > mostPoints) {
                        mostPoints = score;
                        ++this.breakingMostPointsRecords;
                    } else if (score < leastPoints) {
                        leastPoints = score;
                        ++this.breakingLeastPointsRecords;
                    }
            }
        
        public mostPointsRecords(): number {
            return this.breakingMostPointsRecords;
        }

        public leastPointsRecords(): number {
            return this.breakingLeastPointsRecords;
        }
    }
