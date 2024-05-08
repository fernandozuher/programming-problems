# https://www.hackerrank.com/challenges/halloween-sale/problem?isFullScreen=true

def main():
    game_default_price, discount, minimum_price_game, budget = read_int_array()
    print(how_many_games_can_be_bought(game_default_price, discount, minimum_price_game, budget))


def read_int_array():
    return list(map(int, input().split()))


def how_many_games_can_be_bought(default_price_game, discount, minimum_price_game, budget):
    games_can_be_bought_quantity = 0
    current_price_game = default_price_game
    current_budget = budget - default_price_game

    while current_budget >= 0:
        games_can_be_bought_quantity += 1
        current_price_game -= discount
        current_budget -= max(current_price_game, minimum_price_game)

    return games_can_be_bought_quantity


if __name__ == '__main__':
    main()
