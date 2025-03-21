// https://www.hackerrank.com/challenges/30-inheritance/problem?isFullScreen=true

'use strict';

process.stdin.resume();
process.stdin.setEncoding('utf-8');

let inputString: string = '';
let inputLines: string[] = [];
let currentLine: number = 0;

process.stdin.on('data', function (inputStdin: string): void {
  inputString += inputStdin;
});

process.stdin.on('end', function (): void {
  inputLines = inputString.split('\n');
  inputString = '';
  main();
});

function readLine(): string {
  return inputLines[currentLine++];
}

//////////////////////////////////////////////////

function main() {
  let [personalData, studentData] = readInput();
  let student = new Student(personalData, studentData);
  student.printPerson();
  console.log('Grade: ' + student.calculateGrade());
}

function readInput(): [PersonalData, StudentData] {
  let [firstName, lastName, id] = readLine().split(' ');
  readLine(); // Skip next line about size of scores
  let scores: number[] = readLine().split(' ').map(Number);
  return [{ firstName, lastName, id }, { scores }];
}

interface PersonalData {
  readonly firstName: string;
  readonly lastName: string;
  readonly id: string;
}

interface StudentData {
  readonly scores: number[];
}

class Person {
  private firstName: string;
  private lastName: string;
  private id: string;

  constructor(personalData: PersonalData) {
    this.firstName = personalData.firstName;
    this.lastName = personalData.lastName;
    this.id = personalData.id;
  }

  printPerson() {
    console.log(
      'Name: ' + this.lastName + ', ' + this.firstName + '\nID: ' + this.id,
    );
  }
}

class Student extends Person {
  private scores: number[];

  constructor(personalData: PersonalData, studentData: StudentData) {
    super(personalData);
    this.scores = studentData.scores;
  }

  public calculateGrade(): string {
    let sum: number = this.scores.reduce((a, b) => a + b, 0);
    let avg: number = sum / this.scores.length;

    if (avg > 100 || avg < 40) return 'T';
    else if (avg >= 90) return 'O';
    else if (avg >= 80) return 'E';
    else if (avg >= 70) return 'A';
    else if (avg >= 55) return 'P';
    return 'D';
  }
}
