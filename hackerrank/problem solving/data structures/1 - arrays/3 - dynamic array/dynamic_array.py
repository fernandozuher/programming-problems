# https://www.hackerrank.com/challenges/dynamic-array/problem?isFullScreen=true

def main():

    n, n_queries = read_int_array()
    obj = DynamicArray(n)

    for _ in range(n_queries):
        obj.handle_query(read_int_array())
    print(*obj.answers(), sep='\n')


def read_int_array():

    return list(map(int, input().split()))


class DynamicArray:

    def __init__(self, n):

        self._n = n
        self._array = [[] for _ in range(n)]
        self._answers = []
        self._last_answer = 0


    def handle_query(self, query):

        type, x, y = query
        index = (x ^ self._last_answer) % self._n

        if type == 1:
            self._array[index].append(y)
        else:
            j = y % len(self._array[index])
            self._last_answer = self._array[index][j]
            self._answers.append(self._last_answer)


    def answers(self):

        return self._answers


if __name__ == '__main__':
    main()
