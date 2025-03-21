# https://www.hackerrank.com/challenges/30-inheritance/problem?isFullScreen=true

def main
  personal_data, student_data = read_input
  student = Student.new(personal_data, student_data)
  student.print_person
  puts "Grade: #{student.calculate_grade}"
end

def read_input
  first_name, last_name, id = gets.split
  gets # Skip new line about size of scores
  scores = gets.split.map(&:to_i)
  [PersonalData.new(first_name, last_name, id.to_i), StudentData.new(scores)]
end

PersonalData = Struct.new(:first_name, :last_name, :id)
StudentData = Struct.new(:scores)

class Person
  def initialize(personal_data)
    @first_name = personal_data.first_name
    @last_name = personal_data.last_name
    @id = personal_data.id
  end

  def print_person
    puts "Name: #{@last_name}, #{@first_name} \nID: #{@id}"
  end
end

class Student < Person
  def initialize(personal_data, student_data)
    super(personal_data)
    @scores = student_data.scores
  end

  def calculate_grade
    avg = @scores.sum / @scores.size

    if avg > 100 or avg < 40
      return 'T'
    elsif avg >= 90
      return 'O'
    elsif avg >= 80
      return 'E'
    elsif avg >= 70
      return 'A'
    elsif avg >= 55
      return 'P'
    end
    'D'
  end
end

main
