class Solution {
public:
  vector<int> findSubstring(string s, vector<string> &words) {
    std::vector<int> ret;
    if (s.empty() || words.empty())
      return ret;
    int words_count = words.size(), word_size = words.at(0).size();
    std::unordered_map<std::string, int> words_map;
    for (std::string w : words)
      words_map[w]++;
    for (int i = 0; i < (int)s.size() - words_count * word_size + 1; i++) {
      std::unordered_map<std::string, int> cur_map;
      int count = 0;
      for (; count < words_count; count++) {
        std::string target = s.substr(i + count * word_size, word_size);
        if (words_map.find(target) == words_map.end())
          break;
        cur_map[target]++;
        if (cur_map.at(target) > words_map.at(target))
          break;
      }
      if (count == words_count)
        ret.push_back(i);
    }
    return ret;
  }
};
