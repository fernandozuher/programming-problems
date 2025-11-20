// https://www.hackerrank.com/challenges/jumping-on-the-clouds-revisited/problem?isFullScreen=true

#include <iostream>
#include <vector>

using namespace std;

vector<int> read_numbers(int n);
int jumping_on_the_clouds(const vector<int>& clouds, int jump_length);

int main()
{
    int n, jump_length;
    cin >> n >> jump_length;
    vector<int> arr{read_numbers(n)};
    cout << jumping_on_the_clouds(arr, jump_length) << '\n';
    return 0;
}

vector<int> read_numbers(int n)
{
    vector<int> arr(n);
    for (auto& x : arr)
        cin >> x;
    return arr;
}

int jumping_on_the_clouds(const vector<int>& clouds, int jump_length)
{
    int energy{100};
    int cloud_index{};

    do {
        energy -= clouds[cloud_index] == 0 ? 1 : 3;
        cloud_index = (cloud_index + jump_length) % clouds.size();
    } while (cloud_index != 0);

    return energy;
}
