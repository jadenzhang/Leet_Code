/*
Question# + Difficulty + Topic + Company + Similar_Question
[146] [LRU Cache] [Hard] [Design] 
[Google Uber Facebook Twitter Zenefits Amazon Microsoft Snapchat Yahoo Bloomberg Palantir ] 
[460 588 604].cpp
*/

class LRUCache {
public:
    LRUCache(int capacity):my_capacity(capacity) {}
    
    int get(int key) 
    {
        unordered_map<int, my_list::iterator>::iterator found_itr = hash.find(key);
        if(found_itr==hash.end()) return -1;//Not exist
        mlist.splice(mlist.begin(),mlist, found_itr->second); //move node to front
        return found_itr->second->second;   //value of node
    }
    
    
    void put(int key, int value) {
        unordered_map<int, my_list::iterator>::iterator found_itr = hash.find(key);
        if(found_itr!= hash.end()) // has key
        {
            mlist.splice(mlist.begin(),mlist, found_itr->second); //move node to front
            found_itr->second->second = value; //hashitr-> listitr->val update
            return;
        }
        
        if(hash.size()==my_capacity) //reach upperlimit
        {
            int delete_key = mlist.back().first;
            mlist.pop_back();   // remove from list
            hash.erase(delete_key); // remove from hash
        }
        
        mlist.emplace_front(key,value); // create new key for list
        hash[key] = mlist.begin(); // create relationship between key and value
    }
private:
    typedef list<pair<int,int>> my_list;
    my_list mlist;
    unordered_map<int, my_list::iterator> hash;
    int my_capacity;
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache obj = new LRUCache(capacity);
 * int param_1 = obj.get(key);
 * obj.put(key,value);
 */
