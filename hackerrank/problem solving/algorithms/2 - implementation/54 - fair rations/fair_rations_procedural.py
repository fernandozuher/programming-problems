# Source: https://www.hackerrank.com/challenges/fair-rations/problem?isFullScreen=true

def main():

    _ = input()
    N_LOAVES_OF_EACH_PERSON = list(map(int, input().split()))
    print(find_min_loaves_to_satisfy_rules(N_LOAVES_OF_EACH_PERSON))


def find_min_loaves_to_satisfy_rules(n_loaves_of_each_person):

    min_loaves_to_satisfy_rules = 0

    for i in range(len(n_loaves_of_each_person) - 1):
        if n_loaves_of_each_person[i] % 2 == 1:
            n_loaves_of_each_person[i] += 1
            n_loaves_of_each_person[i + 1] += 1
            min_loaves_to_satisfy_rules += 2

    return "NO" if n_loaves_of_each_person[-1] % 2 == 1 else str(min_loaves_to_satisfy_rules)


if __name__ == "__main__":
    main()
