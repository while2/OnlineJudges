class Trie {
private:
    struct Node {
        Node* children[26];
        bool end;
        
        Node () {
			for (int i = 0; i < 26; ++i)
				children[i] = nullptr;
            //memset(children, sizeof(Node*)*26, 0);
            end = false;
        }
    };
    
public:
    Trie () {
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
    
    vector<int> Match(const string &word, int start) {
        vector<int> matches;
        Node *node = m_root;
        for (int i = start; i < word.size(); ++i) {
			char c = word[i];
            node = node->children[c-'a'];
			if (node == nullptr)
				return matches;
			else if (node->end)
                matches.push_back(i);
        }
        return matches;
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
            vector<int> matches = trie.Match(s, i);
            bool ok = false;
            for (int pos : matches) {
                if (flags[pos+1]) {
                    ok = true;
                    break;
                }
            }
            flags[i] = ok;
        }
        return flags[0];
    }
};