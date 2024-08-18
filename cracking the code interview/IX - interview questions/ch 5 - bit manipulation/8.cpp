// From C++23

// Position start from 0, top left.
// Right, horizontal -> x's
// Down, vertical -> y's

#include <algorithm>
#include <bitset>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <print>
#include <ranges>
#include <vector>

using namespace std;

constexpr int n_bits{8};

void draw_line(vector<bitset<n_bits>>& screen, int width, int x1, int x2, int y);
void print_screen(const vector<bitset<n_bits>>& screen, int width);
void print_bits_index(int n);
void print_bits(const string_view& bits);
void print_lines_index(int i, int width_bytes, int last_i);

int main()
{
    constexpr int bytes{8};
    constexpr int n_width{2};
    constexpr int width{n_bits * n_width};
    constexpr int height{bytes / n_width};

    println("SCREEN: {} x {} pixels", width, height);
    print_screen(vector<bitset<n_bits>>(bytes), width);
    println("\n");

    for (const auto x1 : views::iota(-1, width + 1)) // -1 and +1 to catch exceptions
        for (const auto x2 : views::iota(-1, width + 1))
            for (const int y : views::iota(-1, height + 1)) {
                vector<bitset<n_bits>> screen(bytes);
                println("x1 = {}, x2 = {}, y = {}", x1, x2, y);

                try {
                    draw_line(screen, width, x1, x2, y);
                    print_screen(screen, width);
                    println("\n");
                }
                catch (const out_of_range& error) {
                    cout << error.what() << "\n\n";
                }
            }

    return 0;
}

void draw_line(vector<bitset<n_bits>>& screen, const int width, int x1, int x2, const int y)
{
    if (const auto is_negative{[](const int x) { return signbit(x); }};
        ranges::any_of(initializer_list<int>{x1, x2, y}, is_negative))
        throw out_of_range("Points must be nonnegative");

    if (x1 >= width || x2 >= width)
        throw out_of_range("Points must be inside width (x1, x2) from 0 up to (exclusive) " + to_string(width));

    if (const int height{static_cast<int>(screen.size()) / (width / n_bits)}; y >= height)
        throw out_of_range("Points must be inside height (y) from 0 up to (exclusive) " + to_string(height));

    if (x2 < x1)
        swap(x1, x2);

    const int width_bytes{width / n_bits};
    const int initial_byte{y * width_bytes + x1 / n_bits};
    const int initial_bit{x1 % n_bits};

    for (int i{initial_byte}, j{n_bits - initial_bit - 1}, pixels_to_fill{x2 - x1 + 1}; pixels_to_fill--; --j) {
        if (j < 0) {
            j = n_bits - 1;
            ++i;
        }
        screen.at(i).set(j);
    }
}

void print_screen(const vector<bitset<n_bits>>& screen, const int width)
{
    print_bits_index(width);
    println("");
    cout << setw(4) << 0;

    for (const int width_bytes{width / n_bits}, last_i{static_cast<int>(screen.size()) - 1};
         const auto& [i, line] : screen | views::enumerate) {
        print_bits(line.to_string());
        print_lines_index(static_cast<int>(i), width_bytes, last_i);
    }
}

void print_bits_index(const int n)
{
    cout << left << setw(6) << ' ';
    for (const auto i : views::iota(0, n))
        cout << setw(3) << i;
    // Back to default
    cout << right;
}

void print_bits(const string_view& bits)
{
    for (const auto bit : bits)
        cout << setw(3) << (bit == '1' ? '-' : ' ');
}

void print_lines_index(const int i, const int width_bytes, const int last_i)
{
    if ((i + 1) % width_bytes == 0 && i < last_i)
        cout << '\n' << setw(4) << (i + 1) / width_bytes;
}
