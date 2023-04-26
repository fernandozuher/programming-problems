// Source: https://www.hackerrank.com/challenges/acm-icpc-team/problem?isFullScreen=true

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
    const [ATTENDEES, _TOPICS] = readANumericArray();
    const BINARY_STRINGS = readBinaryStrings(ATTENDEES);

    const OBJ = new ACM_ICPC_TEAM(BINARY_STRINGS);
    console.log(`${OBJ.getMaximumSubjectsKnownByTeams()} \n${OBJ.getTeamsThatKnowMaximumSubjects()}`);
}

    function readANumericArray() {
        const ARRAY = readLine().split(" ").map(Number);
        return ARRAY;
    }

    function readBinaryStrings(nStrings) {
        const BINARY_STRINGS = new Array(nStrings).fill().map(_ => readLine());
        return BINARY_STRINGS;
    }

    class ACM_ICPC_TEAM {
        #binaryStrings;
        #maximumSubjectsKnownByTeams;
        #teamsThatKnowMaximumSubjects;

        constructor(binaryStrings) {
            this.#binaryStrings = binaryStrings;
            this.#maximumSubjectsKnownByTeams = 0;
            this.#teamsThatKnowMaximumSubjects = 0;

            this.#findMaximumSubjectsAndTeamsThatKnowThem();
        }

            #findMaximumSubjectsAndTeamsThatKnowThem() {
                for (let i = 0, size1 = this.#binaryStrings.length - 1; i < size1; i++) {
                    for (let j = i + 1, size2 = this.#binaryStrings.length; j < size2; j++) {
                        const SUBJECTS_KNOWN_BY_2_TEAMS = this.#countSubjectsKnownBy2Teams(this.#binaryStrings[i], this.#binaryStrings[j]);
                        this.#updateMaximumSubjectsAndTeamsThatKnowThem(SUBJECTS_KNOWN_BY_2_TEAMS);
                    }
                }
            }

                #countSubjectsKnownBy2Teams(binaryString1, binaryString2) {
                    let subjectsKnownBy2Teams = 0;

                    [...binaryString1].forEach((character_string_1, i) => {
                        let character_string_2 = binaryString2[i];
                        if (character_string_1 == "1" || character_string_2 == "1")
                            subjectsKnownBy2Teams++;
                    });

                    return subjectsKnownBy2Teams;
                }

                #updateMaximumSubjectsAndTeamsThatKnowThem(subjectsKnownBy2Teams) {
                    if (subjectsKnownBy2Teams > this.#maximumSubjectsKnownByTeams) {
                        this.#maximumSubjectsKnownByTeams = subjectsKnownBy2Teams;
                        this.#teamsThatKnowMaximumSubjects = 1;
                    }
                    else if (subjectsKnownBy2Teams == this.#maximumSubjectsKnownByTeams)
                        this.#teamsThatKnowMaximumSubjects++;
                }

        getMaximumSubjectsKnownByTeams() {
            return this.#maximumSubjectsKnownByTeams;
        }

        getTeamsThatKnowMaximumSubjects() {
            return this.#teamsThatKnowMaximumSubjects;
        }
    }
