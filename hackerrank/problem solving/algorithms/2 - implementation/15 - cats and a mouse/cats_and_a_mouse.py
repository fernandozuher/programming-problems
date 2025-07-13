# https://www.hackerrank.com/challenges/cats-and-a-mouse/problem?isFullScreen=true&is_full_screen=true

def main():
    n = int(input())
    nearest_cats_or_not = [find_nearest_cat_or_not(read_numbers()) for _ in range(n)]
    print(*nearest_cats_or_not, sep='\n')


def read_numbers():
    return list(map(int, input().split()))


def find_nearest_cat_or_not(positions):
    cat_a, cat_b, mouse = positions
    cat_a_from_mouse = abs(cat_a - mouse)
    cat_b_from_mouse = abs(cat_b - mouse)

    if cat_a_from_mouse < cat_b_from_mouse:
        return 'Cat A'
    elif cat_a_from_mouse > cat_b_from_mouse:
        return 'Cat B'
    else:
        return 'Mouse C'


if __name__ == '__main__':
    main()
