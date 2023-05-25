# Source: https://www.hackerrank.com/challenges/beautiful-triplets/problem?isFullScreen=true

def main():

    SIZE, BEAUTIFUL_DIFFERENCE = read_an_array()
    ARRAY = read_an_array()

    N_BEAUTIFUL_TRIPLETS = find_beautiful_triplets(ARRAY, BEAUTIFUL_DIFFERENCE)
    print(N_BEAUTIFUL_TRIPLETS)


def read_an_array():

    ARRAY = list(map(int, input().split()))
    return ARRAY


def find_beautiful_triplets(array, beautiful_difference):

    n_beautiful_triplets = 0

    if len(array) > 2:
        for i in range(0, len(array)-2):
            for j in range(i+1, len(array)-1):
                FIRST_DIFFERENCE = array[j] - array[i]

                if FIRST_DIFFERENCE < beautiful_difference:
                    continue
                elif FIRST_DIFFERENCE > beautiful_difference:
                    break
                
                for k in range(j+1, len(array)):
                    SECOND_DIFFERENCE = array[k] - array[j]

                    if SECOND_DIFFERENCE == beautiful_difference:
                        n_beautiful_triplets += 1
                    elif SECOND_DIFFERENCE > beautiful_difference:
                        break

    return n_beautiful_triplets


if __name__ == "__main__":
    main()
