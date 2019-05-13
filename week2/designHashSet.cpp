class MyHashSet {
public:
    // runtime 120ms storage 61.9mb
    // idea: quick lookup + simple find, insertion, removal
    
    // game plan: 
    // chained hash table, size n / 10 with chains of size 10
    /** Initialize your data structure here. */
    struct ListNode
    {
        int info;
        ListNode* next;
        
        ListNode(int i)
            :info(i), next(nullptr)
            {}
        
        static ListNode* contains(ListNode* L, int k)
        {
            // item not found.
            if (!L) return nullptr;
            // item found. return this ListNode
            else if (L->info == k)
            {
                //cout << "found item of value " << k << endl;
                return L;
            }
            // continue searching for the item in the list
            //cout << "current info is " << L->info << ". moving on" << endl;
            return ListNode::contains(L->next, k);
        }
        
        static ListNode* add(ListNode* L, int k)
        {
            // add item to list, or make a new list with this as the head
            if (!L)
            {
                //cout << "added new item with value " << k << endl;
                return new ListNode(k);
            }
            // item already found. no need to add a new one. just return this.
            else if (L->info == k)
            {
                return L;
            }
            // search child nodes for k
            L->next = ListNode::add(L->next, k);
            return L;
        }
        
        static ListNode* remove(ListNode* L, int k)
        {
            // you can't remove what doesn't exist ;>
            if (!L) return nullptr;
            // item is found
            else if (L->info == k)
            {
                // save reference to next item in list
                ListNode* child = L->next;
                // delete current item
                delete L;
                // return reference to next item
                return child;
            }
            // item not found yet; keep trying on subsequent elements
            L->next = remove(L->next, k);
            return L;
        }
    };
    
    ListNode** map;
    MyHashSet()
    :map(new ListNode* [100000])
    {
        for (int i = 0; i < 100000; ++i)
        {
            // initialize each index in our array. Don't want it to be pointing to garbage.
            map[i] = nullptr;
        }
    }
    
    ~MyHashSet()
    {
        for (int i = 0; i < 100000; ++i)
        {
            for (ListNode* cur = map[i]; cur != nullptr; )
            {
                ListNode* temp = cur;
                // move cur onto its child node
                cur = cur->next;
                // delete the old cur
                delete temp;
            }
        }
        delete[] map;
    }
    
    int hash(int k)
    {
        return k / 10;
    }
    
    void add(int key) {
        int newKey = hash(key);
        // Assign the correct map index to the newly modified Linked List
        map[newKey] = ListNode::add(map[newKey], key);
    }
    
    void remove(int key) {
        int newKey = hash(key);
        map[newKey] = ListNode::remove(map[newKey], key);
        
    }
    
    /** Returns true if this set contains the specified element */
    bool contains(int key) {
        int newKey = hash(key);
        ListNode* found = ListNode::contains(map[newKey], key);
        //cout << "found is null " << (found == nullptr) << endl;
        // if key was not found, ListNode::contains will return a nullptr
        return (found != nullptr);
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */