#include <string>
#include <vector>
#include <unordered_set>
using namespace std;

class Trie {
private:
    struct Node {
        Node* children[26];
        bool end;
        
        Node() {
			for (int i = 0; i < 26; ++i)
				children[i] = nullptr;
            end = false;
        }
    };
    
public:
    Trie() {
        m_root = new Node;
    }
    void AddWord(const string &word) {
        Node **node = &m_root;
        for (char c : word) {
            node = &(*node)->children[c-'a'];
            if (*node == nullptr) {
                *node = new Node;
            }
        }
        (*node)->end = true;
    }
    
    void Match(const char *str, vector<int> &match_length) {
        Node *node = m_root;
		for (int i = 0; str[i] != 0; ++i) {
			char c = str[i];
            node = node->children[c-'a'];
			if (node == nullptr)
				break;
			else if (node->end)
                match_length.push_back(i+1);
        }
    }
    Node *m_root;
};

class Solution {
public:
    bool wordBreak(string s, unordered_set<string> &dict) {
        Trie trie;
        for (const string &word : dict) {
            trie.AddWord(word);
        }
        vector<bool> flags(s.size()+1, false);
        flags[s.size()] = true;
        for (int i = s.size()-1; i >= 0; i--) {
            vector<int> match_length;
			trie.Match(&s[i], match_length);

            bool ok = false;
            for (int len : match_length) {
                if (flags[i + len]) {
                    ok = true;
                    break;
                }
            }
            flags[i] = ok;
        }
        return flags[0];
    }
};