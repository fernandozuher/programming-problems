# https://www.hackerrank.com/challenges/30-operators/problem?isFullScreen=true

def main():

    meal_cost = float(input())
    tip_percent = int(input())
    tax_percent = int(input())

    solve(meal_cost, tip_percent, tax_percent)


def solve(meal_cost, tip_percent, tax_percent):

    TOTAL_COST = meal_cost + meal_cost*tip_percent/100 + meal_cost*tax_percent/100
    print("{:.0f}".format(TOTAL_COST))


if __name__ == '__main__':
    main()
