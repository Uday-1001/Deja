// https://leetcode.com/problems/text-justification

class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string>ans;
        vector<string>currentLine;

        int curr_total_char = 0;

        for(int i =0 ;i<words.size(); i++)
        {
            string &curr_word = words[i];
            int curr_line_spaces = currentLine.size();
            // check if addition of the word does exceed the word limit of the line 
            if(curr_total_char + curr_line_spaces + curr_word.size() > maxWidth)
            {
                //FULLY JUSTIFIED CASE

                // exceeded limit of maxWidth in the current line 
                int extra_spaces = maxWidth - curr_total_char;
                // extra spaces needed in b/w the words and the even distribution of them
                int spaces_in_bw = extra_spaces / max(1,(int)(currentLine.size()-1));
                int remainder = extra_spaces % max(1,(int)(currentLine.size()-1));

                //we dont need spaces after last word
                for(int j =0 ; j<currentLine.size()-1 ;j++)
                {
                    for(int k =0 ; k <spaces_in_bw ; k++)
                    {
                        currentLine[j] += " ";
                        // for uneven distribution from the left as the priority
                        if(remainder > 0)
                        {
                            currentLine[j] += " ";
                            remainder--;
                        }
                    }
                }
            // single word in line -> keep it left justified.
            if(currentLine.size() == 1)
            {
                while(extra_spaces--)
                //all spaces added in the word with left justification.
                currentLine[0] += " ";
            }

            //FINAL LINE PREPARATION
            string final_line = "";
            for(string WordWithSpaces : currentLine)
            {
                final_line += WordWithSpaces;
            }

            ans.push_back(final_line);
            currentLine.clear();
            curr_total_char =0;
            }
            // pushing the current word in the vector so as to get the words 
            currentLine.push_back(curr_word);
            // calculating the size  of the cuurent wor and updating the vector
            curr_total_char += curr_word.size();
        }
        // LETS TAKE CARE OF LAST LINE
        //add 1 spaces b/w words
        string final_line = "";
        for(auto word : currentLine)
        {
            final_line += word + " ";
        }
        final_line.pop_back(); // removed last extra space

        int left_spaces =  maxWidth - final_line.size();

        while(left_spaces--)
        {
        final_line += " ";
        }
        ans.push_back(final_line);

    return ans;
    }
};