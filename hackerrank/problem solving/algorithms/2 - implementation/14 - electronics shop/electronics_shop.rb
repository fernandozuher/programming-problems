# https://www.hackerrank.com/challenges/electronics-shop/problem?isFullScreen=true

def main
  budget = read_numbers.first
  keyboards = read_numbers.uniq.sort
  usb_drives = read_numbers.uniq.sort
  puts calculate_money_spent(keyboards, usb_drives, budget)
end

def read_numbers
  gets.split.map(&:to_i)
end

def calculate_money_spent(keyboards, usb_drives, budget)
  max_spent = -1
  i = 0
  j = usb_drives.length - 1

  while i < keyboards.length && j >= 0
    break if keyboards[i] >= budget

    sum = keyboards[i] + usb_drives[j]

    if sum > budget
      j -= 1
    elsif sum == budget
      return budget
    else
      max_spent = sum if sum > max_spent
      i += 1
    end
  end

  max_spent
end

main
