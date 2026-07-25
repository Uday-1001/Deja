// https://leetcode.com/problems/smallest-range-covering-elements-from-k-lists

class Solution {
public:
    class Info
    {
        public:
        int data;
        int row;
        int col;

        Info(int x , int y , int z)
        {
            this->data = x;
            this->row = y;
            this->col = z;
        }
    };

    class comparator
    {
        public:
        bool operator()(Info* a , Info* b)
        {
            return a->data > b->data;
        }
    };

    vector<int> smallestRange(vector<vector<int>>& nums) {
        priority_queue<Info* , vector<Info*> , comparator>pq;
        vector<int>ans;

        int total_row = nums.size();
        int total_col = nums[0].size();

        int mini = INT_MAX;
        int maxi = INT_MIN;

        for(int i=0 ; i<total_row ; i++)
        {
            int first_elem = nums[i][0];
            Info* temp = new Info(first_elem , i , 0);
            pq.push(temp);

            //update the maxi and mini for these elements 
            maxi = max(maxi , first_elem);
            mini = min(mini , first_elem);
        }
        //ans vector's starting and ending -> it makes the range of the answer vector
        int start = mini;
        int end = maxi;

        while(!pq.empty())
        {
            auto front = pq.top();
            pq.pop();

            int front_data = front->data;
            int front_row = front->row;
            int front_col = front->col;

            //surely the first elem from the minheap will be the smallest value -> read question again!!
            mini = front_data;

            //if the difference is smaller than seen before , then update both the ends of the range to new limits
            if((maxi - mini) < (end - start))
            {
                start = mini;
                end = maxi;
            }

            //recalculate the size of each col as it can be different for each list 
            int total_curr_col = nums[front_col].size();

            if(front_col+1 < total_curr_col)
            {
                int next_elem = nums[front_row][front_col+1];
                Info* temp = new Info(next_elem , front_row , front_col+1);
                pq.push(temp);
 
                maxi = max(maxi , next_elem);
                mini = min(mini, next_elem);
            }
            else
            //if the list ends before others means that elements can be selected out of that list's values ...so it is not applicable as per question..
                break;
        }
        ans.push_back(start);
        ans.push_back(end);
        return ans; 
    }
};