# https://www.hackerrank.com/challenges/compare-the-triplets/problem?isFullScreen=true

def main
  triplet_a = read(Integer, Array)
  triplet_b = read(Integer, Array)
  score_a, score_b = compare_triplets(triplet_a, triplet_b)
  puts "#{score_a} #{score_b}"
end

require 'set'

CASTERS = {
  Integer => ->(s) { Integer(s) },
  Float => ->(s) { Float(s) },
  String => ->(s) { s }
}.freeze

def read(cast = String, container = nil)
  converter = CASTERS.fetch(cast) { cast.respond_to?(:call) ? cast : cast.method(:new) }

  if container.nil?
    line = gets.chomp
    return cast == String ? line : converter.call(line)
  end

  unless [Array, Set].include?(container)
    raise TypeError,
          "Unsupported container: #{container.inspect}. Must be Array or Set."
  end

  tokens = gets.chomp.split.map! { converter.call(_1) }
  container == Set ? Set.new(tokens) : tokens
end

# n: length of a and b = 3
# T: O(3) => O(1)
# S: O(1) extra space
def compare_triplets(triplet_a, triplet_b)
  score_a, score_b = 0, 0

  triplet_a.zip(triplet_b).each do |ta, tb|
    if ta > tb
      score_a += 1
    elsif tb > ta
      score_b += 1
    end
  end

  [score_a, score_b]
end

main if __FILE__ == $0
