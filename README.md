# AoC 2023 Notes

## Day 1

Puzzle one was easy. I solved by filtering the input on `isdigit`, and parsing the first and last digit together.

Puzzle two was more difficult. My first instinct was to find and replace any substring that matched a digit, but that
doesn't work because the spelling of digits can overlap (e.g. xxxoneightxxx -> xxx1ightxxx). Also I didn't feel like fighting with regex, so
I abandoned that idea quickly. My next thought was to work through the string char by char and check after each append if a digit had
been spelled out or if the char was a digit. This worked for finding the first digit, but again, since words can overlap, it would erroneously
determine the last digit if the last digit was a word that overlapped with another. I solved this by just doing the same algorithm in reverse.
Build the string from the last char, pushing characters into the front of the string. If a char is a digit or the string contains one
of the digit words, return the digit char. Put the digit characters together and parse as an int from a string. I may go back and clean things up,
but it is good enough for now.

### Learned

I used ranges to solve some issues. I think if I used ranges-v3 instead of STL ranges, I could have solved puzzle one in one or two lines. I'm
not sure how I feel about using ranges. The algorithms are nice, but it was difficult to wrap my head around some of the return types and lambdas.

Inline namespaces are super useful for this. I was able to keep all the code and tests without needing to update the solution executable.
