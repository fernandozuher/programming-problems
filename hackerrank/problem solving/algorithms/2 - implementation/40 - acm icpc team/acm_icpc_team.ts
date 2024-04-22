// https://www.hackerrank.com/challenges/acm-icpc-team/problem?isFullScreen=true

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
    let [attendees, topics]: number[] = readIntArray();
    let binary_strings: string[] = readBinaryStrings(attendees);
    let obj = new ACM_ICPC_TEAM(binary_strings);
    obj.findMaximumSubjectsAndTeamsThatKnowThem();
    console.log(`${obj.maximumSubjectsKnownByTeams()} \n${obj.teamsThatKnowMaximumSubjects()}`);
}

    function readIntArray(): number[] {
        return readLine().split(' ').map(Number);
    }

    function readBinaryStrings(n: number): string[] {
        return new Array(n).fill(null).map(_ => readLine());
    }

    class ACM_ICPC_TEAM {
        private binaryStrings: string[];
        private maxSubjectsKnownByTeams: number;
        private nTeamsThatKnowMaximumSubjects: number;

        public constructor(binaryStrings: string[]) {
            this.binaryStrings = binaryStrings;
            this.maxSubjectsKnownByTeams = 0;
            this.nTeamsThatKnowMaximumSubjects = 0;
        }

        public findMaximumSubjectsAndTeamsThatKnowThem() {
            for (const [i, previous] of this.binaryStrings.slice(0, -1).entries()) {
                for (const current of this.binaryStrings.slice(i + 1)) {
                    let subjectsKnownBy2Teams: number = this.countSubjectsKnownBy2Teams(previous, current);
                    this.updateMaximumSubjectsAndTeamsThatKnowThem(subjectsKnownBy2Teams);
                }
            }
        }

            private countSubjectsKnownBy2Teams(binaryString1: string, binaryString2: string): number {
                let subjectsKnownBy2Teams = 0;

                [...binaryString1].forEach((ch1, i) => {
                    let ch2: string = binaryString2[i];
                    if (ch1 == '1' || ch2 == '1')
                        ++subjectsKnownBy2Teams;
                });

                return subjectsKnownBy2Teams;
            }

            private updateMaximumSubjectsAndTeamsThatKnowThem(subjectsKnownBy2Teams: number) {
                if (subjectsKnownBy2Teams > this.maxSubjectsKnownByTeams) {
                    this.maxSubjectsKnownByTeams = subjectsKnownBy2Teams;
                    this.nTeamsThatKnowMaximumSubjects = 1;
                }
                else if (subjectsKnownBy2Teams == this.maxSubjectsKnownByTeams)
                    ++this.nTeamsThatKnowMaximumSubjects;
            }

        public maximumSubjectsKnownByTeams(): number {
            return this.maxSubjectsKnownByTeams;
        }

        public teamsThatKnowMaximumSubjects(): number {
            return this.nTeamsThatKnowMaximumSubjects;
        }
    }
