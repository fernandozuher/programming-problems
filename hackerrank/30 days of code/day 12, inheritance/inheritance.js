// https://www.hackerrank.com/challenges/30-inheritance/problem?isFullScreen=true

'use strict';
process.stdin.resume();
process.stdin.setEncoding('utf-8');

let inputString = '';
let inputLines = [];
let currentLine = 0;

process.stdin.on('data', function (inputStdin) {
  inputString += inputStdin;
});

process.stdin.on('end', function () {
  inputLines = inputString.split('\n');
  inputString = '';
  main();
});

function readLine() {
  return inputLines[currentLine++];
}

//////////////////////////////////////////////////

function main() {
  let [personalData, studentData] = readInput();
  let student = new Student(personalData, studentData);
  student.printPerson();
  console.log('Grade: ' + student.calculateGrade());
}

function readInput() {
  let [firstName, lastName, id] = readLine().split(' ');
  readLine(); // Skip next line about size of scores
  let scores = readLine().split(' ').map(Number);
  return [new PersonalData(firstName, lastName, id), new StudentData(scores)];
}

class PersonalData {
  constructor(firstName, lastName, id) {
    this.firstName = firstName;
    this.lastName = lastName;
    this.id = id;
    Object.freeze(this);
  }
}

class StudentData {
  constructor(scores) {
    this.scores = scores;
    Object.freeze(this);
  }
}

class Person {
  #firstName;
  #lastName;
  #id;

  constructor(personalData) {
    this.#firstName = personalData.firstName;
    this.#lastName = personalData.lastName;
    this.#id = personalData.id;
  }

  printPerson() {
    console.log(
      'Name: ' + this.#lastName + ', ' + this.#firstName + '\nID: ' + this.#id,
    );
  }
}

class Student extends Person {
  #scores;

  constructor(personalData, studentData) {
    super(personalData);
    this.#scores = studentData.scores;
  }

  calculateGrade() {
    let sum = this.#scores.reduce((a, b) => a + b, 0);
    let avg = sum / this.#scores.length;

    if (avg > 100 || avg < 40) return 'T';
    else if (avg >= 90) return 'O';
    else if (avg >= 80) return 'E';
    else if (avg >= 70) return 'A';
    else if (avg >= 55) return 'P';
    return 'D';
  }
}
