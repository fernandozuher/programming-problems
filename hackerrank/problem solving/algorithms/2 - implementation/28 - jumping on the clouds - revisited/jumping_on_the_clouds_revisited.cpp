// https://www.hackerrank.com/challenges/jumping-on-the-clouds-revisited/problem?isFullScreen=true
// C++23

import std;
using namespace std;

vector<int> read_numbers(int n);
int jumping_on_the_clouds(const vector<int>& clouds, int jump_length);

int main()
{
    int n, jump_length;
    cin >> n >> jump_length;
    vector<int> arr{ read_numbers(n) };
    println("{}", jumping_on_the_clouds(arr, jump_length));
    return 0;
}

vector<int> read_numbers(int n)
{
    vector<int> arr(n);
    for (auto& x : arr)
        cin >> x;
    return arr;
}

// n: length of array clouds; 2 to 25
// k (jump_length): 1 <= k <= n
// n % k = 0
// c[i] = 0 or 1
// T: O(n) = O(25) = O(1)
// S: O(1) extra space
int jumping_on_the_clouds(const vector<int>& clouds, int jump_length)
{
    int energy{ 100 };
    int cloud_index{};

    do {
        energy -= clouds[cloud_index] ? 3 : 1;
        cloud_index = (cloud_index + jump_length) % clouds.size();
    } while (cloud_index);

    return energy;
}
