# Source: https://app.codility.com/programmers/lessons/3-time_complexity/frog_jmp/

import math

def solution(current_position, destination, jump_distance):

    return math.ceil((destination - current_position) / jump_distance)
