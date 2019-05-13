class MyHashMap {
public:
    // runtime 136ms storage 71.4mb
    
    // goal of the hashmap is to have quick access, which means low number of collisions. You also don't want your map to be excessively large because you would then be wasting storage space.
    // Since the problem  explicitly states that all the keys and values will be integers, it makes the design fairly straightforward because the hashing function can be as simple as , for a key 'n', go to index 'n / 10', which will give you access to a linked list containing at most 10 nodes.
    // game plan: initialize an array of size max_input / 10, which is 100,000 in this case. that means that each array will store a linked list of at most 10 items. index 0 will store keys 0 - 9, index 1 will store keys 10 - 19, so on and so forth. The hashing function will take the requested key and divide it by 10 to find its prospective index in the map. This indexing will give you the head of a linked list, with each node containing a 'key' and 'value' and 'next'. You traverse each node until you find the one that contains the requested value OR you reach the end, in which you return -1. Removing is a similar story, except you have to make sure you reconnect the linked list to exclude the node containing that value. Putting will require you to find the correct index in the map and then add a new node containing the value in question, placing this node at the front of this list.
        
        struct ListNode 
        {
            int key;
            int val;
            ListNode* next;
            
            ListNode(int k, int v)
                // note: try to initialize ALL data members in here!
                : key(k), val(v), next(nullptr)
                {}
            
            // explicit ListNode()
            //     :key(0), val(0), next(nullptr)
            // {}
            
            static ListNode* get(ListNode* L, int k)
            {
                if (!L) return nullptr;
                // we've found a match, return its corresponding value
                if (L->key == k)
                    return L;
                else
                {
                    // move onto the next item in the list
                    return ListNode::get(L->next, k);
                }
                return nullptr;
            }
            
            static ListNode* remove(ListNode* L, int k)
            {
                if (!L) return nullptr;
                if (L->key == k)
                {
                    ListNode* child = L->next;
                    delete L;
                    return child;
                }
                else if (L->key != k)
                {
                    // let the rest of the list deal with removal; this ListNode is clean.
                    L->next = ListNode::remove(L->next, k);
                    return L;
                }
                return nullptr;
            }
            
            static ListNode* put(ListNode* L, int k, int v)
            {
                if (!L)
                {
                    //cout << "added a new ListNode with key " << k << " and value " << v << endl;
                    return new ListNode(k, v);
                    
                }
                else if (L->key != k)
                {
                    L->next = ListNode::put(L->next, k, v);
                    return L;
                }
                // overwrite the value originally in the ListNode containing k
                else if (L->key == k)
                {
                    //cout << "updated ListNode with key " << L->key << " to have value " << v << endl;
                    L->val = v;
                    return L;
                }
                return nullptr;
            }
        };
        
        ListNode** map;
        
        // initialize map to an array capable of holding 100000 ListNode pointers
        explicit MyHashMap()
            :map(new ListNode* [100000])
            {
                for (int i = 0; i < 100000; ++i)
                {
                    map[i] = nullptr;
                }
            }
        
        ~MyHashMap()
        {
            //cout << " called destructor" << endl;
            for (int i = 0; i < 100000; ++i)
            {
                for (ListNode* cur = map[i]; cur != nullptr;)
                {
                    // don't delete the current node before moving on to node->next, because by the time you try to call node->next, the node is deleted and is garbage. Save current node in a temp, move node to its next, then delete the temp
                    ListNode* temp = cur;
                    cur = cur->next;
                    delete temp;
                }
                //cout << "deleted all the chains." << endl;
            }
            delete[] map;
            //cout << "destructed this. " << endl;
        }
        
        int hash(int key)
        {
            return key / 10;
        }
        
        
    
    /** value will always be non-negative. */
    void put(int key, int value) {
        //cout << "called put " << endl;
        int newKey = hash(key);
        //cout << "get index: " << newKey << endl;
        map[newKey] = ListNode::put(map[newKey], key, value);
    }
    
    /** Returns the value to which the specified key is mapped, or -1 if this map contains no mapping for the key */
    int get(int key) {
        //cout << "called get" << endl;
        
        int newKey = hash(key);
        //cout << "get index: " << newKey << endl;
        ListNode* found = ListNode::get(map[newKey], key);
        if (!found) return -1;
        return found->val;
    }
    
    /** Removes the mapping of the specified value key if this map contains a mapping for the key */
    void remove(int key) {
        //cout << "called remove" << endl;
        int newKey = hash(key);
        //cout << "get index: " << newKey << endl;
        map[newKey] = ListNode::remove(map[newKey], key);
        return;
    }


};
/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */