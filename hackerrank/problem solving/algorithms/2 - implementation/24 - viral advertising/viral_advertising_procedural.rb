# Source: https://www.hackerrank.com/challenges/strange-advertising/problem?isFullScreen=true

def main
    days = gets.to_i
    cumulativeLikes = viralAdvertising days
    puts cumulativeLikes
end

    def viralAdvertising days
        shared, liked, cumulative = 5, 0, 0

        for _ in 1..days
            liked = (shared / 2).to_i
            cumulative += liked
            shared = liked * 3
        end

        cumulative
    end

main
