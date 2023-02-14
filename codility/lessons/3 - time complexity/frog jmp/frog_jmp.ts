// Source: https://app.codility.com/programmers/lessons/3-time_complexity/frog_jmp/

function solution(currentPosition: number, destination: number, jumpDistance: number) {
    const numberOfJumps: number = (destination - currentPosition) / jumpDistance;
    const minimumNumberOfJumps: number = Math.ceil(numberOfJumps);
    return minimumNumberOfJumps;
}
