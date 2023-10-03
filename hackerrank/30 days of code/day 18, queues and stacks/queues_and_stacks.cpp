// https://www.hackerrank.com/challenges/30-queues-stacks/problem?isFullScreen=true

#include <iostream>
#include <queue>
#include <stack>

using namespace std;

class Queues_And_Stacks
{
private:
    stack<char> my_stack;
    queue<char> my_queue;

public:
    void push_character(const char ch) {
        my_stack.push(ch);
    }

    void enqueue_character(const char ch) {
        my_queue.push(ch);
    }

    char pop_character() {
        char ch {my_stack.top()};
        my_stack.pop();
        return ch;
    }

    char dequeue_character() {
        char ch {my_queue.front()};
        my_queue.pop();
        return ch;
    }
};

void check_if_word_is_palindrome(Queues_And_Stacks& obj, const string& word);

int main()
{
    string word;
    getline(cin, word);
    Queues_And_Stacks obj;

    for (const auto& c : word)
        obj.push_character(c), obj.enqueue_character(c);

    check_if_word_is_palindrome(obj, word);

    return 0;
}

    void check_if_word_is_palindrome(Queues_And_Stacks& obj, const string& word)
    {
        bool is_palindrome {true};

        for (int i {}, len = word.size() / 2; i < len; ++i)
            if (obj.pop_character() != obj.dequeue_character()) {
                is_palindrome = false;
                break;
            }

        string not_word {is_palindrome ? " " : " not "};
        cout << "The word, " << word << ", is" << not_word << "a palindrome.";
    }
