# https://www.hackerrank.com/challenges/30-review-loop/problem?isFullScreen=true

def main():

    N = int(input())
    
    for _ in range(N):
        WORD = input()
        word1, word2 = "", ""
        is_word1_turn = True

        for ch in WORD.strip():
            if is_word1_turn:
                word1 += ch
            else:
                word2 += ch
            is_word1_turn = not is_word1_turn

        print(f"{word1} {word2}")


if __name__ == "__main__":
    main()
