// https://www.hackerrank.com/challenges/acm-icpc-team/problem?isFullScreen=true

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
    let [attendees, topics] = readIntArray();
    let binary_strings = readBinaryStrings(attendees);
    let obj = new ACM_ICPC_TEAM(binary_strings);
    obj.findMaximumSubjectsAndTeamsThatKnowThem();
    console.log(`${obj.maximumSubjectsKnownByTeams()} \n${obj.teamsThatKnowMaximumSubjects()}`);
}

    function readIntArray() {
        return readLine().split(' ').map(Number);
    }

    function readBinaryStrings(n) {
        return new Array(n).fill(null).map(_ => readLine());
    }

    class ACM_ICPC_TEAM {
        #binaryStrings;
        #maximumSubjectsKnownByTeams;
        #teamsThatKnowMaximumSubjects;

        constructor(binaryStrings) {
            this.#binaryStrings = binaryStrings;
            this.#maximumSubjectsKnownByTeams = 0;
            this.#teamsThatKnowMaximumSubjects = 0;
        }

        findMaximumSubjectsAndTeamsThatKnowThem() {
            for (const [i, previous] of this.#binaryStrings.slice(0, -1).entries()) {
                for (const current of this.#binaryStrings.slice(i + 1)) {
                    let subjectsKnownBy2Teams = this.#countSubjectsKnownBy2Teams(previous, current);
                    this.#updateMaximumSubjectsAndTeamsThatKnowThem(subjectsKnownBy2Teams);
                }
            }
        }

            #countSubjectsKnownBy2Teams(binaryString1, binaryString2) {
                let subjectsKnownBy2Teams = 0;

                [...binaryString1].forEach((ch1, i) => {
                    let ch2 = binaryString2[i];
                    if (ch1 == '1' || ch2 == '1')
                        ++subjectsKnownBy2Teams;
                });

                return subjectsKnownBy2Teams;
            }

            #updateMaximumSubjectsAndTeamsThatKnowThem(subjectsKnownBy2Teams) {
                if (subjectsKnownBy2Teams > this.#maximumSubjectsKnownByTeams) {
                    this.#maximumSubjectsKnownByTeams = subjectsKnownBy2Teams;
                    this.#teamsThatKnowMaximumSubjects = 1;
                }
                else if (subjectsKnownBy2Teams == this.#maximumSubjectsKnownByTeams)
                    ++this.#teamsThatKnowMaximumSubjects;
            }

        maximumSubjectsKnownByTeams() {
            return this.#maximumSubjectsKnownByTeams;
        }

        teamsThatKnowMaximumSubjects() {
            return this.#teamsThatKnowMaximumSubjects;
        }
    }
