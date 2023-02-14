// Source: https://app.codility.com/programmers/lessons/3-time_complexity/frog_jmp/

function solution(currentPosition, destination, jumpDistance) {
    const numberOfJumps = (destination - currentPosition) / jumpDistance;
    const minimumNumberOfJumps = Math.ceil(numberOfJumps);
    return minimumNumberOfJumps;
}
