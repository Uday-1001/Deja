// https://leetcode.com/problems/simple-bank-system

class Bank {
public:
    vector<long long>balance;
    int n;
    bool isValid(vector<long long>&balance , int n , int account_no , long long amount)
    {
        if(account_no < 1 || account_no > n || amount > balance[account_no-1]) return false;
        return true;
    }

    Bank(vector<long long>& balance) {
        this->balance = balance;
        n = balance.size();
    }
    
    bool transfer(int account1, int account2, long long money) {
        if(isValid(balance , n , account1 , money) && account2>=1 && account2<=n)
        {
            balance[account2-1] += money;
            balance[account1-1] -= money;
            return true;
        }
        return false;
    }
    
    bool deposit(int account, long long money) {
        if(account <= n)
        {
            balance[account-1] += money;
            return true;
        }
        return false;
    }
    
    bool withdraw(int account, long long money) {
        if(isValid(balance , n , account , money))
        {
            balance[account-1] -= money;
            return true;
        }
        else return false;
    }
};

/**
 * Your Bank object will be instantiated and called as such:
 * Bank* obj = new Bank(balance);
 * bool param_1 = obj->transfer(account1,account2,money);
 * bool param_2 = obj->deposit(account,money);
 * bool param_3 = obj->withdraw(account,money);
 */