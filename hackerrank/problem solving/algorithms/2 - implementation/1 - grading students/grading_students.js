'use strict';
const fs = require('fs');
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
/*
 * Complete the 'gradingStudents' function below.
 *
 * The function is expected to return an INTEGER_ARRAY.
 * The function accepts INTEGER_ARRAY grades as parameter.
 */
function isZeroRemainder(grade) {
    return grade % 5 === 0;
}

function gradingStudents(grades) {
    const N = grades.length;
    const newGrades = new Array(N);

    for (let i = 0, minGrade = 38; i < N; i++) {
    
        if (grades[i] < minGrade || isZeroRemainder(grades[i]))
            newGrades[i] = grades[i];
        else {
            const quocient = parseInt(grades[i] / 5);
            const nextMultiple5 = (quocient + 1) * 5;
            const difference = nextMultiple5 - grades[i];

            const result = difference < 3 ? nextMultiple5 : grades[i];
            newGrades[i] = result;
        }
    }
    return newGrades;
}

function main() {
    const ws = fs.createWriteStream(process.env.OUTPUT_PATH);
    const gradesCount = parseInt(readLine().trim(), 10);
    let grades = [];
    for (let i = 0; i < gradesCount; i++) {
        const gradesItem = parseInt(readLine().trim(), 10);
        grades.push(gradesItem);
    }
    const result = gradingStudents(grades);
    ws.write(result.join('\n') + '\n');
    ws.end();
}