# https://www.hackerrank.com/challenges/append-and-delete/problem?isFullScreen=true

def main():
    s1 = input()
    s2 = input()
    n_ops = int(input())
    print('Yes' if append_and_delete(s1, s2, n_ops) else 'No')


# n1: length of string s1
# n2: length of string s2
# T: O(min(n1, n2))
# S: O(1) extra space
def append_and_delete(s1, s2, n_ops):
    prefix_len = common_prefix_length(s1, s2)
    ops_needed = (len(s1) - prefix_len) + (len(s2) - prefix_len)
    if n_ops < ops_needed:
        return False

    if n_ops >= len(s1) + len(s2):
        return True

    return (n_ops - ops_needed) % 2 == 0


def common_prefix_length(s1, s2):
    for i, (x, y) in enumerate(zip(s1, s2)):
        if x != y:
            return i
    return min(len(s1), len(s2))


if __name__ == '__main__':
    main()
