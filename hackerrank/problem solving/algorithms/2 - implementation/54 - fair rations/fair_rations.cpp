// https://www.hackerrank.com/challenges/fair-rations/problem?isFullScreen=true

#include <iostream>

using namespace std;

int find_min_loaves_to_satisfy_rules(int n);
    bool is_odd(int n);

int main()
{
    int n;
    cin >> n;
    if (int min_loaves {find_min_loaves_to_satisfy_rules(n)}; min_loaves == -1)
        cout << "NO";
    else
        cout << min_loaves;

    return 0;
}

    int find_min_loaves_to_satisfy_rules(int n)
    {
        int min_loaves_to_satisfy_rules{};
        int loaves;
        cin >> loaves;

        while (--n)
            if (is_odd(loaves)) {
                cin >> loaves;
                ++loaves;
                min_loaves_to_satisfy_rules += 2;
            } else
                cin >> loaves;

        return is_odd(loaves) ? -1 : min_loaves_to_satisfy_rules;
    }

        bool is_odd(const int n)
        {
            return n & 1;
        }
