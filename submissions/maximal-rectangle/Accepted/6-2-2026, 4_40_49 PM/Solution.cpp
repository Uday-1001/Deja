// https://leetcode.com/problems/maximal-rectangle

class Solution {
public:

    void prevsmaller(vector<int>& heights , vector<int>&nextans)
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
            nextans.push_back(st.top());
            st.push(i);
        }
    }

    void nextsmaller(vector<int>& arr , vector<int>&prevans)
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
            prevans.push_back(st.top());
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

    int maximalRectangle(vector<vector<char>>& matrix) {
        vector<vector<int>>v;
        int n = matrix.size();
        int m = matrix[0].size();

        for(int i=0 ; i<n ; i++)
        {
            vector<int>temp;
            for(int j=0; j<m ; j++)
            {
                temp.push_back(matrix[i][j] - '0');
            }
            v.push_back(temp);
        }

        int area = largestRectangleArea(v[0]);
        
        for(int i=1 ; i<n ; i++)
        {
            for(int j=0 ; j<m ; j++)
            {
                if(v[i][j] == 1)
                {
                    v[i][j] += v[i-1][j];
                }
                else
                {
                    v[i][j] = 0;
                }
            }
        area = max(area , largestRectangleArea(v[i]));
        }
        return area;
    }
};