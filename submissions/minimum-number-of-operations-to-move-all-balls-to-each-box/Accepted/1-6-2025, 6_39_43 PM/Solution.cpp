// https://leetcode.com/problems/minimum-number-of-operations-to-move-all-balls-to-each-box

class Solution {
public:
    vector<int> minOperations(string boxes) {
       vector<int>result(boxes.size());
       for(int i =0; i<boxes.size(); i++)
       {
        for(int j=0 ; j<boxes.size(); j++)
         {
            if(i != j && boxes[j]=='1')
            {
                result[i] += abs(i-j);           
            }
         } 
      }
      return result;
   }
};