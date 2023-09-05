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
    unordered_map<Node*, Node*> m;

    Node* copyRandomList(Node* head) {
        if (head == NULL) {
            return NULL;
        }
        Node* ret = getCopy(head);
        ret->next = copyRandomList(head->next);
        ret->random = getCopy(head->random);
        return ret;
    }

    Node* getCopy(Node* node) {
        if (node == NULL) {
            return NULL;
        }
        return m.find(node) == m.end() ? (m[node] = new Node(node->val)) : m[node];
    }
};