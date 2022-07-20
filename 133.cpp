#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

class Node {
  public:
    int val;
    vector<Node *> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node *>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node *>();
    }
    Node(int _val, vector<Node *> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};

class Solution {
  public:
    Node *cloneGraph(Node *node) {
        if (node == nullptr) {
            return node;
        }

        // Map from original node to its clone.
        unordered_map<Node *, Node *> cloned;
        // Tracks nodes seen during BFS.
        unordered_set<Node *> seen;
        cloned.reserve(101);
        seen.reserve(101);

        // Start BFS.
        queue<Node *> exploring;
        exploring.push(node);
        seen.insert(node);
        while (!exploring.empty()) {
            Node *n = exploring.front();
            exploring.pop();
            Node *c = new Node(n->val);
            cloned[n] = c;
            for (Node *nbr : n->neighbors) {
                if (seen.find(nbr) == seen.end()) {
                    // We must be seeing this node for the first time. Add it in
                    // queue to be cloned.
                    exploring.push(nbr);
                    seen.insert(nbr);
                } else if (cloned.find(nbr) != cloned.end()) {
                    // We have seen this node already and it has been cloned.
                    // Add corresponding edges in clones.
                    Node *c_nbr = cloned[nbr];
                    (c_nbr->neighbors).push_back(c);
                    (c->neighbors).push_back(c_nbr);
                }
            }
        }

        return cloned[node];
    }
};
