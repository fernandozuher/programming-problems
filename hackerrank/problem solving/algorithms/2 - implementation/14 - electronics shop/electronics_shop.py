# https://www.hackerrank.com/challenges/electronics-shop/problem?isFullScreen=true

def main():
    budget = read_numbers()[0]
    keyboards = sorted(set(read_numbers()))
    usb_drives = sorted(set(read_numbers()))
    print(calculate_money_spent(keyboards, usb_drives, budget))


def read_numbers():
    return list(map(int, input().split()))


def calculate_money_spent(keyboards, usb_drives, budget):
    max_spent = -1

    for keyboard in keyboards:
        if keyboard > budget:
            break
        remaining = budget - keyboard
        max_spent = max(max_usb_price_within_budget(usb_drives, remaining, keyboard), max_spent)

    return max_spent


def max_usb_price_within_budget(usb_drives, remaining, keyboard):
    left = 0
    right = len(usb_drives) - 1
    max_spent = -1

    while left <= right:
        mid = (left + right) // 2
        if usb_drives[mid] == remaining:
            return max([max_spent, keyboard + usb_drives[mid]])
        elif usb_drives[mid] < remaining:
            max_spent = max(max_spent, keyboard + usb_drives[mid])
            left = mid + 1
        else:
            right = mid - 1

    return max_spent


if __name__ == '__main__':
    main()
