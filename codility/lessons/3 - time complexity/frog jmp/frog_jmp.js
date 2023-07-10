// Source: https://app.codility.com/programmers/lessons/3-time_complexity/frog_jmp/

function solution(currentPosition, destination, jumpDistance) {
    return Math.ceil((destination - currentPosition) / jumpDistance);
}
