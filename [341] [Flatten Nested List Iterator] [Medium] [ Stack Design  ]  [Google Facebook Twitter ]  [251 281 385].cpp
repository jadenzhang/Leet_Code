/*
Question# + Difficulty + Topic + Company + Similar_Question
[341] [Flatten Nested List Iterator] [Medium] [ Stack Design  ] 
[Google Facebook Twitter ] 
[251 281 385].cpp
*/

/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */
class NestedIterator {
private:
    stack<NestedInteger> sta;
    
public:
    NestedIterator(vector<NestedInteger> &nestedList) {
        for(int i = nestedList.size()-1;i>=0;i--)
        {
            sta.push(nestedList[i]);
        }
    }

    int next() {
        int res = sta.top().getInteger();
        sta.pop();
        return res;
    }

    bool hasNext() {
        while(!sta.empty())
        {
            NestedInteger cur = sta.top();
            if(cur.isInteger()) return true; //next will pop
            
            //else list node
            sta.pop();
            vector<NestedInteger>& adj = cur.getList();
            for(int i = adj.size()-1;i>=0;i--)
            {
                sta.push(adj[i]);
            }
        }
        return false;
        
    }
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */
