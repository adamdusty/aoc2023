# AoC 2023 Notes

## Day 1

Puzzle one was easy. I solved by filtering the input on `isdigit`, and parsing the first and last digit together.

Puzzle two was more difficult. My first instinct was to find and replace any substring that matched a digit, but that doesn't work because the spelling of digits can overlap (e.g. xxxoneightxxx -> xxx1ightxxx). Also I didn't feel like fighting with regex, so I abandoned that idea quickly. My next thought was to work through the string char by char and check after each append if a digit had been spelled out or if the char was a digit. This worked for finding the first digit, but again, since words can overlap, it would erroneously determine the last digit if the last digit was a word that overlapped with another. I solved this by just doing the same algorithm in reverse. Build the string from the last char, pushing characters into the front of the string. If a char is a digit or the string contains one of the digit words, return the digit char. Put the digit characters together and parse as an int from a string. I may go back and clean things up, but it is good enough for now.

### Thoughts

I used ranges to solve some issues. I think if I used ranges-v3 instead of STL ranges, I could have solved puzzle one in one or two lines. I'm not sure how I feel about using ranges. The algorithms are nice, but it was difficult to wrap my head around some of the return types and lambdas.

Inline namespaces are super useful for this. I was able to keep all the code and tests without needing to update the solution executable.

## Day 2

### Puzzle 1

This puzzle kind of sucked. Not because it was difficult, but because parsing is boring. I did a ton of tests because I kept getting slightly wrong answers, which I eventually figured out was due to an off-by-one error. To solve the puzzle, I parsed each number, and if the number was greater than 12 I checked the next letter since the first letter of each color was unique. Unfortunately I was incrementing the index beforehand and because the switch statement didn't have a default case, I wasn't catching that I was calculating the wrong values. Eventually I caught it with the millionth test, and it was an easy fix. I probably could have properly parsed each entire game, but that's unnecessary. I just failed as early as possible, and summed the game id's that never failed.

### Puzzle 2

Another annoying puzzle, with an optimal solution involving actually parsing each line. Again I avoided this by just splitting each line into draws by `;` and each draw into colors by `,`. Then I just alternated parsing numbers and identifiers keeping track of the max value along the way. Sum the product of each max from each game, and the answer was quick.

### Thoughts

Writing parsers isn't much fun. This puzzle encouraged me to put some more string functions into my utility library. Getting slightly more comfortable with ranges. Ranges hurts from lack of conversion to collections and from lack of accumulate/reduce in ranges library. I could definitely go back and implement a much cleaner solution, but I didn't enjoy today's puzzle at all, so I'm not going to do that. I don't feel I learned much. I also did a lot of unnecessary data copies, but I don't care to fix those either.
