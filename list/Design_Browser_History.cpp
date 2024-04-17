/**
 * L1472_Design Browser History
*/
#include <iostream>
#include <vector>
#include <string>
#include <list>

using namespace std;

vector<string> answer;

class BrowserHistory {
public:
    list<string> history_pages; 
    list<string>::iterator iter;
    BrowserHistory(string homepage) {
        history_pages.push_back(homepage);
        iter = history_pages.begin();
    }
    
    void visit(string url) {
        list<string>::iterator del = iter; 
        history_pages.erase(++del, history_pages.end()); 
        history_pages.push_back(url); 
        iter++;  
    }
    
    string back(int steps) {  
        while((history_pages.begin() != iter) && steps--) 
            iter--;
        return *iter; 
    }
    
    string forward(int steps) { 
        while(((--history_pages.end()) != iter) && steps--) 
            iter++;
        return *iter;
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */