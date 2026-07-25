// https://leetcode.com/problems/solving-questions-with-brainpower

class Solution {
public:
    int recursion(vector<vector<int>>& questions , int index)
    {
        //base case
        if(index >= questions.size())
        return 0;

        int points = questions[index][0];
        int brain = questions[index][1];
        //include -> question ko solve kiya to kya hua 
        int solved = points + recursion(questions , index + brain + 1);
        //exclude -> question ko solve he nhi kiya to kya hua
        int unsolved = recursion(questions , index + 1);
        //returning the max of the both possibilities
        return max(solved , unsolved);
    }
    
    long long mostPoints(vector<vector<int>>& questions) {
        return recursion(questions , 0);
    }
};