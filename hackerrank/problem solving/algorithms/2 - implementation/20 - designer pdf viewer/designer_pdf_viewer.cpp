// https://www.hackerrank.com/challenges/designer-pdf-viewer/problem?isFullScreen=true

#include <algorithm>
#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

class Designer_Pdf_Viewer {
public:
    Designer_Pdf_Viewer(const vector<int>& letters_heights, const string& word);
    int area() const;

private:
    vector<int> letters_heights;
    string word;
    int area_size;

    void calculate_area();
};

    Designer_Pdf_Viewer::Designer_Pdf_Viewer(const vector<int>& letters_heights, const string& word)
        : letters_heights{letters_heights}, word{word}, area_size{}
    {
        calculate_area();
    }

        void Designer_Pdf_Viewer::calculate_area()
        {
            int max_height{};

            for (const char letter : word) {
                int letter_index {letter - 'a'};
                int letter_height {letters_heights[letter_index]};
                max_height = max(max_height, letter_height);
            }

            area_size = max_height * word.size();
        }

    int Designer_Pdf_Viewer::area() const
    {
        return area_size;
    }

/////////////////////////////////////////////////

template<class T = int>
vector<T> read(const int n = 0);

int main()
{
    vector<int> letters_heights {read()};
    string word;
    cin >> word;

    Designer_Pdf_Viewer obj{letters_heights, word};
    cout << obj.area();

    return 0;
}

    template<class T = int>
    vector<T> read(const int n)
    {
        vector<T> array(n);

        if (n)
            ranges::generate(array, [] {T x; cin >> x; return x;});
        else {
            string line;
            getline(cin, line);
            istringstream is{line};
            for (T x; is >> x; array.push_back(x));
        }

        return array;
    }
