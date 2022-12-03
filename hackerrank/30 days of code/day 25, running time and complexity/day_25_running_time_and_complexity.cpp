#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int n;
    cin >> n;

    for (int number; n-- && cin >> number; ) {
        if (number == 1) {
            cout << "Not prime\n";
            continue;
        }

        int i {2}, limit = static_cast<int>(sqrt(number));
        for (; i <= limit; ++i)
            if (!(number % i)) {
                cout << "Not prime\n";
                break;
            }

        if (i > limit)
            cout << "Prime\n";
    }
    return 0;
}
