// https://www.hackerrank.com/challenges/30-testing/problem?isFullScreen=true

#include <algorithm>
#include <cassert>
#include <iostream>
#include <set>
#include <vector>

using namespace std;

class Test_Data_Empty_Array {
public:
    static vector<int> get_array()
    {
        return vector<int> {};
    }
};

class Test_Data_Unique_Values {
public:
    static vector<int> get_array()
    {
        return vector<int> {2, 1};
    }

    static int get_expected_result()
    {
        return 1;
    }
};

class Test_Data_Exactly_Two_Different_Minimums {
public:
    static vector<int> get_array()
    {
        return vector<int> {1, 2, 1};
    }

    static int get_expected_result()
    {
        return 0;
    }
};

void test_with_empty_array();
int minimum_index(const vector<int>& seq);
void test_with_unique_values();
void test_with_exactly_two_different_minimums();

int main()
{
    test_with_empty_array();
    test_with_unique_values();
    test_with_exactly_two_different_minimums();
    cout << "OK" << endl;
    return 0;
}

    void test_with_empty_array() {
        try {
            vector<int> seq {Test_Data_Empty_Array::get_array()};
            int result {minimum_index(seq)};
        } catch (invalid_argument& e) {
            return;
        }
        assert(false);
    }

    int minimum_index(const vector<int>& seq)
    {
        if (seq.empty())
            throw invalid_argument("Cannot get the minimum value index from an empty sequence");

        int min_idx {};
        for (int i {1}; i < seq.size(); ++i)
            if (seq[i] < seq[min_idx])
                min_idx = i;

        return min_idx;
    }

    void test_with_unique_values()
    {
        vector<int> seq {Test_Data_Unique_Values::get_array()};
        assert(seq.size() >= 2);

        assert(set<int>(seq.begin(), seq.end()).size() == seq.size());

        int expected_result {Test_Data_Unique_Values::get_expected_result()};
        int result {minimum_index(seq)};
        assert(result == expected_result);
    }

    void test_with_exactly_two_different_minimums()
    {
        vector<int> seq {Test_Data_Exactly_Two_Different_Minimums::get_array()};
        assert(seq.size() >= 2);

        vector<int> tmp {seq};
        ranges::sort(tmp);
        assert(tmp[0] == tmp[1] and (tmp.size() == 2 or tmp[1] < tmp[2]));

        int expected_result {Test_Data_Exactly_Two_Different_Minimums::get_expected_result()};
        int result {minimum_index(seq)};
        assert(result == expected_result);
    }
