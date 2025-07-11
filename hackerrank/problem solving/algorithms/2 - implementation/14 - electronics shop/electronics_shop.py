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
    i = 0
    j = len(usb_drives) - 1

    while i < len(keyboards) and j >= 0:
        if keyboards[i] >= budget:
            break

        current_sum = keyboards[i] + usb_drives[j]
        if current_sum > budget:
            j -= 1
        elif current_sum == budget:
            return budget
        else:
            if current_sum > max_spent:
                max_spent = current_sum
            i += 1

    return max_spent


if __name__ == '__main__':
    main()
