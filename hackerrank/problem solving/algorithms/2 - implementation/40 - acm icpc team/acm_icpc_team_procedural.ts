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

    const OUTPUT: Array<number> = findMaximumSubjectsAndTeamsThatKnowThem(BINARY_STRINGS);
    printArray(OUTPUT);
}

    function readANumericArray(): Array<number> {
        const ARRAY: Array<number> = readLine().split(" ").map(Number);
        return ARRAY;
    }

    function readBinaryStrings(nStrings: number): Array<string> {
        const BINARY_STRINGS: Array<string> = new Array(nStrings).fill("").map(_ => readLine());
        return BINARY_STRINGS;
    }

    function findMaximumSubjectsAndTeamsThatKnowThem(binaryStrings: Array<string>): Array<number> {
        let maximumSubjectsKnownByTeams: number = 0;
        let teamsThatKnowMaximumSubjects: number = 0;

        for (let i = 0, size1 = binaryStrings.length - 1; i < size1; i++) {
            for (let j = i + 1, size2 = binaryStrings.length; j < size2; j++) {
                const SUBJECTS_KNOWN_BY_2_TEAMS: number = countSubjectsKnownBy2Teams(binaryStrings[i], binaryStrings[j]);
                [maximumSubjectsKnownByTeams, teamsThatKnowMaximumSubjects] = updateMaximumSubjectsAndTeamsThatKnowThem(SUBJECTS_KNOWN_BY_2_TEAMS, maximumSubjectsKnownByTeams, teamsThatKnowMaximumSubjects);
            }
        }

        const OUTPUT: Array<number> = [maximumSubjectsKnownByTeams, teamsThatKnowMaximumSubjects];
        return OUTPUT;
    }

        function countSubjectsKnownBy2Teams(binaryString1: string, binaryString2: string): number {
            let subjectsKnownBy2Teams: number = 0;

            [...binaryString1].forEach((character_string_1, i) => {
                let character_string_2: string = binaryString2[i];
                if (character_string_1 == "1" || character_string_2 == "1")
                    subjectsKnownBy2Teams++;
            });

            return subjectsKnownBy2Teams;
        }

        function updateMaximumSubjectsAndTeamsThatKnowThem(subjectsKnownBy2Teams: number, maximumSubjectsKnownByTeams: number, teamsThatKnowMaximumSubjects: number): Array<number> {
            if (subjectsKnownBy2Teams > maximumSubjectsKnownByTeams) {
                maximumSubjectsKnownByTeams = subjectsKnownBy2Teams;
                teamsThatKnowMaximumSubjects = 1;
            }
            else if (subjectsKnownBy2Teams == maximumSubjectsKnownByTeams)
                teamsThatKnowMaximumSubjects++;

            return [maximumSubjectsKnownByTeams, teamsThatKnowMaximumSubjects];
        }

    function printArray(array: Array<number>) {
        array.forEach(element => console.log(element));
    }
