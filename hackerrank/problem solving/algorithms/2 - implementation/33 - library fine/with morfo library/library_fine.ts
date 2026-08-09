// https://www.hackerrank.com/challenges/library-fine/problem?isFullScreen=true

import { read } from 'morfo';

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
  const day: number = read(Number);
  const month: number = read(Number);
  const year: number = read(Number);
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

main();
