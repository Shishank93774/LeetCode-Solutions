class DLL{
public:
    string data;
    DLL *prev, *next;
    DLL(string data){
        this->data = data;
        prev = next = NULL;
    }
};

class BrowserHistory {
    DLL *cur;
public:
    BrowserHistory(string homepage) {
        cur = new DLL(homepage);
    }
    
    void visit(string url) {
        DLL *newSite = new DLL(url);
        newSite->prev = cur;
        cur->next = newSite;
        cur = cur->next;
    }
    
    string back(int steps) {
        while(steps-- and cur->prev != NULL){
            cur = cur->prev;
        }
        return cur->data;
    }
    
    string forward(int steps) {
        while(steps-- and cur->next != NULL){
            cur = cur->next;
        }
        return cur->data;
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */