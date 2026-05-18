// https://www.hackerrank.com/challenges/time-conversion/problem?isFullScreen=true

function main() {
  const time = readLine();
  console.log(timeConversion(time));
}

// T: O(1)
// S: O(1) extra space
function timeConversion(time) {
  let convertedTime = time.substring(0, 8);
  const hour = time.substring(0, 2);
  const dayPeriod = time.substring(8, 9);

  if (hour === '12') {
    if (dayPeriod === 'A') {
      let midnight = '00';
      convertedTime = convertedTime.replace(hour, midnight);
    }
  } else if (dayPeriod === 'P') {
    let newHour = Number(hour);
    newHour += 12;
    convertedTime = convertedTime.replace(hour, newHour.toString());
  }

  return convertedTime;
}

////////////////////////////////////////////////

const readline = require('readline');

const rl = readline.createInterface({ input: process.stdin });
let inputLines = [];
rl.on('line', (line) => inputLines.push(line));
rl.on('close', main);

function readLine() {
  return inputLines.shift();
}
