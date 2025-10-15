# https://www.hackerrank.com/challenges/halloween-sale/problem?isFullScreen=true

def main():
    price, discount, min_price, budget = read_numbers()
    print(how_many_games_can_be_bought(price, discount, min_price, budget))


def read_numbers():
    return list(map(int, input().split()))


def how_many_games_can_be_bought(price, discount, min_price, budget):
    count = 0
    while budget >= price:
        count += 1
        budget -= price
        price = max(price - discount, min_price)
    return count


if __name__ == '__main__':
    main()
