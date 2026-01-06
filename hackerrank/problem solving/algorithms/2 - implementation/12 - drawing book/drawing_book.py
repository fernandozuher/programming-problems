# https://www.hackerrank.com/challenges/drawing-book/problem?isFullScreen=true

def main():
    n = int(input())
    page = int(input())
    print(count_page(n, page))


# T: O(1)
# S: O(1) extra space
def count_page(n, page):
    from_front = page // 2
    from_back = n // 2 - from_front
    return min(from_front, from_back)


if __name__ == '__main__':
    main()
