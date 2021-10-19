class Bank {
public:
    vector<long long> balance;
    int accounts = 0;
    Bank(vector<long long>& balanceList) {
        balance = balanceList;
        accounts = balanceList.size();
    }

    bool doesAccountExist(int account) {
        return account <= accounts;
    }

    bool transfer(int account1, int account2, long long money) {
        if (!doesAccountExist(account1) || !doesAccountExist(account2)) return false;
        long long amount1 = balance[account1 - 1];
        bool isValid =  withdraw(account1, money);
        if (!isValid) return false;
        balance[account2 - 1] += money;
        return true;
    }

    bool deposit(int account, long long money) {
        if (!doesAccountExist(account)) return false;
        balance[account - 1] += money;
        return true;
    }

    bool withdraw(int account, long long money) {
        if (!doesAccountExist(account)) return false;
        long long amount = balance[account - 1];
        if (money > amount) return false;
        balance[account - 1] = amount - money;
        return true;
    }
};

/**
 * Your Bank object will be instantiated and called as such:
 * Bank* obj = new Bank(balance);
 * bool param_1 = obj->transfer(account1,account2,money);
 * bool param_2 = obj->deposit(account,money);
 * bool param_3 = obj->withdraw(account,money);
 */