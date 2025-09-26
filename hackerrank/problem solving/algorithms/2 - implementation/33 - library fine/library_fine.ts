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

type DateTriple = { day: number; month: number; year: number };

const HackosFine = Object.freeze({
  DaysFine: 15,
  MonthsFine: 500,
  YearsFine: 10000,
});

function main() {
  const returnDate: DateTriple = readDate();
  const dueDate: DateTriple = readDate();
  console.log(calculateFine(returnDate, dueDate));
}

function readDate(): DateTriple {
  const [day, month, year]: number[] = readLine().split(' ').map(Number);
  return { day, month, year };
}

function calculateFine(returnDate: DateTriple, dueDate: DateTriple) {
  if (returnedOnTime(returnDate, dueDate)) return 0;
  if (returnDate.year > dueDate.year) return HackosFine.YearsFine;
  if (returnDate.month > dueDate.month)
    return (returnDate.month - dueDate.month) * HackosFine.MonthsFine;
  return (returnDate.day - dueDate.day) * HackosFine.DaysFine;
}

function returnedOnTime(returnDate: DateTriple, dueDate: DateTriple): boolean {
  return (
    returnDate.year < dueDate.year ||
    (returnDate.year === dueDate.year && returnDate.month < dueDate.month) ||
    (returnDate.year === dueDate.year &&
      returnDate.month === dueDate.month &&
      returnDate.day <= dueDate.day)
  );
}
