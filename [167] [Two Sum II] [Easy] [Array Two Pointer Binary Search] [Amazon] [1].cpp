//Question# + Difficulty + Topic + Company + Similar_Question
//[167] [Two Sum II] [Easy] [Array Two Pointer Binary Search] 
//[Amazon] 
//[1].cpp

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int front = 0;
        int back  = numbers.size()-1;
        while(front<back)
        {
            int diff = target - numbers[front] - numbers[back];
            if(diff>0)front++;//sum too small
            else if(diff<0)back--;//sum too big
            else return vector<int>{front+1,back+1};
        
        }
        
    }
};
