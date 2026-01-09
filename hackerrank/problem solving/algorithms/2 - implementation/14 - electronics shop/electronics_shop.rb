# https://www.hackerrank.com/challenges/electronics-shop/problem?isFullScreen=true

def main
  budget = read_numbers.first
  keyboards = preprocess_input(read_numbers)
  usb_drives = preprocess_input(read_numbers)
  puts calculate_money_spent(keyboards, usb_drives, budget)
end

def read_numbers
  gets&.split&.map!(&:to_i)
end

def preprocess_input(arr)
  arr.uniq!
  arr.sort!
end

# n: length of array keyboards
# m: length of array usb_drives
# T: O(n + m)
# S: O(1) extra space
def calculate_money_spent(keyboards, usb_drives, budget)
  return -1 if keyboards[0] >= budget || usb_drives[0] >= budget

  max_spent = -1
  idx_k, idx_ud = 0, usb_drives.size - 1

  while idx_k < keyboards.size && idx_ud >= 0
    break if keyboards[idx_k] >= budget

    current_sum = keyboards[idx_k] + usb_drives[idx_ud]
    return budget if current_sum == budget

    if current_sum > budget
      idx_ud -= 1
    else
      max_spent = [max_spent, current_sum].max
      idx_k += 1
    end
  end

  max_spent
end

main if __FILE__ == $0
