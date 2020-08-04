// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends

#include<bits/stdc++.h>

class LRUCache{
    int _capacity;
    unordered_map<int, pair<int, list<int>::iterator>> _map;
    list<int> _lru;

public:
    LRUCache(int cap){
        _capacity = cap;
    }
    int get(int);
    void set(int , int);
    void use(unordered_map<int, pair<int, list<int>::iterator>>::iterator);
};

void LRUCache:: use(unordered_map<int , pair<int, list<int>::iterator>>::iterator iter){
     _lru.erase(iter->second.second);
    _lru.push_front(iter->first);
    iter->second.second = _lru.begin();
    return;
}

int LRUCache :: get(int key){
    unordered_map<int, pair<int, list<int>::iterator>>::iterator iter = _map.find(key);
    //if not found return -1
    if(iter == _map.end()) return -1;
    
    use(iter); //update 
    return iter->second.first; //return the value
}


void LRUCache:: set(int key , int value){
    auto iter = _map.find(key);
    if(iter != _map.end()){
        use(iter);
        iter->second.first = value;
        return;
    }
    
    //if size of lru is equal to the capacity , then delete from the back
    if(_lru.size() == _capacity){
        _map.erase(_lru.back());
        _lru.pop_back();
    }

    _lru.push_front(key);
    pair<int , list<int>::iterator> p;
    p.first = value;
    p.second = _lru.begin();
    _map[key] = p;
    return;
}


// { Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {

        int capacity;
        cin >> capacity;
        LRUCache *cache = new LRUCache(capacity);
        
        int queries;
        cin >> queries;
        while (queries--)
        {
            string q;
            cin >> q;
            if (q == "SET")
            {
                int key;
                cin >> key;
                int value;
                cin >> value;
                cache->set(key, value);
            }
            else
            {
                int key;
                cin >> key;
                cout << cache->get(key) << " ";
            }
        }
        cout << endl;
    }
    return 0;
}
  // } Driver Code Ends