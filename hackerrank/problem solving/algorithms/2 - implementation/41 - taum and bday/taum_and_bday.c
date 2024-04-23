// https://www.hackerrank.com/challenges/taum-and-bday/problem?isFullScreen=true

#include <stdbool.h>
#include <stdio.h>

typedef struct {
    long n_black_gifts;
    long n_white_gifts;
    long black_gift_cost;
    long white_gift_cost;
    long cost_to_convert_between_gifts;
} gifts;

gifts read_test_case();
long calculate_minimum_cost_of_buying_gifts(const gifts *const x);
    bool are_original_costs_cheaper_or_equal_than_convertion_between_gifts(const gifts *const x);
    long calculate_minimum_standard_cost(const gifts *const x);
    long calculate_minimum_cost_in_converting_gifts(const gifts *const x);
void print_array(const long *const array, const int n);

int main()
{
    int n;
    scanf("%d", &n);
    long output[n];

    for (int i = 0; i < n; ++i) {
        gifts x = read_test_case();
        output[i] = calculate_minimum_cost_of_buying_gifts(&x);
    }
    print_array(output, n);

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

    long calculate_minimum_cost_of_buying_gifts(const gifts *const x)
    {
        if (are_original_costs_cheaper_or_equal_than_convertion_between_gifts(x))
            return calculate_minimum_standard_cost(x);
        return calculate_minimum_cost_in_converting_gifts(x);
    }

        bool are_original_costs_cheaper_or_equal_than_convertion_between_gifts(const gifts *const x)
        {
            long cost_to_convert_from_black_to_white = x->black_gift_cost + x->cost_to_convert_between_gifts;
            long cost_to_convert_from_white_to_black = x->white_gift_cost + x->cost_to_convert_between_gifts;
            return x->white_gift_cost <= cost_to_convert_from_black_to_white && x->black_gift_cost <= cost_to_convert_from_white_to_black;
        }

        long calculate_minimum_standard_cost(const gifts *const x)
        {
            return x->n_black_gifts * x->black_gift_cost + x->n_white_gifts * x->white_gift_cost;
        }

        long calculate_minimum_cost_in_converting_gifts(const gifts *const x)
        {
            long cost_to_convert_from_black_to_white = x->black_gift_cost + x->cost_to_convert_between_gifts;
            long total_gifts = x->n_black_gifts + x->n_white_gifts;

            if (x->white_gift_cost > cost_to_convert_from_black_to_white)
                return total_gifts * x->black_gift_cost + x->n_white_gifts * x->cost_to_convert_between_gifts;
            else
                return total_gifts * x->white_gift_cost + x->n_black_gifts * x->cost_to_convert_between_gifts;
        }

    void print_array(const long *const array, const int n)
    {
        for (int i = 0; i < n; ++i)
            printf("%ld\n", array[i]);
    }
