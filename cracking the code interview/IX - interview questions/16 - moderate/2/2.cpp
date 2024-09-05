// From C++23 onwards

#include <fstream>
#include <print>
#include <stdexcept>
#include <unordered_map>

using namespace std;

unordered_map<string, int> word_frequencies(const string_view& file_name);

int main()
{
    for (const string file_name{"input.txt"}; const auto& [str, freq] : word_frequencies(file_name))
        println("{}: {}", str, freq);
    return 0;
}

unordered_map<string, int> word_frequencies(const string_view& file_name)
{
    ifstream file{file_name.data()};
    if (!file)
        throw runtime_error("Error to open file");

    unordered_map<string, int> words;
    for (string str; file >> str; ++words[str]);
    return words;
}
