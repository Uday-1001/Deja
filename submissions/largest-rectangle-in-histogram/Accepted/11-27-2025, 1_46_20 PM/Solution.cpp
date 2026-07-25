// https://leetcode.com/problems/largest-rectangle-in-histogram

class Solution {
public:
    
    vector<int> prevsmaller(vector<int>& heights)
    {
        stack<int>st;
        st.push(-1);
        vector<int>prevans(heights.size() , 0);

        for(int i=0 ; i<heights.size() ; i++)
        {
            int element = heights[i];

            while(st.top() != -1 && heights[st.top()] >= element)
            {
                st.pop();
            }
            prevans[i] = st.top();
            st.push(i);
        }
        return prevans;
    }

    vector<int> nextsmaller(vector<int>& heights)
    {
        stack<int>st;
        st.push(-1);
        vector<int>nextans(heights.size() , 0);

        for(int i=heights.size()-1 ; i>=0 ; i--)
        {
            int element = heights[i];

            while(st.top() != -1 && heights[st.top()] >= element)
            {
                st.pop();
            }
            nextans[i] = st.top();
            st.push(i);
        }
    return nextans;
    }

    int largestRectangleArea(vector<int>& heights) {
        auto nextans = nextsmaller(heights);
        auto prevans = prevsmaller(heights);

        for(int i=0 ; i<nextans.size() ; i++)
        {
            if(nextans[i] == -1) nextans[i] = nextans.size();
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