// https://leetcode.com/problems/number-of-students-unable-to-eat-lunch

class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        int ones = 0;
        int zeros = 0;

        for(auto stud : students) 
        {
            if(stud == 1) ones++;
            else zeros++;
        }

        for(auto choice : sandwiches)
        {
            if(choice == 1)
            {
                if(ones > 0) ones--;
                else return zeros;
            }
            else 
            {
                if(zeros > 0) zeros--;
                else return ones;
            }
        }
    return 0;
    }
};