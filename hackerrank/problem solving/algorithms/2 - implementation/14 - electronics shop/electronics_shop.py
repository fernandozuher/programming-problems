# https://www.hackerrank.com/challenges/electronics-shop/problem?isFullScreen=true

def main():
    budget = read_numbers()[0]
    keyboards = preprocess_input(read_numbers())
    usb_drives = preprocess_input(read_numbers())
    print(calc_money_spent(keyboards, usb_drives, budget))


def read_numbers():
    return list(map(int, input().split()))


# n: length of array arr
# k: length after deduplication
# k <= n
# T: O(n + k log k) = O(n log n)
# S: O(k) = O(n) extra space
def preprocess_input(arr):
    arr = list(set(arr))
    arr.sort()
    return arr


# n1: length of array keyboards
# n2: length of array usb_drives
# T: O(n1 + n2)
# S: O(1) extra space
def calc_money_spent(keyboards, usb_drives, budget):
    if keyboards[0] >= budget or usb_drives[0] >= budget:
        return -1

    max_spent = -1
    idx_k, idx_ud = 0, len(usb_drives) - 1

    while idx_k < len(keyboards) and idx_ud >= 0:
        if keyboards[idx_k] >= budget:
            break

        current_sum = keyboards[idx_k] + usb_drives[idx_ud]
        if current_sum == budget:
            return budget
        if current_sum > budget:
            idx_ud -= 1
        else:
            max_spent = max(max_spent, current_sum)
            idx_k += 1

    return max_spent


if __name__ == '__main__':
    main()
