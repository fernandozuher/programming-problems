# https://www.hackerrank.com/challenges/sock-merchant/problem?isFullScreen=true

def main
  _n = gets.to_i
  array = read_int_array
  p sock_merchant(array)
end

  def read_int_array
    gets.split.map(&:to_i)
  end
  
  def sock_merchant(socks)
    pairs = 0
    socks_pairing = Hash.new
  
    socks.each { |sock|
      if socks_pairing[sock]
        pairs += 1
      end
      socks_pairing[sock] = !socks_pairing[sock]
    }
    
    pairs
  end

main
