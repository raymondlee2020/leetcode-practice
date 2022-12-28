class MyLinkedList {
public:
    int size;
    ListNode* root;

    MyLinkedList() {
        size = 0;
        root = NULL;
    }
    
    int get(int index) {
        ListNode* ret = getNode(index);
        if (ret == NULL) {
            return -1;
        }
        return ret->val;
    }
    
    void addAtHead(int val) {
        if (size == 0) {
            root = new ListNode(val);
        } else {
            ListNode* newNode = new ListNode(val, root);
            root = newNode;
        }
        size++;
    }
    
    void addAtTail(int val) {
        if (size == 0) {
            root = new ListNode(val);
        } else {
            ListNode* lastNode = getNode(size - 1);
            lastNode->next = new ListNode(val);
        }
        size++;
    }
    
    void addAtIndex(int index, int val) {
        if (index == 0) {
            addAtHead(val);
        } else {
            ListNode* prevNode = getNode(index - 1);
            if (prevNode == NULL) {
                return;
            }
            ListNode* newNode = new ListNode(val, prevNode->next);
            prevNode->next = newNode;
        }
        size++;
    }
    
    void deleteAtIndex(int index) {
        if (index >= size) {
            return;
        }
        if (index == 0) {
            root = root->next;
        } else {
            ListNode* prevNode = getNode(index - 1);
            if (prevNode == NULL) {
                return;
            }
            prevNode->next = prevNode->next->next;
        }
        size--;
    }
private:
    ListNode* getNode(int index) {
        if (index >= size || index < 0) {
            return NULL;
        }
        ListNode* ret = root;
        for (int i = 1; i <= index; i++) {
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