// From C++23

#include <bitset>
#include <iostream>
#include <print>
#include <ranges>
#include <tuple>

using namespace std;

pair<int, int> next_number(int n);
int next_smallest_number(int n, int i);
int next_largest_number(int n, int i);

bool get_bit(int n, int i);
int clear_bit(int n, int i);
int set_bit(int n, int i);

void next_smallest_largest(const tuple<int, int, int>& numbers);
void next_largest(const tuple<int, int, int>& numbers);
void next_smallest(const tuple<int, int, int>& numbers);
void neither_smallest_nor_largest(const tuple<int, int, int>& numbers);

int main()
{
    println("X (smallest), Y (number), Z (largest)\n");
    for (const auto i : views::iota(1, 101)) {
        const auto [smallest, largest]{next_number(i)};
        const auto numbers{tuple{smallest, i, largest}};

        if (smallest != -1 && largest != -1)
            next_smallest_largest(numbers);
        else if (smallest == -1)
            next_largest(numbers);
        else if (largest == -1)
            next_smallest(numbers);
        else
            neither_smallest_nor_largest(numbers);
    }
    return 0;
}

pair<int, int> next_number(const int n)
{
    int smallest_i{-1}, largest_i{-1};
    constexpr auto n_bits{sizeof(n) * 8};
    constexpr auto last_bit_to_check{n_bits - 2};

    for (int i{}; i < last_bit_to_check && (smallest_i == -1 || largest_i == -1); ++i) {
        if (smallest_i == -1 && !get_bit(n, i) && get_bit(n, i + 1))
            smallest_i = i;
        else if (largest_i == -1 && get_bit(n, i) && !get_bit(n, i + 1))
            largest_i = i;
    }

    int smallest_n{-1}, largest_n{-1};
    if (smallest_i != -1)
        smallest_n = next_smallest_number(n, smallest_i);
    if (largest_i != -1)
        largest_n = next_largest_number(n, largest_i);

    return {smallest_n, largest_n};
}

int next_smallest_number(const int n, const int i)
{
    int next_smallest_number{n};
    next_smallest_number = clear_bit(next_smallest_number, i + 1);
    next_smallest_number = set_bit(next_smallest_number, i);
    return next_smallest_number;
}

int next_largest_number(const int n, const int i)
{
    int next_largest_number{n};
    next_largest_number = clear_bit(next_largest_number, i);
    next_largest_number = set_bit(next_largest_number, i + 1);
    return next_largest_number;
}

bool get_bit(const int n, const int i)
{
    return (n & 1 << i) != 0;
}

int clear_bit(const int n, const int i)
{
    return n & ~(1 << i);
}

int set_bit(const int n, const int i)
{
    return n | 1 << i;
}

void next_smallest_largest(const tuple<int, int, int>& numbers)
{
    const auto [smallest, n, largest]{numbers};
    println("{}, {}, {}", smallest, n, largest);
    constexpr auto n_bits{sizeof(n) * 8};

    cout << bitset<n_bits>(smallest) << '\n';
    cout << bitset<n_bits>(n) << '\n';
    cout << bitset<n_bits>(largest) << "\n\n";
}

void next_largest(const tuple<int, int, int>& numbers)
{
    const auto [smallest, n, largest]{numbers};
    println("no next smallest, {}, {}", n, largest);
    constexpr auto n_bits{sizeof(n) * 8};

    println("X");
    cout << bitset<n_bits>(n) << '\n';
    cout << bitset<n_bits>(largest) << "\n\n";
}

void next_smallest(const tuple<int, int, int>& numbers)
{
    const auto [smallest, n, largest]{numbers};
    println("{}, {}, no next largest, otherwise it overflows", smallest, n);
    constexpr auto n_bits{sizeof(n) * 8};

    cout << bitset<n_bits>(smallest) << '\n';
    cout << bitset<n_bits>(n) << '\n';
    println("X\n");
}

void neither_smallest_nor_largest(const tuple<int, int, int>& numbers)
{
    const auto [smallest, n, largest]{numbers};
    println("no next smallest, {}, no next largest", n);
    constexpr auto n_bits{sizeof(n) * 8};

    println("X");
    cout << bitset<n_bits>(n) << '\n';
    println("X\n");
}
