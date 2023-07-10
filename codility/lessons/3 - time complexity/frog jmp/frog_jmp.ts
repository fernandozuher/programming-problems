// Source: https://app.codility.com/programmers/lessons/3-time_complexity/frog_jmp/

function solution(currentPosition: number, destination: number, jumpDistance: number): number {
    return Math.ceil((destination - currentPosition) / jumpDistance);
}
