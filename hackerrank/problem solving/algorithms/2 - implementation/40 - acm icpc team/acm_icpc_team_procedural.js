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

    const OUTPUT = findMaximumSubjectsAndTeamsThatKnowThem(BINARY_STRINGS);
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

    function findMaximumSubjectsAndTeamsThatKnowThem(binaryStrings) {
        let maximumSubjectsKnownByTeams = 0;
        let teamsThatKnowMaximumSubjects = 0;

        for (let i = 0, size1 = binaryStrings.length - 1; i < size1; i++) {
            for (let j = i + 1, size2 = binaryStrings.length; j < size2; j++) {
                const SUBJECTS_KNOWN_BY_2_TEAMS = countSubjectsKnownBy2Teams(binaryStrings[i], binaryStrings[j]);
                [maximumSubjectsKnownByTeams, teamsThatKnowMaximumSubjects] = updateMaximumSubjectsAndTeamsThatKnowThem(SUBJECTS_KNOWN_BY_2_TEAMS, maximumSubjectsKnownByTeams, teamsThatKnowMaximumSubjects);
            }
        }

        const OUTPUT = [maximumSubjectsKnownByTeams, teamsThatKnowMaximumSubjects];
        return OUTPUT;
    }

        function countSubjectsKnownBy2Teams(binaryString1, binaryString2) {
            let subjectsKnownBy2Teams = 0;

            [...binaryString1].forEach((character_string_1, i) => {
                let character_string_2 = binaryString2[i];
                if (character_string_1 == "1" || character_string_2 == "1")
                    subjectsKnownBy2Teams++;
            });

            return subjectsKnownBy2Teams;
        }

        function updateMaximumSubjectsAndTeamsThatKnowThem(subjectsKnownBy2Teams, maximumSubjectsKnownByTeams, teamsThatKnowMaximumSubjects) {
            if (subjectsKnownBy2Teams > maximumSubjectsKnownByTeams) {
                maximumSubjectsKnownByTeams = subjectsKnownBy2Teams;
                teamsThatKnowMaximumSubjects = 1;
            }
            else if (subjectsKnownBy2Teams == maximumSubjectsKnownByTeams)
                teamsThatKnowMaximumSubjects++;

            return [maximumSubjectsKnownByTeams, teamsThatKnowMaximumSubjects];
        }

    function printArray(array) {
        array.forEach(element => console.log(element));
    }
