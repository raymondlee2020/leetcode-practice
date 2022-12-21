class MyLinkedList {
public:
    int size;
    ListNode* root;

    MyLinkedList() {
        size = 0;
        root = new ListNode(0);
    }
    
    int get(int index) {
        ListNode* ret = getNode(index);
        if (ret == NULL) {
            return -1;
        }
        return ret->val;
    }
    
    void addAtHead(int val) {
        ListNode* newNode = new ListNode(val, root->next);
        root->next = newNode;
        size++;
    }
    
    void addAtTail(int val) {
        ListNode* lastNode = this->getNode(size - 1);
        lastNode->next = new ListNode(val);
        size++;
    }
    
    void addAtIndex(int index, int val) {
        if (index > size) {
            return;
        }
        ListNode* prevNode = this->getNode(index - 1);
        ListNode* newNode = new ListNode(val, prevNode->next);
        prevNode->next = newNode;
        size++;
    }
    
    void deleteAtIndex(int index) {
        if (index >= size) {
            return;
        }
        ListNode* prevNode = this->getNode(index - 1);
        prevNode->next = prevNode->next->next;
        size--;
    }
private:
    ListNode* getNode(int index) {
        if (index >= size) {
            return NULL;
        }
        ListNode* ret = root;
        for (int i = 0; i <= index; i++) {
            ret = ret->next;
        }
        return ret;
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */