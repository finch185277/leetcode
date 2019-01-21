class Solution {
public: // by @jianchao-li
  vector<vector<string>> groupAnagrams(vector<string> &strs) {
    std::unordered_map<std::string, std::multiset<std::string>> map;
    for (std::string s : strs) {
      std::string t(s);
      std::sort(t.begin(), t.end());
      map[t].insert(s);
    }
    std::vector<std::vector<string>> anagrams;
    for (auto p : map) { // p.second = multiset
      std::vector<std::string> anagram(p.second.begin(), p.second.end());
      anagrams.push_back(anagram);
    }
    return anagrams;
  }
};
