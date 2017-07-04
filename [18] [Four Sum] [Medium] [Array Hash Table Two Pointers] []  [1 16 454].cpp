//Question# + Difficulty + Topic + Company + Similar_Question
//[18] [Four Sum] [Medium] [Array Hash Table Two Pointers]
//[]
//[1 16 454].cpp

/*C++*/
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& num, int target) 
    {    
        vector<vector<int>> ans;
        sort(num.begin(), num.end());
        for(int i = 0; i<num.size();i++)
        {
            int sub_target = target - num[i];
            threeSum(num, i+1, ans, sub_target);
            while(i+1<num.size() && num[i + 1] == num[i])i++;
        }
        return ans;
    
    }
    void threeSum(vector<int> &num,int start, vector<vector<int>> &ans, int target) 
    {
        for (int i = start; i < num.size(); i++) {

            int sub_target = target-num[i];
            int front = i + 1;
            int back = num.size() - 1;

            while (front < back) {

                int sum = num[front] + num[back];

                // Finding answer which start from number num[i]
                if (sum < sub_target)
                    front++;

                else if (sum > sub_target)
                    back--;

                else {
                    vector<int> triplet(4, 0);
                    triplet[0] = num[start-1];
                    triplet[1] = num[i];
                    triplet[2] = num[front];
                    triplet[3] = num[back];
                    ans.push_back(triplet);

                    // Processing duplicates of Number 2
                    // Rolling the front pointer to the next different number forwards
                    while (front < back && num[front] == triplet[2]) front++;

                    // Processing duplicates of Number 3
                    // Rolling the back pointer to the next different number backwards
                    while (front < back && num[back] == triplet[3]) back--;
                }

            }

            // Processing duplicates of Number 1
            while (i + 1 < num.size() && num[i + 1] == num[i]) 
                i++;

        }
    }
};
