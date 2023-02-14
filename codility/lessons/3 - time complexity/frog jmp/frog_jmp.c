  // Source: https://app.codility.com/programmers/lessons/3-time_complexity/frog_jmp/

  #include <math.h>

  int solution(const int current_position, const int destination, const int jump_distance) {
    const float number_of_jumps = (float)(destination - current_position) / jump_distance;
    const int minimum_number_of_jumps = ceil(number_of_jumps);
    return minimum_number_of_jumps;
  }