// https://www.hackerrank.com/challenges/jumping-on-the-clouds-revisited/problem?isFullScreen=true
// C++23

import morfo;
import std;
using namespace std;

int jumping_on_the_clouds(const vector<int>& clouds, int jump_length);

int main()
{
    morfo::skip_input();
    int jump_length = morfo::read();
    vector<int> arr = morfo::readln();
    println("{}", jumping_on_the_clouds(arr, jump_length));
    return 0;
}

// n: length of clouds; 2 to 25
// k (jump_length): 1 <= k <= n
// n % k = 0
// c[i] = 0 or 1
// T: O(n) = O(25) = O(1)
// S: O(1) extra space
int jumping_on_the_clouds(const vector<int>& clouds, int jump_length)
{
    int energy{ 100 };

    for (int cloud_index{};;) {
        energy -= clouds[cloud_index] ? 3 : 1;
        cloud_index = (cloud_index + jump_length) % clouds.size();
        if (!cloud_index)
            break;
    }

    return energy;
}
