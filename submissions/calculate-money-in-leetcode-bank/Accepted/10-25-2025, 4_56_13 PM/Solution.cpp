// https://leetcode.com/problems/calculate-money-in-leetcode-bank

class Solution {
public:
    int totalMoney(int n) {
        int whole_week = n/7;
        int remain_day = n%7;
        int money = 1;
        int sum = 0;

        while(whole_week--)
        {
            int day_money = money;
            int week = 7;
            while(week--)
            {
                sum += day_money;
                day_money++;
            }
            money += 1;
        }
        if(remain_day > 0)
        {
            while(remain_day--)
            {
                sum += money;
                money++;
            }
        }
    return sum;
    }
};