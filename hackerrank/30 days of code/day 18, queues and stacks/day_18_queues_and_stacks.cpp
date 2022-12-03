#include <iostream>
#include <stack>
#include <queue>
using namespace std;

class Solution
{
    private:
        stack<char> my_stack;
        queue<char> my_queue;

    public:
        void push_character(char ch) {
            my_stack.push(ch);
        }

        void enqueue_character(char ch) {
            my_queue.push(ch);
        }

        char pop_character() {
            char ch = my_stack.top();
            my_stack.pop();
            return ch;
        }

        char dequeue_character() {
            char ch = my_queue.front();
            my_queue.pop();
            return ch;
        }

        bool is_empty() const {
            return my_stack.empty();
        }
};

int main()
{
    string s;
    getline(cin, s);
    
    Solution obj;
    
    for (auto& c : s)
        obj.push_character(c), obj.enqueue_character(c);
    
    int i {};
    for ( ; !obj.is_empty() && obj.pop_character() == obj.dequeue_character(); ++i);
    
    i = i < static_cast<int>(s.length()) / 2;
    cout << "The word, " << s << ", is " << (!i ? "" : "not ") << "a palindrome.";
    
    return 0;
}
