# https://www.hackerrank.com/challenges/climbing-the-leaderboard/problem?isFullScreen=true

def main():

    n = int(input())
    ranked = read_int_array()
    ranked = remove_duplicates(ranked)

    n = read_int_array()
    player = read_int_array()

    obj = ClimbingTheLeaderboard(ranked, player)
    print(*obj.player_rank(), sep='\n')


def read_int_array():

    return list(map(int, input().split()))


def remove_duplicates(array):

    return list(dict.fromkeys(array))


def binary_search_descending_order(array, low, high, key):

    if high >= low:
        middle = low + int((high - low) / 2)

        if key == array[middle]:
            return middle
        elif key > array[middle]:
            return binary_search_descending_order(array, low, middle - 1, key)
        else:
            return binary_search_descending_order(array, middle + 1, high, key)
    return low


class ClimbingTheLeaderboard:

    def __init__(self, ranked, player):

        self._ranked = ranked
        self._player = player
        self._player_rank = [None] * len(player)
        self._climbing_leaderboard()


    def _climbing_leaderboard(self):

        for i, player_score in enumerate(self._player):
            index = binary_search_descending_order(self._ranked, 0, len(self._ranked) - 1, player_score)
            self._player_rank[i] = index + 1


    def player_rank(self):

        return self._player_rank


if __name__ == "__main__":
    main()
