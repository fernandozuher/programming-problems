#include <print>

using namespace std;

int insert_m_into_n(int m, int n, int i, int j);

int main()
{
    constexpr int m{19}, n{1024}, i{2}, j{6};
    println("Insert {} into {} in range [{}..{}] = {}", m, n, i, j, insert_m_into_n(m, n, i, j));
    return 0;
}

int insert_m_into_n(const int m, const int n, const int i, const int j)
{
    auto ones_before_i{~(-1 << i)};
    auto ones_until_j{~(-1 << j + 1)};
    auto mask{ones_before_i ^ ones_until_j};

    mask = ~mask;
    auto shifted_m{m << i};

    return n & mask | shifted_m;
}
