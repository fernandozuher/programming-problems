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

    const OUTPUT: Array<number> = acmTeam(BINARY_STRINGS);
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

    function acmTeam(binaryStrings: Array<string>): Array<number> {
        let teamsThatKnowMaximumSubjects: number = 0;
        let maximumSubjectsKnownByTeams: number = 0;

        for (let i = 0, size1 = binaryStrings.length - 1; i < size1; i++) {
            for (let j = i + 1, size2 = binaryStrings.length; j < size2; j++) {

                const TEMPORARY_MAXIMUM_SUBJECTS_KNOWN_BY_TEAMS: number = calculateMaximumSubjectsKnownByTeam(binaryStrings[i], binaryStrings[j]);

                if (TEMPORARY_MAXIMUM_SUBJECTS_KNOWN_BY_TEAMS > maximumSubjectsKnownByTeams) {
                    maximumSubjectsKnownByTeams = TEMPORARY_MAXIMUM_SUBJECTS_KNOWN_BY_TEAMS;
                    teamsThatKnowMaximumSubjects = 1;
                }
                else if (TEMPORARY_MAXIMUM_SUBJECTS_KNOWN_BY_TEAMS == maximumSubjectsKnownByTeams)
                    teamsThatKnowMaximumSubjects++;
            }
        }

        const OUTPUT: Array<number> = [maximumSubjectsKnownByTeams, teamsThatKnowMaximumSubjects];
        return OUTPUT;
    }

        function calculateMaximumSubjectsKnownByTeam(binaryString1: string, binaryString2: string): number {
            let temporaryMaximumSubjectsKnownByTeams: number = 0;

            [...binaryString1].forEach((character_string_1, i) => {
                let character_string_2: string = binaryString2[i];
                if (character_string_1 == "1" || character_string_2 == "1")
                    temporaryMaximumSubjectsKnownByTeams++;
            });

            return temporaryMaximumSubjectsKnownByTeams;
        }

    function printArray(array: Array<number>) {
        array.forEach(element => console.log(element));
    }
