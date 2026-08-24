// https://www.hackerrank.com/challenges/grading/problem?isFullScreen=true

import { idiv, println, read } from 'morfo';

const n = read(Number);
const grades = read(n, Number);
println(gradingStudents(grades));

// n: length of grades
// T: O(n)
// S: O(1) extra space
function gradingStudents(grades) {
  for (let i = 0, minGrade = 38; i < grades.length; i++) {
    if (grades[i] < minGrade) continue;
    const nextMultiple5 = (idiv(grades[i], 5) + 1) * 5;
    if (nextMultiple5 - grades[i] < 3) grades[i] = nextMultiple5;
  }
  return grades;
}
