// https://leetcode.com/problems/course-schedule-iii

class Solution {
public:
    int scheduleCourse(vector<vector<int>>& courses) {
        sort(courses.begin() , courses.end());

        int course_done = 0;
        int sumofdays = 0;

        for(auto it : courses)
        {
            int duration = it[0];
            int lastday = it[1];

            int newdays = sumofdays + duration;
            if(newdays <= lastday)
            {
                course_done++;
                sumofdays = newdays;
            } 
            else
            {
                newdays -= duration;
            }
        }
        return course_done;
    }
};