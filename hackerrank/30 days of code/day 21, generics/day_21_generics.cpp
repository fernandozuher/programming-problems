#include <iostream>
#include <vector>
#include <string>

using namespace std;

template <typename T>
void print_array(vector<T>& vec) {
    for (auto& val : vec)
        cout << val << '\n';
}

int main() {
    int n;
    cin >> n;
    vector<int> int_vector(n);
    for (int i {}, value; i < n && cin >> value; int_vector.at(i++) = value);
    
    cin >> n;
    vector<string> string_vector(n);
    string value;
    for (int i {}; i < n && cin >> value; string_vector.at(i++) = value);

    print_array(int_vector);
    print_array(string_vector);

    return 0;
}
