// https://www.hackerrank.com/challenges/30-operators/problem?isFullScreen=true

#include <stdio.h>

void solve(const double meal_cost, const int tip_percent, const int tax_percent);

int main()
{
    double meal_cost;
    int tip_percent, tax_percent;
    scanf("%lf %d %d", &meal_cost, &tip_percent, &tax_percent);

    solve(meal_cost, tip_percent, tax_percent);

    return 0;
}

    void solve(const double meal_cost, const int tip_percent, const int tax_percent)
    {
        double total_cost = meal_cost + meal_cost * tip_percent / 100 + meal_cost * tax_percent / 100;
        printf("%.0lf", total_cost);
    }
