# https://www.hackerrank.com/challenges/climbing-the-leaderboard/problem?isFullScreen=true

def main():
    input()
    ranked = remove_duplicates(read_numbers())
    input()
    player = read_numbers()
    print(*climbing_leaderboard(ranked, player), sep='\n')


def read_numbers():
    return list(map(int, input().split()))


def remove_duplicates(numbers):
    return list(dict.fromkeys(numbers))


def climbing_leaderboard(ranked, player):
    player_ranks = [None] * len(player)
    i = len(ranked) - 1

    for j, score in enumerate(player):
        while i >= 0 and score >= ranked[i]:
            i -= 1
        player_ranks[j] = i + 2

    return player_ranks


if __name__ == '__main__':
    main()
