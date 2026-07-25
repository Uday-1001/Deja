// https://leetcode.com/problems/largest-rectangle-in-histogram

class Solution {
public:
    
    void prevsmaller(vector<int>& heights , vector<int>&prevans)
    {
        stack<int>st;
        st.push(-1);

        for(int i=0 ; i<heights.size() ; i++)
        {
            int element = heights[i];

            while(st.top() != -1 && heights[st.top()] >= element)
            {
                st.pop();
            }
            //yha pr hume smaller num he mila hoga tbhi loop exit hua hai
            prevans.push_back(st.top());
            st.push(i);
        }
    }

    void nextsmaller(vector<int>& arr , vector<int>&nextans)
    {
        stack<int>st;
        st.push(-1);

        for(int i=arr.size()-1 ; i>=0 ; i--)
        {
            int element = arr[i];

            while(st.top() != -1 && arr[st.top()] >= element)
            {
                st.pop();
            }
            //yha pr hume smaller num he mila hoga tbhi loop exit hua hai
            nextans.push_back(st.top());
            st.push(i);
        }
    }

    int largestRectangleArea(vector<int>& heights) {
        vector<int>nextans;
        vector<int>prevans;

        nextsmaller(heights , nextans);
        reverse(begin(nextans) , end(nextans));

        prevsmaller(heights , prevans);

        //yhi mai bhul jata hu !!!
        for(int i=0 ; i<nextans.size() ; i++)
        {
            if(nextans[i] == -1)
            {
                nextans[i] = nextans.size();
            }
        }

        int maxi = INT_MIN;

        for(int i=0 ; i<nextans.size() ; i++)
        {
            int width = nextans[i] - prevans[i] - 1;
            int height = heights[i];
            maxi = max(maxi , width*height);
        }
    return maxi;
    }
};