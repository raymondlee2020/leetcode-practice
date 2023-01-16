/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    map<Node*, Node*> m;

    Node* cloneGraph(Node* node) {
        if (node == NULL) {
            return NULL;
        }
        if (node->neighbors.size() == 0) {
            return new Node(node->val);
        }
        return dfs(node);
    }

    Node* dfs(Node* node) {
        Node* cloned = new Node(node->val);
        m[node] = cloned;
        vector<Node*> neighbors;
        for (const auto neighbor: node->neighbors) {
            if (m.find(neighbor) != m.end()) {
                neighbors.push_back(m[neighbor]);
            } else {
                neighbors.push_back(dfs(neighbor));
            }
        }
        cloned->neighbors = neighbors;
        return cloned;
    }
};