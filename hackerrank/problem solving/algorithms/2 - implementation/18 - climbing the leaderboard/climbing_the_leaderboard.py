# https://www.hackerrank.com/challenges/climbing-the-leaderboard/problem?isFullScreen=true

def main():
    input()
    ranked = remove_duplicates(read_numbers())
    input()
    player = read_numbers()
    print(*climbing_leaderboard(ranked, player), sep='\n')


def read_numbers():
    return list(map(int, input().split()))


def remove_duplicates(arr):
    return list(dict.fromkeys(arr))


# n: length of array player|player_ranks
# m: length of array ranked
# T: O(n + m)
# S: O(n) extra space
def climbing_leaderboard(ranked, player):
    player_ranks = [0] * len(player)
    seeker = len(ranked) - 1

    for writer, score in enumerate(player):
        while seeker >= 0 and score >= ranked[seeker]:
            seeker -= 1
        player_ranks[writer] = seeker + 2

    return player_ranks


if __name__ == '__main__':
    main()
