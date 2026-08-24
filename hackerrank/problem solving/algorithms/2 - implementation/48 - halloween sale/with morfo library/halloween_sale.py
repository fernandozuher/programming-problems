# https://www.hackerrank.com/challenges/halloween-sale/problem?isFullScreen=true

import morfo


def main():
    price, discount, min_price, budget = morfo.read(int, 4)
    print(how_many_games_can_be_bought(price, discount, min_price, budget))


# T: O(budget / min_price)
# S: O(1) extra space
def how_many_games_can_be_bought(price, discount, min_price, budget):
    count = 0
    while budget >= price:
        count += 1
        budget -= price
        price = max(price - discount, min_price)
    return count


if __name__ == '__main__':
    main()
