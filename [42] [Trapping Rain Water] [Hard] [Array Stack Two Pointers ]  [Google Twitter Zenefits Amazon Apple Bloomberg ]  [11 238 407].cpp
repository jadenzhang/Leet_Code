/*
Question# + Difficulty + Topic + Company + Similar_Question
[42] [Trapping Rain Water] [Hard] [Array Stack Two Pointers ] 
[Google Twitter Zenefits Amazon Apple Bloomberg ] 
[11 238 407].cpp
*/
// Two PTR Approach
class Solution {
public:
    int trap(vector<int>& height) {
        int left = 0,water = 0,leftmax = 0,rightmax = 0;
        int right = height.size()-1;
        while(left<=right)
        {
            leftmax = max(leftmax,height[left]);
            rightmax = max(rightmax,height[right]);
            if(leftmax<rightmax)//store water from left to right
            {
                water+= leftmax-height[left];//0 if this is max, else add water
                left++;
            }
            else//store water from right to left
            {
                water+= rightmax-height[right];
                right--;
            }
        }
        //cout<<*max_element(height.begin(),height.end())<<endl;
        //cout<<max_element(height.begin(),height.end())-height.begin()<<endl;
        return water;
    }
};


// Stack Approach, push in decreasing order, and pop when meet local highest right
public int trap(int[] A) {
        if (A==null) return 0;
        Stack<Integer> s = new Stack<Integer>();
        int i = 0, maxWater = 0, maxBotWater = 0;
        while (i < A.length){
            if (s.isEmpty() || A[i]<=A[s.peek()]){
                s.push(i++);
            }
            else {
                int bot = s.pop();
                maxBotWater = s.isEmpty()? // empty means no il
                0:(Math.min(A[s.peek()],A[i])-A[bot])*(i-s.peek()-1);
                maxWater += maxBotWater;
            }
        }
        return maxWater;
    }
