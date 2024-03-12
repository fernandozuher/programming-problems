# https://www.hackerrank.com/challenges/sparse-arrays/problem?isFullScreen=true

def main():

    n = int(input())
    input_strings = read_lines(n)
    input_strings = create_dictionary_from_list(input_strings)

    n = int(input())
    queries = read_lines(n)

    result = count_matches(input_strings, queries)
    print(*result, sep= '\n')


def read_lines(n):

    return [input() for _ in range(n)]


def create_dictionary_from_list(ls):

    dictionary = {}
    for key in ls:
        dictionary[key] = dictionary.get(key, 0) + 1
    return dictionary


def count_matches(input_strings, queries):

    result = [0] * len(queries)
    for i in range(len(result)):
        query = queries[i]
        result[i] = input_strings.get(query, 0)
    return result


if __name__ == '__main__':
    main()
