# https://www.hackerrank.com/challenges/append-and-delete/problem?isFullScreen=true

def main():
    initial_string = input()
    final_string = input()
    n_operations = int(input())
    print("Yes" if append_and_delete(initial_string, final_string, n_operations) else "No")


def append_and_delete(s1, s2, n_ops):
    prefix_len = common_prefix_length(s1, s2)
    total_ops_needed = (len(s1) - prefix_len) + (len(s2) - prefix_len)
    can_remove_all = n_ops >= len(s1) + len(s2)
    return can_remove_all or (n_ops >= total_ops_needed and (n_ops - total_ops_needed) % 2 == 0)


def common_prefix_length(s1, s2):
    min_len = min(len(s1), len(s2))
    for i in range(min_len):
        if s1[i] != s2[i]:
            return i
    return min_len


if __name__ == '__main__':
    main()
  