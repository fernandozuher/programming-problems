# https://www.hackerrank.com/challenges/kangaroo/problem?isFullScreen=true

def main
  array = read_int_array
  puts kangaroo(array)
end

  def read_int_array
    gets.split.map(&:to_i)
  end
  
  def kangaroo(array)
    x1, v1, x2, v2 = array
  
    if v2 >= v1
      return 'NO'
    end
  
    while x1 < x2
      x1 += v1
      x2 += v2
    end
  
    x1 == x2 ? 'YES' : 'NO'
  end

main
