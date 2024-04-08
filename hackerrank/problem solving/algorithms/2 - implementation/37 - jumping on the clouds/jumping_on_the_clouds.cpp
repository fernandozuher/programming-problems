// https://www.hackerrank.com/challenges/jumping-on-the-clouds/problem?isFullScreen=true

import <algorithm>;
import <iostream>;
import <vector>;

using namespace std;

int minimum_number_of_jumps(const vector<int>& clouds);
    int next_jump(int index, const vector<int>& clouds);

int main()
{
    int n;
    cin >> n;
    vector<int> clouds(n);
    ranges::generate(clouds, []{int x; cin >> x; return x;});
    cout << minimum_number_of_jumps(clouds);

    return 0;
}

    int minimum_number_of_jumps(const vector<int>& clouds)
    {
        int jumps {};
        for (int i{}, n = clouds.size() - 1; i < n; ++jumps)
            i += next_jump(i, clouds);
        return jumps;
    }

        int next_jump(int index, const vector<int>& clouds)
        {
            if (index + 2 < clouds.size())
                if (bool is_next_second_cloud_cumulus = clouds[index + 2] == 0)
                    return 2;
            return 1;
        }
