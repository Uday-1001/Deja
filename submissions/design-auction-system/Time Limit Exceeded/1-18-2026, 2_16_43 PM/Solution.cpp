// https://leetcode.com/problems/design-auction-system

class AuctionSystem {
public:
    unordered_map<int , unordered_map<int,int>>mp;
    //itemId -> [userId -> bidamount]
    AuctionSystem() {
    }
    
    void addBid(int userId, int itemId, int bidAmount) {
        mp[itemId][userId] = bidAmount;
    }
    
    void updateBid(int userId, int itemId, int newAmount) {
        mp[itemId][userId] = newAmount;
    }
    
    void removeBid(int userId, int itemId) {
        if(!mp.count(itemId)) return;

        mp[itemId].erase(userId);
        if(mp[itemId].empty()) mp.erase(itemId);
    }
    
    int getHighestBidder(int itemId) {
        int biggestamt = -1;
        int biggestuser = -1;

        auto map = mp[itemId];
        for(auto x : map)
        {   
            auto[user , amount] = x;
            if(amount > biggestamt)
            {
                biggestamt = amount;
                biggestuser = user;
            } 
            else if(amount == biggestamt) 
            {
                if(user > biggestuser) biggestuser = user;
            }
        }
        return biggestuser;
    }
};

/**
 * Your AuctionSystem object will be instantiated and called as such:
 * AuctionSystem* obj = new AuctionSystem();
 * obj->addBid(userId,itemId,bidAmount);
 * obj->updateBid(userId,itemId,newAmount);
 * obj->removeBid(userId,itemId);
 * int param_4 = obj->getHighestBidder(itemId);
 */