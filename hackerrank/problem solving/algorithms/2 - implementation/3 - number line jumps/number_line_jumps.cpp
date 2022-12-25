// Source: https://www.hackerrank.com/challenges/kangaroo/problem?isFullScreen=true

#include <bits/stdc++.h>

using namespace std;

/*
 * Complete the 'kangaroo' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts following parameters:
 *  1. INTEGER x1
 *  2. INTEGER v1
 *  3. INTEGER x2
 *  4. INTEGER v2
 */

string kangaroo(int x1, int v1, int x2, int v2) {
    if (v2 >= v1)
        return "NO";
    for (; x1 < x2; x1 += v1, x2 += v2);
    return x1 == x2 ? "YES" : "NO";
}

int main() {
    ofstream fout(getenv("OUTPUT_PATH"));
    
    vector<int> numbers(4);
    for (int i {0}; i < 4; cin >> numbers.at(i++));

    int x1 = numbers.at(0);
    int v1 = numbers.at(1);
    int x2 = numbers.at(2);
    int v2 = numbers.at(3);

    string result = kangaroo(x1, v1, x2, v2);
    fout << result << "\n";

    fout.close();

    return 0;
}
