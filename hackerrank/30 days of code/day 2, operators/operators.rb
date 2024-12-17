# https://www.hackerrank.com/challenges/30-operators/problem?isFullScreen=true

def main
  meal_cost = gets.to_f
  tip_percent = gets.to_i
  tax_percent = gets.to_i
  solve(meal_cost, tip_percent, tax_percent)
end

def solve(meal_cost, tip_percent, tax_percent)
  total_cost = meal_cost + meal_cost * tip_percent / 100 + meal_cost * tax_percent / 100
  puts "%.0f" % (total_cost)
end

main
