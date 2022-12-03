class Person
    def initialize(firstName, lastName, id)
        @firstName = firstName
        @lastName = lastName
        @id = id
    end
    
    def printPerson()
        print("Name: ",@lastName , ", " + @firstName ,"\nID: " , @id)
    end
end

class Student < Person
    
    def initialize(firstName, lastName, id, testScores)
        super(firstName, lastName, id)
        @testScores = testScores
    end

    def calculate()
        avg = @testScores.reduce(:+).to_i / @testScores.size

        if avg >= 90 && avg <= 100
            return "O"
        elsif avg >= 80 && avg < 90
            return "E"
        elsif avg >= 70 && avg < 80
            return "A"
        elsif avg >= 55 && avg < 70
            return "P"
        elsif avg >= 40 && avg < 55
            return "D"
        else
            return "T"
        end  
    end  
end

input = gets.split()
firstName = input[0]
lastName = input[1]
id = input[2].to_i
numScores = gets.to_i
scores = gets.strip().split().map!(&:to_i)
s = Student.new(firstName, lastName, id, scores)
s.printPerson           
print("\nGrade: " + s.calculate)
