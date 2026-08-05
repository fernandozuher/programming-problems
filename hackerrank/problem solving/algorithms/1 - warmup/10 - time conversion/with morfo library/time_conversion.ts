// https://www.hackerrank.com/challenges/time-conversion/problem?isFullScreen=true

import { read } from 'morfo';

const time: string = read(String);
console.log(to24HourTime(time));

// T: O(1)
// S: O(1) extra space
function to24HourTime(hour12: string): string {
  let hour24: string = hour12.substring(0, 8);
  const hour: string = hour12.substring(0, 2);
  const dayPeriod: string = hour12.substring(8, 9);

  if (
    (hour === '12' && dayPeriod === 'A') ||
    (hour !== '12' && dayPeriod === 'P')
  ) {
    const newHour: string = genNewHour(dayPeriod, hour);
    hour24 = hour24.replace(hour, newHour);
  }

  return hour24;
}

function genNewHour(dayPeriod: string, hour: string): string {
  if (dayPeriod === 'A') return '00';
  let newHour = +hour;
  newHour += 12;
  return newHour.toString();
}
