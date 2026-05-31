# https://www.hackerrank.com/challenges/dynamic-array/problem?isFullScreen=true

def main():
    n, n_queries = read_numbers()
    obj = DynamicArray(n)

    for _ in range(n_queries):
        obj.handle_query(read_numbers())

    print(*obj.answers(), sep='\n')


def read_numbers():
    return list(map(int, input().split()))


class DynamicArray:

    def __init__(self, n):
        self._n = n
        self._arr = [[] for _ in range(n)]
        self._answers = []
        self._last_answer = 0

    def handle_query(self, query):
        type, x, y = query
        index = (x ^ self._last_answer) % self._n

        if type == 1:
            self._arr[index].append(y)
        else:
            j = y % len(self._arr[index])
            self._last_answer = self._arr[index][j]
            self._answers.append(self._last_answer)

    def answers(self):
        return self._answers


if __name__ == '__main__':
    main()
