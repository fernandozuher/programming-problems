#include <iostream>
#include <cstring>

using namespace std;

void reverse(char* str);

int main()
{
    char str[] = "abcde";
    reverse(str);
    cout << str;
    return 0;
}

void reverse(char* str)
{
    int n = strlen(str);
    for (int i{}, j = n - 1, size = n / 2; i < size; ++i, --j)
        swap(str[i], str[j]);
}
