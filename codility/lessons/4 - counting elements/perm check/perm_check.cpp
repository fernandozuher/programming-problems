// Source: https://app.codility.com/programmers/lessons/4-counting_elements/perm_check/

#include <set>

using namespace std;

int solution(vector<int>& array)
{
    set<int> numbers {array.begin(), array.end()};
    return numbers.size() == array.size() && *numbers.rbegin() == (int) array.size();
}
