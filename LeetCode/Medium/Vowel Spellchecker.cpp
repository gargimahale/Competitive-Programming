#include <bits/stdc++.h>

using namespace std;

class Solution {
public:

	string tolow(string s) {
		for (auto& ch : s) ch = tolower(ch);
		return s;
	}

	string todev(string s) {
		s = tolow(s);
		for (auto& ch : s) {
			if (ch == 'a' || ch == 'i' || ch == 'e' || ch == 'o' || ch == 'u') ch = '#';
		}
		return s;
	}


	vector<string> spellchecker(vector<string>& wordlist, vector<string>& queries) {
		unordered_set<string> words(begin(wordlist), end(wordlist));
		unordered_map<string, string> cap, vowel;
		
		for (string w : wordlist) {
			cap.insert({tolow(w), w});
			vowel.insert({todev(w), w});
		}

		for (int i = 0; i < queries.size(); ++i) {
			if (words.count(queries[i])) continue;
			string lower = tolow(queries[i]), devowel = todev(queries[i]);
			if (cap.count(lower)) {
				queries[i] = cap[lower];
			}
			else if (vowel.count(devowel)) {
				queries[i] = vowel[devowel];
			}
			else {
				queries[i] = "";
			}
		}
		return queries;
	}
};