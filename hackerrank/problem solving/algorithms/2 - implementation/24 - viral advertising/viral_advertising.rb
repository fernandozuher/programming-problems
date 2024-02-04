# https://www.hackerrank.com/challenges/strange-advertising/problem?isFullScreen=true

def main
    days = gets.to_i
    puts viral_advertising(days)
end

    def viral_advertising(days)
        shared, liked, cumulative = 5, 0, 0

        days.times do
            liked = (shared / 2).to_i
            cumulative += liked
            shared = liked * 3
        end

        cumulative
    end

main
