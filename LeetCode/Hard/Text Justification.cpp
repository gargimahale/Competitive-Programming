#include <bits/stdc++.h>

using namespace std;

/*
For the current line, the idea is to select a number of words based on their length. 
The selection is represented by the interval [i,j). Each time a word is selected, we 
reduce the remaining room, until the next word doesn't fit the line.

Then, we compute the gap as the quotient of the room and the number of words minus 
one (gap = room / (j - i - 1)). There is possibly remaining room as the remainder of this division 
isn't necessarily null (room -= gap * (j - i - 1)) . Therefore we add gap + 1 spaces for the room 
first gaps and gap spaces for the others, i.e. gap + (room-- > 0 ? 1 : 0).

Once the line is done (i == j), we start a new line and this until all words have been consumed (i == n).

Note : One should pay attention that the last word of a line is treated differently.
*/

class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        int n = words.size(), room, gap;
        vector<string> text;
        
        for (int i = 0, j = 0; i < n;) { // Two pointers i and j
            for (room = maxWidth; j < n and room >= j - i + words[j].length();) // While there is enough room
                room -= words[j++].length();

            gap = (j - i == 1) or (j == n) ? 0 : room / (j - i - 1); // If one word or last line gap is null
            room -= gap * (j - i - 1); // Remainder
            
            text.push_back("");
            while (i < j - 1)
                text.back().append(words[i++]).append(gap + (room-- > 0 ? 1 : 0), ' ');
            text.back().append(words[i++]).append(max(room, 0), ' ');
        }
        
        return text;
    }
};
