# Source: https://www.hackerrank.com/challenges/halloween-sale/problem?isFullScreen=true

def main():

    GAME_DEFAULT_PRICE, DISCOUNT, GAME_MINIMUM_PRICE, BUDGET = read_an_array()
    OBJ = HalloweenSale(GAME_DEFAULT_PRICE, DISCOUNT, GAME_MINIMUM_PRICE, BUDGET)
    print(OBJ.get_games_can_be_bought_quantity())


def read_an_array():

    return list(map(int, input().split()))


class HalloweenSale:

    def __init__(self, game_default_price, discount, game_minimum_price, budget):

        self._game_default_price = game_default_price
        self._discount = discount
        self._game_minimum_price = game_minimum_price
        self._budget = budget
        self._games_can_be_bought_quantity = 0

        self._calculate_how_many_games_can_be_bought()


    def _calculate_how_many_games_can_be_bought(self):

        current_game_price = self._game_default_price
        current_budget = self._budget - self._game_default_price

        while current_budget >= 0:
            self._games_can_be_bought_quantity += 1
            current_game_price -= self._discount
            current_budget -= current_game_price if current_game_price >= self._game_minimum_price else self._game_minimum_price


    def get_games_can_be_bought_quantity(self):
        
        return self._games_can_be_bought_quantity


if __name__ == "__main__":
    main()
