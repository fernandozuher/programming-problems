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
  keyboards.each do |keyboard|
    break if keyboard > budget
    remaining = budget - keyboard
    max_spent = [max_usb_price_within_budget(usb_drives, remaining, keyboard), max_spent].max
  end
  max_spent
end

def max_usb_price_within_budget(usb_drives, remaining, keyboard)
  left = 0
  right = usb_drives.length - 1
  max_spent = -1

  while left <= right
    mid = (left + right) / 2
    if usb_drives[mid] == remaining
      return [max_spent, keyboard + usb_drives[mid]].max
    elsif usb_drives[mid] < remaining
      max_spent = [max_spent, keyboard + usb_drives[mid]].max
      left = mid + 1
    else
      right = mid - 1
    end
  end

  max_spent
end

main
