/*
Question# + Difficulty + Topic + Company + Similar_Question
[347] [Top K Frequent Elements] [Medium] [Hash Table Heap ] 
[Yelp Pocket Gems ] 
[192 215 451 659 692].cpp
*/

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map <int,int> hash;
        vector<int> res;
        priority_queue <pair<int,int>> heap;
        for(int i=0;i<nums.size();i++)
        {
            hash[nums[i]]++;
        }
        
        //Use Hash to generate Max Heap with key value: frequency
        //Then Extract Max for K frequent elements
        /*
            template <class T1, class T2>
              bool operator<(const pair<T1, T2>& x, const pair<T1, T2>& y)
            { return x.first < y.first || (!(y.first < x.first) && x.second < y.second) }
            
            So we just need to use frequency as the first to ensure priority queue is 
            properly maintained
        */
        for(auto iter = hash.begin();iter!=hash.end();iter++)
        {
            heap.push(make_pair(iter->second,iter->first));
            if(heap.size()>(hash.size()-k))//minimize heap size
            {
                res.push_back(heap.top().second);
                heap.pop();
            }
        }
        return res;
    }
};
