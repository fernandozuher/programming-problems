# Source: https://app.codility.com/programmers/lessons/3-time_complexity/frog_jmp/

import math

def solution(currentPosition, destination, jumpDistance):
    numberOfJumps = (destination - currentPosition) / jumpDistance
    minimumNumberOfJumps = int(math.ceil(numberOfJumps))
    return minimumNumberOfJumps
