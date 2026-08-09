// https://www.hackerrank.com/challenges/acm-icpc-team/problem?isFullScreen=true

import { println, read, skipInput } from 'morfo';

const n: number = read(Number);
skipInput();
const binaries: string[] = readBinaries(n);
println(acmTeam(binaries));

function readBinaries(n: number): string[] {
  return read(n, String);
}

function acmTeam(binaries: string[]): number[] {
  let maxSubjects = 0;
  let teamsWithMax = 0;

  for (let i = 0, n1 = binaries.length - 1; i < n1; i++) {
    for (let j = i + 1; j < binaries.length; j++) {
      const knownSubjects = countSubjectsKnownBy2Teams(
        binaries[i],
        binaries[j],
      );

      if (knownSubjects > maxSubjects) {
        maxSubjects = knownSubjects;
        teamsWithMax = 1;
      } else if (knownSubjects === maxSubjects) teamsWithMax++;
    }
  }

  return [maxSubjects, teamsWithMax];
}

function countSubjectsKnownBy2Teams(a: string, b: string): number {
  let count = 0;
  for (let i = 0; i < a.length; i++) {
    if (a[i] === '1' || b[i] === '1') count++;
  }
  return count;
}
