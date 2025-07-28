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
    Node* cloneGraph(Node* node) {
        std::map<Node*, Node*> hashmap;
        return DFS(node, hashmap);
    }

    Node* DFS(Node* node, map<Node*, Node*>& hashmap){
        if(node == nullptr){
            return nullptr;
        }
        if(hashmap.count(node)){
            return hashmap[node];
        }

        Node* newNode = new Node(node->val);
        hashmap[node] = newNode;
        for(const auto& n: node->neighbors){
            newNode->neighbors.push_back(DFS(n, hashmap));
        }

        return newNode;
    }
};
