# Source: https://app.codility.com/programmers/lessons/3-time_complexity/frog_jmp/

def solution(currentPosition, destination, jumpDistance)
    numberOfJumps = (destination - currentPosition).to_f / jumpDistance
    minimumNumberOfJumps = numberOfJumps.ceil
end
