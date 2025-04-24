// https://www.hackerrank.com/challenges/30-nested-logic/problem?isFullScreen=true

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

//////////////////////////////////////////////////

function main() {
  const returnedDate: Date = readDate();
  const dueDate: Date = readDate();
  const fine =
    returnedDate <= dueDate ? 0 : new FineOnDelay(returnedDate, dueDate).fine;
  console.log(fine);
}

function readLine(): string {
  return inputLines[currentLine++];
}

function readDate(): Date {
  const [day, month, year] = readLine().split(' ').map(Number);
  return new Date(year, month - 1, day);
}

class FineOnDelay {
  private static FINE_PER_YEAR = 10000;
  private static FINE_PER_MONTH = 500;
  private static FINE_PER_DAY = 15;

  private readonly returnedDate: Date;
  private readonly dueDate: Date;
  private readonly fineValue: number;

  constructor(returnedDate: Date, dueDate: Date) {
    this.returnedDate = returnedDate;
    this.dueDate = dueDate;
    this.fineValue = this.calculateFine();
  }

  private calculateFine(): number {
    let fine: number = this.lateByYear();
    if (fine !== 0) return fine;

    fine = this.lateByMonth();
    if (fine !== 0) return fine;

    return this.lateByDay();
  }

  private lateByYear(): number {
    return this.returnedDate.getFullYear() > this.dueDate.getFullYear()
      ? FineOnDelay.FINE_PER_YEAR
      : 0;
  }

  private lateByMonth(): number {
    if (
      this.isSameYear() ||
      this.returnedDate.getMonth() > this.dueDate.getMonth()
    )
      return (
        (this.returnedDate.getMonth() - this.dueDate.getMonth()) *
        FineOnDelay.FINE_PER_MONTH
      );
    return 0;
  }

  private isSameYear(): boolean {
    return this.returnedDate.getFullYear() === this.dueDate.getFullYear();
  }

  private lateByDay(): number {
    if (
      this.isSameYear() &&
      this.isSameMonth() &&
      this.returnedDate.getDate() > this.dueDate.getDate()
    )
      return (
        (this.returnedDate.getDate() - this.dueDate.getDate()) *
        FineOnDelay.FINE_PER_DAY
      );
    return 0;
  }

  private isSameMonth(): boolean {
    return this.returnedDate.getMonth() === this.dueDate.getMonth();
  }

  get fine(): number {
    return this.fineValue;
  }
}
