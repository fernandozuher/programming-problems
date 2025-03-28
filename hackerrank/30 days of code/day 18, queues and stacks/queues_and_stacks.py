# https://www.hackerrank.com/challenges/30-queues-stacks/problem?isFullScreen=true

def main():
    word = input()
    obj = init_queue_and_stack(word)
    check_if_palindrome(obj, word)


def init_queue_and_stack(word):
    obj = QueueAndStack()
    for ch in word:
        obj.enqueue_character(ch)
        obj.push_character(ch)
    return obj


class QueueAndStack:

    def __init__(self):
        self.my_queue = []
        self.my_stack = []

    def enqueue_character(self, ch):
        self.my_queue.append(ch)

    def push_character(self, ch):
        self.my_stack.append(ch)

    def dequeue_character(self):
        return self.my_queue.pop(0)

    def pop_character(self):
        return self.my_stack.pop()


def check_if_palindrome(obj, word):
    is_palindrome = True

    for _ in range(int(len(word) / 2)):
        if obj.dequeue_character() != obj.pop_character():
            is_palindrome = False
            break

    not_word = ' ' if is_palindrome else ' not '
    print(f"The word, {word}, is{not_word}a palindrome.")


if __name__ == '__main__':
    main()
