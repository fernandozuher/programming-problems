// https://www.hackerrank.com/challenges/beautiful-days-at-the-movies/problem?isFullScreen=true

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
  const [startDay, endDay, divisor]: number[] = readNumbers();
  console.log(beautifulDays(startDay, endDay, divisor));
}

function readNumbers(): number[] {
  return readLine().split(' ').map(Number);
}

// n: range (endDay - startDay + 1)
// d: number of digits of the largest day
// T: O(n * d)
// S: O(d) extra space
function beautifulDays(
  startDay: number,
  endDay: number,
  divisor: number,
): number {
  let count = 0;
  for (let day = startDay; day <= endDay; day++)
    if (isDayBeautiful(day, divisor)) count++;
  return count;
}

function isDayBeautiful(day: number, divisor: number): boolean {
  return (day - reverseNumber(day)) % divisor === 0;
}

function reverseNumber(number: number): number {
  return +String(number).split('').reverse().join('');
}
