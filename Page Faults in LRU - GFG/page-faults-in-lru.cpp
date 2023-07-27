//{ Driver Code Starts
// Initial Template for C++



#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class ListNode{
public:
    int data;
    ListNode *prev, *next;
    ListNode(){
       data = -1;
       prev = next = NULL;
    }
    ListNode(int d){
       data = d;
       prev = next = NULL;
    }
};

class LRUCache{
    ListNode *head, *tail;
    int capacity;
    unordered_map<int, ListNode* > mp;
    int curSize;
    void insertAtHead(int page){
        ListNode *newPage = new ListNode(page);
        
        newPage->next = head->next;
        head->next->prev = newPage;
        newPage->prev = head;
        head->next = newPage;
        
        mp[page] = newPage;
        curSize++;
    }
public:
    int pageFaults;
    LRUCache(){
        head = new ListNode(-1);
        tail = new ListNode(1001);
        head->next = tail;
        tail->prev = head;
        capacity = 2;
        pageFaults = 0;
        mp[-1] = head;
        mp[1001] = tail;
        curSize = 2;
    }
    LRUCache(int c){
        head = new ListNode(-1);
        tail = new ListNode(1001);
        head->next = tail;
        tail->prev = head;
        capacity = c+2;
        pageFaults = 0;
        mp[-1] = head;
        mp[1001] = tail;
        curSize = 2;
    }
    
    void usePage(int page){
        
        if(mp.find(page) == mp.end()){
            pageFaults++;
            if(curSize == capacity){
                int pageToDelete = tail->prev->data;
                
                mp.erase(pageToDelete);
                curSize--;
                
                ListNode *toDelete = tail->prev;
                
                tail->prev = toDelete->prev;
                toDelete->prev->next = toDelete->next;
                
                toDelete->prev = toDelete->next = NULL;
                delete toDelete;
                
            }
            insertAtHead(page);
            
        }else{
            ListNode *pageToReplace = mp[page];
            
            pageToReplace->prev->next = pageToReplace->next;
            pageToReplace->next->prev = pageToReplace->prev;
            
            pageToReplace->prev = pageToReplace->next = NULL;
            
            pageToReplace->next = head->next;
            head->next->prev = pageToReplace;
            pageToReplace->prev = head;
            head->next = pageToReplace;
            
        }
    }
    
};

class Solution{
public:
    int pageFaults(int n, int C, int pages[]){
        // code here
        LRUCache *cache = new LRUCache(C);
        
        for(int i = 0; i<n; i++){
            cache->usePage(pages[i]);
        }
        
        return cache->pageFaults;
        
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N, C;
        cin>>N;
        int pages[N];
        for(int i = 0;i < N;i++)
            cin>>pages[i];
        cin>>C;
        
        Solution ob;
        cout<<ob.pageFaults(N, C, pages)<<"\n";
    }
    return 0;
}
// } Driver Code Ends