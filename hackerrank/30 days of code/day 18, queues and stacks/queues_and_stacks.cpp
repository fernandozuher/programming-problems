// https://www.hackerrank.com/challenges/30-queues-stacks/problem?isFullScreen=true

#include <iostream>
#include <queue>
#include <string_view>
#include <stack>

using namespace std;

class Queue_And_Stack {
private:
    queue<char> my_queue;
    stack<char> my_stack;

public:
    void enqueue_character(const char ch)
    {
        my_queue.push(ch);
    }

    void push_character(const char ch)
    {
        my_stack.push(ch);
    }

    char dequeue_character()
    {
        char ch{my_queue.front()};
        my_queue.pop();
        return ch;
    }

    char pop_character()
    {
        char ch{my_stack.top()};
        my_stack.pop();
        return ch;
    }
};

Queue_And_Stack init_queue_and_stack(const string_view& word);
void check_if_palindrome(Queue_And_Stack& obj, const string_view& word);

int main()
{
    string word;
    getline(cin, word);
    Queue_And_Stack obj{init_queue_and_stack(word)};
    check_if_palindrome(obj, word);
    return 0;
}

Queue_And_Stack init_queue_and_stack(const string_view& word)
{
    Queue_And_Stack obj;
    for (auto c : word) {
        obj.enqueue_character(c);
        obj.push_character(c);
    }
    return obj;
}

void check_if_palindrome(Queue_And_Stack& obj, const string_view& word)
{
    bool is_palindrome{true};

    for (auto half_length{word.size() / 2}; half_length--;)
        if (obj.dequeue_character() != obj.pop_character()) {
            is_palindrome = false;
            break;
        }

    string_view not_word{is_palindrome ? " " : " not "};
    cout << "The word, " << word << ", is" << not_word << "a palindrome.";
}
