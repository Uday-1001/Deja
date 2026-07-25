// https://leetcode.com/problems/minimum-number-of-operations-to-move-all-balls-to-each-box

class Solution {
public:
    vector<int> minOperations(string boxes) {
        
        vector<int>answer(boxes.size());
        vector<int>left(boxes.size());
        vector<int>right(boxes.size());

        left[0] =0;
        int balls = boxes[0] - '0';
        for(int i =1; i<boxes.size();i++)
        {
           left[i] = left[i-1] + balls ;
           balls += boxes[i] - '0';
        }

        right[boxes.size()-1] =0;
        balls = boxes[boxes.size()-1] - '0';
        for(int i = boxes.size()-2 ; i>=0; i--)
        {
            right[i] = right [i+1] + balls;
            balls += boxes[i] - '0';
        }

        for(int i=0; i<boxes.size(); i++)
        {
            answer[i] = left[i] + right[i];
        }

        return answer;

   }
};