// https://leetcode.com/problems/number-of-elapsed-seconds-between-two-times

class Solution {
public:
    int convert(string t){
        int h = stoi(t.substr(0,2));
        int m = stoi(t.substr(3,2));
        int s = stoi(t.substr(6,2));

        return h* 3600 + m *60 + s;
    }
    int secondsBetweenTimes(string startTime, string endTime) {
        int start = convert(startTime);
        int end = convert(endTime);

        return end - start;
    }
};