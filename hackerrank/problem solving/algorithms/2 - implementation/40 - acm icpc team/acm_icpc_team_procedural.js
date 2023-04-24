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

    const OUTPUT = acmTeam(BINARY_STRINGS);
    printArray(OUTPUT);
}

    function readANumericArray() {
        const ARRAY = readLine().split(" ").map(Number);
        return ARRAY;
    }

    function readBinaryStrings(nStrings) {
        const BINARY_STRINGS = new Array(nStrings).fill().map(_ => readLine());
        return BINARY_STRINGS;
    }

    function acmTeam(binaryStrings) {
        let teamsThatKnowMaximumSubjects = 0;
        let maximumSubjectsKnownByTeams = 0;

        for (let i = 0, size1 = binaryStrings.length - 1; i < size1; i++) {
            for (let j = i + 1, size2 = binaryStrings.length; j < size2; j++) {

                const TEMPORARY_MAXIMUM_SUBJECTS_KNOWN_BY_TEAMS = calculateMaximumSubjectsKnownByTeam(binaryStrings[i], binaryStrings[j]);

                if (TEMPORARY_MAXIMUM_SUBJECTS_KNOWN_BY_TEAMS > maximumSubjectsKnownByTeams) {
                    maximumSubjectsKnownByTeams = TEMPORARY_MAXIMUM_SUBJECTS_KNOWN_BY_TEAMS;
                    teamsThatKnowMaximumSubjects = 1;
                }
                else if (TEMPORARY_MAXIMUM_SUBJECTS_KNOWN_BY_TEAMS == maximumSubjectsKnownByTeams)
                    teamsThatKnowMaximumSubjects++;
            }
        }

        const OUTPUT = [maximumSubjectsKnownByTeams, teamsThatKnowMaximumSubjects];
        return OUTPUT;
    }

        function calculateMaximumSubjectsKnownByTeam(binaryString1, binaryString2) {
            let temporaryMaximumSubjectsKnownByTeams = 0;

            [...binaryString1].forEach((character_string_1, i) => {
                let character_string_2 = binaryString2[i];
                if (character_string_1 == "1" || character_string_2 == "1")
                    temporaryMaximumSubjectsKnownByTeams++;
            });

            return temporaryMaximumSubjectsKnownByTeams;
        }

    function printArray(array) {
        array.forEach(element => console.log(element));
    }
