# https://www.hackerrank.com/challenges/30-nested-logic/problem?isFullScreen=true

require 'date'

def main
  returned_date = read_date
  due_date = read_date
  puts returned_date <= due_date ? 0 : FineOnDelay.new(returned_date, due_date).fine
end

def read_date
  date = gets
  Date.strptime(date, "%d %m %Y")
end

class FineOnDelay
  FINES = {
    year: 10000,
    month: 500,
    day: 15
  }.freeze

  attr_reader :fine

  def initialize(returned_date, due_date)
    @returned_date = returned_date
    @due_date = due_date
    @fine = calculate_fine
  end

  private

  def calculate_fine
    late_by_year || late_by_month || late_by_day
  end

  def late_by_year
    FINES[:year] if @returned_date.year > @due_date.year
  end

  def late_by_month
    return unless same_year?
    return unless @returned_date.month > @due_date.month
    (@returned_date.month - @due_date.month) * FINES[:month]
  end

  def same_year?
    @returned_date.year == @due_date.year
  end

  def late_by_day
    return unless same_year? && same_month?
    return unless @returned_date.day > @due_date.day
    (@returned_date.day - @due_date.day) * FINES[:day]
  end

  def same_month?
    @returned_date.month == @due_date.month
  end
end

main
