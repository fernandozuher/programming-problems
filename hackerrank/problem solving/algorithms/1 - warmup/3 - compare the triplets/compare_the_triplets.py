# https://www.hackerrank.com/challenges/compare-the-triplets/problem?isFullScreen=true

def main():
    triplet_a = read_input()
    triplet_b = read_input()
    score_a, score_b = compare_triplets(triplet_a, triplet_b)
    print(f"{score_a} {score_b}")


def read_input():
    return list(map(int, input().split()))


def compare_triplets(triplet_a, triplet_b):
    score_a, score_b = 0, 0

    for ta, tb in zip(triplet_a, triplet_b):
        if ta > tb:
            score_a += 1
        elif tb > ta:
            score_b += 1

    return [score_a, score_b]


if __name__ == '__main__':
    main()
