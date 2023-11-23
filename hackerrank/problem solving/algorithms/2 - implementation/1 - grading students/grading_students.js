// https://www.hackerrank.com/challenges/grading/problem?isFullScreen=true

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

function main() {
    let n = +readLine();
    let array = readIntArray(n);
    printArray(gradingStudents(array));
}

    function readIntArray(n) {
        return Array(n).fill(0).map(_ => +readLine());
    }

    function gradingStudents(grades) {
        let newGrades = Array(grades.length).fill(0);

        for (let i = 0, minGrade = 38; i < grades.length; ++i) {

            if (grades[i] < minGrade || isZeroRemainder(grades[i])) newGrades[i] = grades[i];
            else {
                let quocient = Math.floor((grades[i] / 5));
                let nextMultiple5 = (quocient + 1) * 5;
                let difference = nextMultiple5 - grades[i];
                let result = difference < 3 ? nextMultiple5 : grades[i];
                newGrades[i] = result;
            }
        }

        return newGrades;
    }

        function isZeroRemainder(grade) {
            return grade % 5 === 0;
        }

    function printArray(array) {
        array.forEach(x => console.log(x));
    }
