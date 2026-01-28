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

// T: O(1)
// S: O(1) extra space
function calculateFine(returnDate, dueDate) {
  if (isYearLate(returnDate, dueDate)) return HackosFine.YearsFine;
  if (isMonthLate(returnDate, dueDate))
    return (returnDate.month() - dueDate.month()) * HackosFine.MonthsFine;
  if (isDayLate(returnDate, dueDate))
    return (returnDate.day() - dueDate.day()) * HackosFine.DaysFine;
  return 0;
}

function isYearLate(returnDate, dueDate) {
  return returnDate.year() > dueDate.year();
}

function isMonthLate(returnDate, dueDate) {
  return (
    returnDate.year() === dueDate.year() && returnDate.month() > dueDate.month()
  );
}

function isDayLate(returnDate, dueDate) {
  return (
    returnDate.year() === dueDate.year() &&
    returnDate.month() === dueDate.month() &&
    returnDate.day() > dueDate.day()
  );
}
