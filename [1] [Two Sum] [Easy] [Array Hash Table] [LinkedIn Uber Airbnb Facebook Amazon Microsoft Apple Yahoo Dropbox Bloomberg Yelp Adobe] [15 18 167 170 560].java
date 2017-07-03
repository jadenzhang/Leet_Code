//Question# + Difficulty + Topic + Company + Similar_Question
//[1] [Two Sum] [Easy] [Array Hash Table] 
//[LinkedIn Uber Airbnb Facebook Amazon Microsoft Apple Yahoo Dropbox Bloomberg Yelp Adobe] 
//[15 18 167 170 560].java

/* C++ */
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        //Use hash table to make search O(1). Number : Index
        
        //Add to hash
        unordered_map<int,int> hash;
        for (int i = 0; i<nums.size();i++)
        {
            hash[nums[i]] = i;
        }
        
        //Start Iteration
        for (int i =0;i<nums.size();i++)
        {
            int target_num = target - nums[i];
            if(hash.find(target_num)!=hash.end())
            {
                if(hash[target_num]!=i)//Not the same index, e.g. target = 8 = 4 + 4
                {
                    return vector<int> {i,hash[target_num]};
                }
            }
        }
    }
};


/* Java */
public class Solution {
    public int[] twoSum(int[] nums, int target) {
        
        //Use hash table to make search O(1). Number : Index
        
        //Add to hash
        HashMap<Integer, Integer> hash = new HashMap<Integer, Integer>();        
        for (int i = 0; i<nums.length;i++)
        {
            hash.put(nums[i], i);
        }
        
        //Start Iteration
        for (int i =0;i<nums.length;i++)
        {
            int target_num = target - nums[i];
            if(hash.get(target_num)!=null)
            {
                if(hash.get(target_num)!=i)//Not the same index, e.g. target = 8 = 4 + 4
                {
                   return new int[] {i,hash.get(target_num)};
                }
            }
        }
        return new int[2];
    }
}
