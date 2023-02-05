# Source: https://www.hackerrank.com/challenges/strange-advertising/problem?isFullScreen=true

def main
    days = gets.to_i
    cumulativeLikes = ViralAdvertising.new days
end

    class ViralAdvertising

        @days
        @cumulativeLikes

        def initialize days
            @days = days
            @cumulativeLikes = 0
        
            _viralAdvertising
            printCumulativeLikes
        end
        
            def _viralAdvertising
                shared, liked, cumulative = 5, 0, 0

                for _ in 1..@days
                    liked = (shared / 2).to_i
                    @cumulativeLikes += liked
                    shared = liked * 3
                end
            end

            def printCumulativeLikes
                puts @cumulativeLikes
            end
    end

main
