# https://www.hackerrank.com/challenges/compare-the-triplets/problem?isFullScreen=true

def main():
    triplet_a = read_nums()
    triplet_b = read_nums()
    score_a, score_b = compare_triplets(triplet_a, triplet_b)
    print(f"{score_a} {score_b}")


def read_nums():
    return list(map(int, input().split()))


# n: length of a and b = 3
# T: O(3) => O(1)
# S: O(1) extra space
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
