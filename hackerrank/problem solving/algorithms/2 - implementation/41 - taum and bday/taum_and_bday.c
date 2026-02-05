// https://www.hackerrank.com/challenges/taum-and-bday/problem?isFullScreen=true

#include <stdio.h>

typedef struct {
    long n_black_gifts;
    long n_white_gifts;
    long black_gift_cost;
    long white_gift_cost;
    long cost_to_convert_between_gifts;
} gifts;

gifts read_test_case();
long min_cost_of_buying_gifts(const gifts *x);

int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        gifts test_case = read_test_case();
        printf("%ld\n", min_cost_of_buying_gifts(&test_case));
    }
    return 0;
}

gifts read_test_case()
{
    gifts x;
    scanf("%ld %ld %ld %ld %ld",
          &x.n_black_gifts, &x.n_white_gifts,
          &x.black_gift_cost, &x.white_gift_cost,
          &x.cost_to_convert_between_gifts);
    return x;
}

// T: O(1)
// S: O(1) extra space
long min_cost_of_buying_gifts(const gifts *x)
{
    long blackCost = x->black_gift_cost < x->white_gift_cost + x->cost_to_convert_between_gifts
                         ? x->black_gift_cost
                         : x->white_gift_cost + x->cost_to_convert_between_gifts;

    long whiteCost = x->white_gift_cost < x->black_gift_cost + x->cost_to_convert_between_gifts
                         ? x->white_gift_cost
                         : x->black_gift_cost + x->cost_to_convert_between_gifts;

    return x->n_black_gifts * blackCost + x->n_white_gifts * whiteCost;
}
