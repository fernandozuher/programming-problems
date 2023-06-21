# Source: https://www.hackerrank.com/challenges/halloween-sale/problem?isFullScreen=true

def main():

    GAME_DEFAULT_PRICE, DISCOUNT, GAME_MINIMUM_PRICE, BUDGET = read_an_array()
    print(how_many_games_can_be_bought(GAME_DEFAULT_PRICE, DISCOUNT, GAME_MINIMUM_PRICE, BUDGET))


def read_an_array():

    return list(map(int, input().split()))


def how_many_games_can_be_bought(game_default_price, discount, game_minimum_price, budget):

    games_can_be_bought_quantity = 0
    current_game_price = game_default_price
    current_budget = budget - game_default_price

    while current_budget >= 0:
        games_can_be_bought_quantity += 1
        current_game_price -= discount
        current_budget -= current_game_price if current_game_price >= game_minimum_price else game_minimum_price

    return games_can_be_bought_quantity


if __name__ == "__main__":
    main()
