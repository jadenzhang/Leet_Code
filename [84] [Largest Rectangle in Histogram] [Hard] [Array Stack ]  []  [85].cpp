/*
Question# + Difficulty + Topic + Company + Similar_Question
[84] [Largest Rectangle in Histogram] [Hard] [Array Stack ] 
[] 
[85].cpp
*/
  class Solution {
    public:
        int largestRectangleArea(vector<int> &height) {
            
            int res = 0;
            height.push_back(0);
            vector<int> index;
            
            for(int i = 0; i < height.size(); i++)
            {
                while(!index.empty() && height[i]<height[index.back()] )
                {
                    int h = height[index.back()];
                    index.pop_back();
                    
                    res = max(ret,h*(index.empty()?i:i-index.back()-1));
                    
                }
                index.push_back(i);
            }
            return res;
        }
    };
