/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

struct comp{
    bool operator()(const ListNode *l1, const ListNode *l2) const{
        return l1->val < l2->val;
    }
};

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        multiset<ListNode* ,comp> st;
        for(auto it:lists){
            if(it!=NULL)
                st.insert(it);
        }
        ListNode *head=NULL, *ptr=NULL;
        int cnt = 0;
        while(!st.empty()){
            ListNode* temp=*st.begin();
            st.erase(st.begin());
            if(ptr!=NULL){
                ptr->next=temp;
                ptr=temp;
            }
            else{
                head=ptr=temp;
            }
            if(temp->next!=NULL){
                st.insert(temp->next);
            }
        }
        
        return head;
    }
};