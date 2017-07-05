//Question# + Difficulty + Topic + Company + Similar_Question
//[170] [Two Sum III] [Easy] [Hash Table Design] 
//[LinkedIn] 
//[1 288].cpp

/*C++ my own hash table approah*/
class TwoSum {
public:
    /** Initialize your data structure here. */
    unordered_map<int,int> hash;
    TwoSum() 
    {
    }
    
    
    /** Add the number to an internal data structure.. */
    void add(int number) 
    {
        hash[number]++;
    }
    
    /** Find if there exists any pair of numbers which sum is equal to the value. */
    bool find(int target) 
    {
        //Start Iteration
        for (auto iter:hash)
        {
            int target_num = target - iter.first;
            if(hash.find(target_num)!=hash.end())
            {
                if((iter.second>1)||(target_num!=iter.first))
                    //Not the same index, e.g. target = 8 = 4 + 4
                {
                    return true;
                }
            }
        }
        return false;
    }
};

/**
 * Your TwoSum object will be instantiated and called as such:
 * TwoSum obj = new TwoSum();
 * obj.add(number);
 * bool param_2 = obj.find(value);
 */




/*C++ Two Pointer Approach Faster! */
class TwoSum {
private:
    vector<int> list;
    
    int getupper(vector<int>& array, int& target)
    {
        int left = 0;
        int right = array.size()-1;
        
        while(left < right)
        {
            int mid = left + (right-left)/2;
            if(array[mid] <= target)
                left = mid+1;
            else
                right = mid;
        }

        return (array[left] == target) ? left+1 : left;
    }
    
public:
    /** Initialize your data structure here. */
    TwoSum() {

    }
    
    /** Add the number to an internal data structure.. */
    void add(int number) {
        std::vector<int>::iterator index = list.begin();
        if(list.size())
            //index = getupper(list, number);
            index = std::upper_bound(list.begin(), list.end(), number);
        list.insert(index, number);
    }
    
    /** Find if there exists any pair of numbers which sum is equal to the value. */
    bool find(int value) {
        int left = 0;
        int right = list.size() - 1;
        
        while(left < right)
        {
            int sum = list[left] + list[right];
            if(sum == value)
                return true;
            else if(sum < value)
                left++;
            else
                right--;
        }
        
        return false;
    }
};

/**
 * Your TwoSum object will be instantiated and called as such:
 * TwoSum obj = new TwoSum();
 * obj.add(number);
 * bool param_2 = obj.find(value);
 */
