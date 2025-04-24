// https://www.hackerrank.com/challenges/30-nested-logic/problem?isFullScreen=true

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

//////////////////////////////////////////////////

function main() {
  const returnedDate = readDate();
  const dueDate = readDate();
  const fine =
    returnedDate <= dueDate ? 0 : new FineOnDelay(returnedDate, dueDate).fine;
  console.log(fine);
}

function readLine() {
  return inputLines[currentLine++];
}

function readDate() {
  const [day, month, year] = readLine().split(' ').map(Number);
  return new Date(year, month - 1, day);
}

class FineOnDelay {
  static #FINE_PER_YEAR = 10000;
  static #FINE_PER_MONTH = 500;
  static #FINE_PER_DAY = 15;

  #returnedDate;
  #dueDate;
  #fine;

  constructor(returnedDate, dueDate) {
    this.#returnedDate = returnedDate;
    this.#dueDate = dueDate;
    this.#fine = this.#calculateFine();
  }

  #calculateFine() {
    let fine = this.#lateByYear();
    if (fine !== 0) return fine;

    fine = this.#lateByMonth();
    if (fine !== 0) return fine;

    return this.#lateByDay();
  }

  #lateByYear() {
    if (this.#returnedDate.getFullYear() > this.#dueDate.getFullYear())
      return FineOnDelay.#FINE_PER_YEAR;
    return 0;
  }

  #lateByMonth() {
    if (
      this.#isSameYear() &&
      this.#returnedDate.getMonth() > this.#dueDate.getMonth()
    )
      return (
        (this.#returnedDate.getMonth() - this.#dueDate.getMonth()) *
        FineOnDelay.#FINE_PER_MONTH
      );
    return 0;
  }

  #isSameYear() {
    return this.#returnedDate.getFullYear() === this.#dueDate.getFullYear();
  }

  #lateByDay() {
    if (
      this.#isSameYear() &&
      this.#isSameMonth() &&
      this.#returnedDate.getDate() > this.#dueDate.getDate()
    )
      return (
        (this.#returnedDate.getDate() - this.#dueDate.getDate()) *
        FineOnDelay.#FINE_PER_DAY
      );
    return 0;
  }

  #isSameMonth() {
    return this.#returnedDate.getMonth() === this.#dueDate.getMonth();
  }

  get fine() {
    return this.#fine;
  }
}
