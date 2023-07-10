# Source: https://app.codility.com/programmers/lessons/3-time_complexity/frog_jmp/

def solution(current_position, destination, jump_distance)
    ((destination - current_position).to_f / jump_distance).ceil
end
