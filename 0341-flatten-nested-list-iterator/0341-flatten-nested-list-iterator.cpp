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
    stack<NestedInteger> stk;
public:
    NestedIterator(vector<NestedInteger> &nestedList) {
        int sz = nestedList.size();
        while(sz--) stk.push(nestedList[sz]);
    }
    
    int next() {
        int val = stk.top().getInteger(); stk.pop();
        return val;
    }
    
    bool hasNext() {
        while(!stk.empty()){
            NestedInteger curr = stk.top(); 
            if(curr.isInteger()) return true;
            
            stk.pop();
            vector<NestedInteger> &list = curr.getList();
            int sz = list.size();
            while(sz--) stk.push(list[sz]);
        }
        return false;
    }
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */