// https://www.hackerrank.com/challenges/library-fine/problem?isFullScreen=true

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

const HackosFine = Object.freeze({
  DaysFine: 15,
  MonthsFine: 500,
  YearsFine: 10000,
});

type DateTriple = { day: number; month: number; year: number };

function main() {
  const returnDate: DateTriple = readDate();
  const dueDate: DateTriple = readDate();
  console.log(calculateFine(returnDate, dueDate));
}

function readDate(): DateTriple {
  const [day, month, year]: number[] = readLine().split(' ').map(Number);
  return { day, month, year };
}

// T: O(1)
// S: O(1) extra space
function calculateFine(returnDate: DateTriple, dueDate: DateTriple): number {
  if (isYearLate(returnDate, dueDate)) return HackosFine.YearsFine;
  if (isMonthLate(returnDate, dueDate))
    return (returnDate.month - dueDate.month) * HackosFine.MonthsFine;
  if (isDayLate(returnDate, dueDate))
    return (returnDate.day - dueDate.day) * HackosFine.DaysFine;
  return 0;
}

function isYearLate(returnDate: DateTriple, dueDate: DateTriple): boolean {
  return returnDate.year > dueDate.year;
}

function isMonthLate(returnDate: DateTriple, dueDate: DateTriple): boolean {
  return returnDate.year === dueDate.year && returnDate.month > dueDate.month;
}

function isDayLate(returnDate: DateTriple, dueDate: DateTriple): boolean {
  return (
    returnDate.year === dueDate.year &&
    returnDate.month === dueDate.month &&
    returnDate.day > dueDate.day
  );
}
