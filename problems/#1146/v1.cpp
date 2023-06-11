class SnapshotArray {
public:
    int ver;

    struct Node {
        int val;
        int ver;
        Node *next;
        Node(int x, int v) : val(x), ver(v), next(NULL) {}
    };

    vector<Node*> memo;

    SnapshotArray(int length) {
        memo = vector<Node*>(length);
        ver = 0;
        for (int i = 0; i < length; ++i) {
            memo[i] = new Node(0, ver);
        }
    }
    
    void set(int index, int val) {
        if (memo[index]->ver == ver) {
            memo[index]->val = val;
            return;
        }
        Node* node = new Node(val, ver);
        node->next = memo[index];
        memo[index] = node;
    }
    
    int snap() {
        return ver++;
    }
    
    int get(int index, int snap_id) {
        Node* curr = memo[index];
        while (curr->ver > snap_id) {
            curr = curr->next;
        }
        return curr->val;
    }
};

/**
 * Your SnapshotArray object will be instantiated and called as such:
 * SnapshotArray* obj = new SnapshotArray(length);
 * obj->set(index,val);
 * int param_2 = obj->snap();
 * int param_3 = obj->get(index,snap_id);
 */