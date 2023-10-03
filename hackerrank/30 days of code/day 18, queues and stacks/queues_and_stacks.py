# https://www.hackerrank.com/challenges/30-queues-stacks/problem?isFullScreen=true

def main():
    word = input()
    obj = Solution()
    
    for ch in word:
        obj.push_character(ch)
        obj.enqueue_character(ch)

    check_if_word_is_palindrome(obj, word)


class QueuesAndStacks:

    def __init__(self):

        self.my_stack = []
        self.my_queue = []


    def push_character(self, ch):

        self.my_stack.append(ch)


    def enqueue_character(self, ch):

        self.my_queue.append(ch)


    def pop_character(self):

        return self.my_stack.pop()


    def dequeue_character(self):

        return self.my_queue.pop(0)


def check_if_word_is_palindrome(obj, word):

    is_palindrome = True

    for _ in range(len(word)/2):
        if obj.pop_character() != obj.dequeue_character():
            is_palindrome = False
            break

    not_word = ' ' if is_palindrome else ' not '
    print(f"The word, {word}, is{not_word}a palindrome.")


if __name__ == '__main__':
    main()
