// https://www.hackerrank.com/challenges/simple-array-sum/problem?isFullScreen=true
// C++23

import std;
using namespace std;

template<class T>
concept Readable = requires(istream& is, T& value) { is >> value; };

template<Readable T>
T read_as()
{
    if (T x; cin >> x)
        return x;
    throw invalid_argument("Failed to read value.");
}

struct read {
    template<Readable T>
    operator T() const {
        return read_as<T>();
    }
};

// T: O(n)
// S: O(1) extra space
int sum_stdin(int n)
{
    auto x = views::iota(0, n) | views::transform([](...) { return read_as<int>(); });
    return *ranges::fold_left_first(x, plus{});
}

int main()
{
    int n{ read() };
    cout << sum_stdin(n);
    return 0;
}
