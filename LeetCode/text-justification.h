/*
*	https://oj.leetcode.com/problems/text-justification/
*/

#define LEETCODE
#include <cassert>
#include <functional>
#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <queue>
using namespace std;
class Solution {
public:
    string flush(const vector<string> &line, int L) {  
        
        
        int space = L;
        for (auto &word : line)
            space -= word.size();
          
        int words = line.size();
        string output = line[0];
        words--;
        
        for (int i = 1; i < line.size(); ++i) {
            int count = (space+1) / words;
            space -= count;
            words--;
            while (count--)
                output += ' ';
            output += line[i];
        }

		while (output.size() < L)
			output += " ";
        return output;
    }
    
    vector<string> fullJustify(vector<string> &words, int L) {
        vector<string> output;
        vector<string> line;
        int len = 0;
        for (auto &word : words) {
            if (len + line.size() + word.size() > L) {
                // flush
                output.push_back(flush(line, L));
                line.clear();
                len = 0;
            }
            
            len += word.size();
            line.push_back(word);
        }
        
        string last = line[0];
        for (int i = 1; i < line.size(); ++i)
            last += " " + line[i];
		while (last.size() < L)
			last += " ";
        output.push_back(last);
        return output;
    }
};