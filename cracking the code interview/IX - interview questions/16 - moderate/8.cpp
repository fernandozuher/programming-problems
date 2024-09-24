// From C++23 onwards

#include <print>
#include <ranges>
#include <unordered_map>
#include <vector>

using namespace std;

unordered_map<int, string> init_default_english_words_of_numbers();
string number_to_word(int n, const unordered_map<int, string>& english_numbers);
string chunk_to_word(vector<int> digits, const unordered_map<int, string>& english_numbers);
string three_digits(vector<int>& digits, const unordered_map<int, string>& english_numbers);
string two_digits(const vector<int>& digits, const unordered_map<int, string>& english_numbers);
string one_digit(const vector<int>& digits, const unordered_map<int, string>& english_numbers);

int main()
{
    const auto english_numbers{init_default_english_words_of_numbers()};
    for (constexpr int start{1'000'000}, end{1'000'400}; const auto i : views::iota(start, end))
        println("{} = {}", i, number_to_word(i, english_numbers));
    return 0;
}

unordered_map<int, string> init_default_english_words_of_numbers()
{
    vector<string> from_0_to_19{
        "zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine", "ten",
        "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen",
        "nineteen"
    };
    vector<string> from_20_to_90{
        "twenty", "thirty", "forty", "fifty", "sixty", "seventy", "eighty", "ninety"
    };

    unordered_map<int, string> number_in_english;
    for (const auto& [i, x] : from_0_to_19 | views::enumerate)
        number_in_english[i] = x;

    for (const auto& [i, x] : views::zip(views::iota(20, 91) | views::stride(10), from_20_to_90))
        number_in_english[i] = x;

    return number_in_english;
}

string number_to_word(const int n, const unordered_map<int, string>& english_numbers)
{
    const auto char_to_int{[](const char ch) { return ch - '0'; }};
    auto digits{to_string(n) | views::transform(char_to_int) | ranges::to<vector>()};
    vector strings{""s, "thousand"s, "million"s, "billion"s};
    string number_in_english;

    constexpr int chunk_size{3};
    const auto chunks{digits | views::reverse | views::chunk(chunk_size)};
    for (const auto& [chunk, english_string] : views::zip(chunks, strings)) {
        vector<int> chunk_vec;
        ranges::copy(chunk, back_inserter(chunk_vec));

        if (string word{chunk_to_word(chunk_vec, english_numbers)}; !word.empty()) {
            if (!english_string.empty())
                word += " " + english_string;

            if (!number_in_english.empty())
                number_in_english = word += " " + number_in_english;
            else
                number_in_english = word;
        }
    }

    return number_in_english;
}

string chunk_to_word(vector<int> digits, const unordered_map<int, string>& english_numbers)
{
    int n{static_cast<int>(digits.size())};
    string word;

    if (n == 3) {
        word = three_digits(digits, english_numbers);
        --n;
    }
    if (n == 2)
        word += two_digits(digits, english_numbers);
    else if (n == 1)
        word = one_digit(digits, english_numbers);

    if (!word.empty() && word.back() == ' ')
        word.pop_back();

    return word;
}

string three_digits(vector<int>& digits, const unordered_map<int, string>& english_numbers)
{
    string word;
    if (digits.back() != 0)
        word = english_numbers.at(digits.back()) + " hundred ";
    digits.pop_back();
    return word;
}

string two_digits(const vector<int>& digits, const unordered_map<int, string>& english_numbers)
{
    string word;

    if (digits.back() != 0) {
        int tens{digits.back() * 10};
        int number{tens + digits.front()};

        if (number < 21)
            word = english_numbers.at(number);
        else {
            word = english_numbers.at(tens);
            if (digits.front() != 0)
                word += "-" + english_numbers.at(digits.front());
        }
    }
    else if (digits.front() != 0)
        word = english_numbers.at(digits.front());

    return word;
}

string one_digit(const vector<int>& digits, const unordered_map<int, string>& english_numbers)
{
    return english_numbers.at(digits.back());
}
