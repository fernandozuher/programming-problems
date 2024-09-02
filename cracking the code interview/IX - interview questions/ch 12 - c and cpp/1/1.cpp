// From C++23

#include <fstream>
#include <iostream>
#include <print>
#include <ranges>
#include <string_view>

using namespace std;

void print_last_k_lines(const string_view& file_name, int k);

int main()
{
    const auto file_name{"input.txt"s};

    try {
        for (constexpr int n{9}; const auto i : views::iota(1, n)) {
            println("Last {} line(s):", i);
            print_last_k_lines(file_name, i);
            println("");
        }
    }
    catch (const invalid_argument& error) {
        cerr << error.what() << '\n';
    }

    return 0;
}

void print_last_k_lines(const string_view& file_name, const int k)
{
    ifstream file(file_name.data());
    if (!file)
        throw invalid_argument("Error opening file.");

    file.seekg(0, ios::end);

    for (streamoff file_size{file.tellg()}, i{file_size - 1}, lines{}; i >= 0; --i) {
        file.seekg(i);
        char ch;
        file.get(ch);

        if (ch == '\n' && ++lines == k)
            break;
    }

    for (string str; getline(file, str);)
        cout << str << '\n';

    file.close();
}
