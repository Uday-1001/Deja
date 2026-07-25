// https://leetcode.com/problems/sum-of-subarray-ranges

class Solution {
public:
    vector<int> prevsmaller(vector<int>& arr)
    {
        stack<int>st;
        st.push(-1);

        vector<int>prevans(arr.size() , -1);

        for(int i=0 ; i<arr.size() ; i++)
        {
            int element = arr[i];

            while(!st.empty() && st.top() != -1 && arr[st.top()] > element)
            {
                st.pop();
            }
            //yha pr hume smaller num he mila hoga tbhi loop exit hua hai
            prevans[i] = st.top();
            st.push(i);
        }
    return prevans;   
    }

    vector<int> nextsmaller(vector<int>& arr)
    {
        stack<int>st;
        st.push(-1);

        vector<int>nextans(arr.size() , -1);

        for(int i=arr.size()-1 ; i>=0 ; i--)
        {
            int element = arr[i];

            while(!st.empty() && st.top() != -1 && arr[st.top()] >= element)
            {
                st.pop();
            }
            //yha pr hume smaller num he mila hoga tbhi loop exit hua hai
            nextans[i] = st.top();
            st.push(i);
        }
    return nextans;
    }

    vector<int> prevgreater(vector<int>& arr)
    {
        stack<int>st;
        st.push(-1);

        vector<int>prevans(arr.size() , -1);

        for(int i=0 ; i<arr.size() ; i++)
        {
            int element = arr[i];

            while(!st.empty() && st.top() != -1 && arr[st.top()] < element)
            {
                st.pop();
            }
            //yha pr hume smaller num he mila hoga tbhi loop exit hua hai
            prevans[i] = st.top();
            st.push(i);
        }
    return prevans;   
    }

    vector<int> nextgreater(vector<int>& arr)
    {
        stack<int>st;
        st.push(-1);

        vector<int>nextans(arr.size() , -1);

        for(int i=arr.size()-1 ; i>=0 ; i--)
        {
            int element = arr[i];

            while(!st.empty() && st.top() != -1 && arr[st.top()] <= element)
            {
                st.pop();
            }
            //yha pr hume smaller num he mila hoga tbhi loop exit hua hai
            nextans[i] = st.top();
            st.push(i);
        }
    return nextans;
    }

    long long sumSubarrayMins(vector<int>& arr) {

        auto prevans = prevsmaller(arr);
        auto nextans = nextsmaller(arr);

        long long sum =0;
        for(int i=0 ; i<arr.size() ; i++)
        {
            auto nexti = nextans[i] == -1 ? arr.size() : nextans[i];
            auto previ = prevans[i];

            long long left = i - previ;
            long long right = nexti - i;
            sum += (left * right * arr[i]);
        }
    return sum;
    }

    long long sumSubarrayMaxs(vector<int>& arr) {

        auto prevans = prevgreater(arr);
        auto nextans = nextgreater(arr);

        long long sum =0;
        for(int i=0 ; i<arr.size() ; i++)
        {
            auto nexti = nextans[i] == -1 ? arr.size() : nextans[i];
            auto previ = prevans[i];

            long long left = i - previ;
            long long right = nexti - i;
            sum += (left * right * arr[i]);
        }
    return sum;
    }

    long long subArrayRanges(vector<int>& nums) {
        auto subarrmin = sumSubarrayMins(nums);
        auto subarrmax = sumSubarrayMaxs(nums);

        long long total_ans = subarrmax - subarrmin;
        return total_ans;
    }
};