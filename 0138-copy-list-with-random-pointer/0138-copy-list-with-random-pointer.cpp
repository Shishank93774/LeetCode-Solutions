/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(head == NULL) return NULL;
        Node *ptr = head;
        while(ptr){
            Node *newNode = new Node(ptr->val);
            newNode->next = ptr->next;
            ptr->next = newNode;
            ptr = ptr->next->next;
        }
        ptr = head;
        while(ptr){
            Node *copy = ptr->next;
            if(ptr->random) copy->random = ptr->random->next;
            else copy->random = NULL;
            ptr = ptr->next->next;
        }
        Node *newHead = NULL, *newTail = NULL;
        ptr = head;
        while(ptr){
            if(newHead == NULL) newHead = newTail = ptr->next;
            else{
                newTail->next = ptr->next;
                newTail = ptr->next;
            }
            ptr->next = newTail->next;
            ptr = ptr->next;
        }
        newTail->next = NULL;
        return newHead;
    }
};