// Source: https://www.hackerrank.com/challenges/acm-icpc-team/problem?isFullScreen=true

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
    const [ATTENDEES, _TOPICS]: Array<number> = readANumericArray();
    const BINARY_STRINGS: Array<string> = readBinaryStrings(ATTENDEES);

    const OBJ: ACM_ICPC_TEAM = new ACM_ICPC_TEAM(BINARY_STRINGS);
    console.log(`${OBJ.getMaximumSubjectsKnownByTeams()} \n${OBJ.getTeamsThatKnowMaximumSubjects()}`);
}

    function readANumericArray(): Array<number> {
        const ARRAY: Array<number> = readLine().split(" ").map(Number);
        return ARRAY;
    }

    function readBinaryStrings(nStrings: number): Array<string> {
        const BINARY_STRINGS: Array<string> = new Array(nStrings).fill("").map(_ => readLine());
        return BINARY_STRINGS;
    }

    class ACM_ICPC_TEAM {
        _binaryStrings;
        _maximumSubjectsKnownByTeams;
        _teamsThatKnowMaximumSubjects;

        constructor(binaryStrings: Array<string>) {
            this._binaryStrings = binaryStrings;
            this._maximumSubjectsKnownByTeams = 0;
            this._teamsThatKnowMaximumSubjects = 0;

            this._findMaximumSubjectsAndTeamsThatKnowThem();
        }

            private _findMaximumSubjectsAndTeamsThatKnowThem() {
                for (let i = 0, size1 = this._binaryStrings.length - 1; i < size1; i++) {
                    for (let j = i + 1, size2 = this._binaryStrings.length; j < size2; j++) {
                        const SUBJECTS_KNOWN_BY_2_TEAMS: number = this._countSubjectsKnownBy2Teams(this._binaryStrings[i], this._binaryStrings[j]);
                        this._updateMaximumSubjectsAndTeamsThatKnowThem(SUBJECTS_KNOWN_BY_2_TEAMS);
                    }
                }
            }

                private _countSubjectsKnownBy2Teams(binaryString1: string, binaryString2: string): number {
                    let subjectsKnownBy2Teams: number = 0;

                    [...binaryString1].forEach((character_string_1, i) => {
                        let character_string_2: string = binaryString2[i];
                        if (character_string_1 == "1" || character_string_2 == "1")
                            subjectsKnownBy2Teams++;
                    });

                    return subjectsKnownBy2Teams;
                }

                private _updateMaximumSubjectsAndTeamsThatKnowThem(subjectsKnownBy2Teams: number) {
                    if (subjectsKnownBy2Teams > this._maximumSubjectsKnownByTeams) {
                        this._maximumSubjectsKnownByTeams = subjectsKnownBy2Teams;
                        this._teamsThatKnowMaximumSubjects = 1;
                    }
                    else if (subjectsKnownBy2Teams == this._maximumSubjectsKnownByTeams)
                        this._teamsThatKnowMaximumSubjects++;
                }

        public getMaximumSubjectsKnownByTeams() {
            return this._maximumSubjectsKnownByTeams;
        }

        public getTeamsThatKnowMaximumSubjects() {
            return this._teamsThatKnowMaximumSubjects;
        }
    }
