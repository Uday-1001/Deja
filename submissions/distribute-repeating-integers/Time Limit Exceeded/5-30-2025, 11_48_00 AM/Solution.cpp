// https://leetcode.com/problems/distribute-repeating-integers

class Solution {
public:
    bool solve(vector<int>&count , vector<int>&quantity , int customer)
    {
        //base case
        //it means we have attended all the customers successfully 
        if(customer == quantity.size())
        {
            return true;
        }

        //ek case hum solve karenge baaki recursion dekhlega 
        for(int i = 0  ;i<count.size() ; i++)
        {
            if(count[i] >= quantity[customer])
            {
                count[i] -= quantity[customer];

                //recursive call krdo aage ke ans ke liye
                bool recursive_ans = solve(count , quantity, customer + 1);
                if(recursive_ans == true)
                {
                    return true;
                }
                //backtracking 
                //restore the count 
                count[i] += quantity[customer];
            }
        }
        return false;
    }

    bool canDistribute(vector<int>& nums, vector<int>& quantity) {
        int n = quantity.size();
        
        unordered_map<int,int>freq;
        //store the frqe of each no. of nums
        for(auto num : nums)
        {
            freq[num]++;
        }
        //made a vector for count of the nums element 
        vector<int>count;
        for(auto it : freq)
        {
            count.push_back(it.second);
        }

        return solve(count , quantity , 0);
    }
};