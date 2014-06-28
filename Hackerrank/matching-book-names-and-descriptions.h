/*
*	https://www.hackerrank.com/contests/june-real-data/challenges/matching-book-names-and-descriptions
*/
#define HACKERRANK
#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <cmath>
using namespace std;

const char *black_list[] = {"at", "of", "the", "in", "out", "on", "a", "an", "st", "s", "from", "to", 
};

class Matching {
public:
	Matching() {
		for (auto word : black_list)
			m_black_list.insert(word);
	}
	void SplitWords(string sentence, vector<string> &words, bool might_break) {
		string word;
		for (auto c : sentence) {
			if (c >= 'A' && c <= 'Z')
				c = c - 'A' + 'a';
			if (c >= 'a' && c <= 'z')
				word += c;
			else {
				if (word.size() > 1)
					words.push_back(word);
				word.clear();
			}
		}
		
		char c = sentence.back();
		if (c >= 'A' && c <= 'Z')
			c = c - 'A' + 'a';
		if (might_break && c >= 'a' && c <= 'z' )
			might_break = true;
		else
			might_break = false;

		if (!might_break && word.size() > 1)
			words.push_back(word);
	}

	void Readinput() {
		int n; scanf("%d\n", &n);
		m_booknames.resize(n);
		m_descriptions.resize(n);
		char buff[1024];
		for (int i = 0; i < n; ++i) {
			scanf("%[^\n]\n", buff);
			SplitWords(buff, m_booknames[i], false);
		}
		scanf("%[^\n]\n", buff);
		for (int i = 0; i < n; ++i) {
			scanf("%[^\n]\n", buff);
			SplitWords(buff, m_descriptions[i], true);
		}
	}

	void BuildDict() {
		for (auto &words : m_booknames) {
			for (auto &word : words)
				m_dict[word]++;
			for (int i = 1; i < words.size(); ++i) {
				string word = words[i-1] + ' ' + words[i];
				m_dict[word]++;
			}
		}
		
		for (auto &words : m_descriptions) {
			for (auto &word : words)
				m_dict[word]++;
			for (int i = 1; i < words.size(); ++i) {
				string word = words[i-1] + ' ' + words[i];
				m_dict[word]++;
			}
		}

		for (auto &pair : m_dict) {
			int id = m_str_to_id.size();
			m_str_to_id[pair.first] = id;
			m_id_to_str[id] = pair.first;
		}

		unordered_map<string, int> dict2;
		for (auto &words : m_booknames) {
			unordered_set<string> set;
			for (auto &word : words)
				set.insert(word);
			for (auto &word : set)
				dict2[word]++;
		}
		
		for (auto &words : m_descriptions) {
			unordered_set<string> set;
			for (auto &word : words)
				set.insert(word);
			for (auto &word : set)
				dict2[word]++;
		}

		for (auto &pair : dict2)
			m_dict[pair.first] = pair.second;
	}

	typedef unordered_map<int, float> BagOfWords;
	void BuildBOWS(vector<string> &words, BagOfWords &bows, bool normalize = true) {
		for (auto &word : words) {
			bows[m_str_to_id[word]]++;
		}
		for (int i = 1; i < words.size(); ++i) {
			string word = words[i-1] + ' ' + words[i];
			bows[m_str_to_id[word]]++;
		}

		float sum2 = 0;
		for (auto &pair : bows) {
			string word = m_id_to_str[pair.first];
			int count = m_dict[word];
			if (word.find(' ') != word.npos)
				pair.second *= 2;
			if (m_black_list.find(word) != m_black_list.end())
				pair.second = 0;
			else {
				pair.second /= count;
				pair.second = logf(pair.second + 1.15);
			}
			sum2 += pair.second * pair.second;
		}
		//sum2 = sqrt(sum2);
		sum2 = words.size();
		if (normalize) {
			for (auto &pair : bows) {
				pair.second /= sum2;
			}
		}
	}
	void BuildBOWS() {
		m_bows1.resize(m_booknames.size());
		m_bows2.resize(m_booknames.size());

		for (int i = 0; i < m_booknames.size(); ++i)
			BuildBOWS(m_booknames[i], m_bows1[i]);

		for (int i = 0; i < m_descriptions.size(); ++i)
			BuildBOWS(m_descriptions[i], m_bows2[i]);
	}

	float Score(BagOfWords &bow1, BagOfWords &bow2) {
		float sum = 0;
		for (auto &pair : bow1) {
			auto it = bow2.find(pair.first);
			if (it == bow2.end())
				continue;
			sum += pair.second * it->second;
		}
		return sum;
	}

	int Match(BagOfWords &bow2) {
		int id = -1;
		float max_score = 0;
		for (int i = 0; i < m_bows1.size(); ++i) {
			float score = Score(bow2, m_bows1[i]);
			if (max_score < score) {
				max_score = score;
				id = i;
			}
		}
		return id;
	}

	void Match() {
		for (auto &bow2 : m_bows2) {
			printf("%d\n", Match(bow2) + 1);
		}
	}

	unordered_set<string> m_black_list;
	vector<vector<string>> m_booknames;
	vector<vector<string>> m_descriptions;
	unordered_map<string, int> m_str_to_id;
	unordered_map<int, string> m_id_to_str;
	unordered_map<string, int> m_dict;
	vector<BagOfWords> m_bows1, m_bows2;

};

int main() {
	Matching matching;
	matching.Readinput();
	matching.BuildDict();
	matching.BuildBOWS();
	matching.Match();
	return 0;
}