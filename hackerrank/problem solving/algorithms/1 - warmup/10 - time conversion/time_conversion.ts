// https://www.hackerrank.com/challenges/time-conversion/problem?isFullScreen=true

function main() {
  const time: string = readLine();
  console.log(timeConversion(time));
}

// T: O(1)
// S: O(1) extra space
function timeConversion(time: string): string {
  let convertedTime: string = time.substring(0, 8);
  const hour: string = time.substring(0, 2);
  const dayPeriod: string = time.substring(8, 9);

  if (hour === '12') {
    if (dayPeriod === 'A') {
      let midnight: string = '00';
      convertedTime = convertedTime.replace(hour, midnight);
    }
  } else if (dayPeriod === 'P') {
    let newHour: number = Number(hour);
    newHour += 12;
    convertedTime = convertedTime.replace(hour, newHour.toString());
  }

  return convertedTime;
}

//////////////////////////////////////////////////

import readline = require('readline');

const rl = readline.createInterface({ input: process.stdin });
let inputLines: string[] = [];
rl.on('line', (line: string) => inputLines.push(line));
rl.on('close', main);

function readLine(): string {
  return inputLines.shift()!;
}
