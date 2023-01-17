// Source: https://www.hackerrank.com/challenges/designer-pdf-viewer/problem?isFullScreen=true

#include <iostream>
#include <vector>
#include <sstream>

using namespace std;


class Result {

private:
    vector<int> _lettersHeights;
    string _word;
    int _area;

    void _designer_pdf_viewer() {
        int max_height {0};

        for (char letter : _word) {
            const int letter_index {letter - 'a'};
            const int letter_height {_lettersHeights[letter_index]};

            if (max_height < letter_height)
                max_height = letter_height;
        }

        _area = max_height * _word.size();
    }

public:
    Result(const vector<int> lettersHeights, const string word) {
        _lettersHeights = lettersHeights;
        _word = word;
        _area = 0;

        _designer_pdf_viewer();
        print_area();
    }

        void print_area() const {
            cout << _area << "\n";
        }
};

vector<int> read_line_as_vector_int() {
    vector<int> input_line;
    string line;
    getline(cin, line);
    stringstream ss(line);

    for (int number; ss >> number; input_line.push_back(number));
    return input_line;
}

int main() {
    const vector<int> input_line1 {read_line_as_vector_int()};
    string input_line2;
    cin >> input_line2;

    const Result result(input_line1, input_line2);

    return 0;
}
