# https://www.hackerrank.com/challenges/beautiful-triplets/problem?isFullScreen=true

def main():
    _, beautiful_difference = read_int_array()
    array = read_int_array()
    print(find_beautiful_triplets(array, beautiful_difference))


def read_int_array():
    return list(map(int, input().split()))


def find_beautiful_triplets(array, beautiful_difference):
    n_beautiful_triplets = 0

    if len(array) > 2:
        for i, v1 in enumerate(array[:-2]):
            for j, v2 in enumerate(array[i + 1:-1]):
                if (first_difference := v2 - v1) < beautiful_difference:
                    continue
                elif first_difference > beautiful_difference:
                    break

                j += i + 1
                for k, v3 in enumerate(array[j + 1:]):
                    if (second_difference := v3 - v2) == beautiful_difference:
                        n_beautiful_triplets += 1
                    elif second_difference > beautiful_difference:
                        break

    return n_beautiful_triplets


if __name__ == '__main__':
    main()
