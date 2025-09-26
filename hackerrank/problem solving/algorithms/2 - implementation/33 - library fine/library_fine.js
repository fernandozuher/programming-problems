// https://www.hackerrank.com/challenges/library-fine/problem?isFullScreen=true

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

const HackosFine = Object.freeze({
  DaysFine: 15,
  MonthsFine: 500,
  YearsFine: 10000,
});

class DateThatWorks {
  #day;
  #month;
  #year;

  constructor(day, month, year) {
    this.#day = day;
    this.#month = month;
    this.#year = year;
  }

  day() {
    return this.#day;
  }

  month() {
    return this.#month;
  }

  year() {
    return this.#year;
  }
}

function main() {
  const returnDate = readDate();
  const dueDate = readDate();
  console.log(calculateFine(returnDate, dueDate));
}

function readDate() {
  const [day, month, year] = readLine().split(' ').map(Number);
  return new DateThatWorks(day, month, year);
}

function calculateFine(returnDate, dueDate) {
  if (returnedOnTime(returnDate, dueDate)) return 0;
  if (returnDate.year() > dueDate.year()) return HackosFine.YearsFine;
  if (returnDate.month() > dueDate.month())
    return (returnDate.month() - dueDate.month()) * HackosFine.MonthsFine;
  return (returnDate.day() - dueDate.day()) * HackosFine.DaysFine;
}

function returnedOnTime(returnDate, dueDate) {
  return (
    returnDate.year() < dueDate.year() ||
    (returnDate.year() === dueDate.year() &&
      returnDate.month() < dueDate.month()) ||
    (returnDate.year() === dueDate.year() &&
      returnDate.month() === dueDate.month() &&
      returnDate.day() <= dueDate.day())
  );
}
