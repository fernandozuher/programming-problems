# https://www.hackerrank.com/challenges/compare-the-triplets/problem?isFullScreen=true

import sys
from typing import Type, List, Any, TextIO


def main():
    triplet_a = read(int)
    triplet_b = read(int)
    score_a, score_b = compare_triplets(triplet_a, triplet_b)
    print(f"{score_a} {score_b}")


def read(target_type: Type[Any], stream: TextIO = sys.stdin) -> List[Any]:
    if not is_callable_builtin_type(target_type):
        raise TypeError(f"Type '{target_type}' is not a valid built-in type.")
    line = stream.readline()
    return list(map(target_type, line.strip().split()))


def is_callable_builtin_type(target_type: Type[Any]):
    return (hasattr(target_type, '__module__') and
            target_type.__module__ == 'builtins' and
            callable(target_type))


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
