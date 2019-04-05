class Solution {
private:
  std::vector<std::vector<string>> get_seqs(
      std::string &word, std::string &beginWord,
      std::unordered_map<std::string, std::pair<bool, std::vector<std::string>>>
          &words) {
    if (beginWord == word)
      return {{beginWord}};
    std::vector<std::vector<std::string>> seqs;
    for (auto &w : words[word].second) {
      auto w_seqs = get_seqs(w, beginWord, words);
      for (auto &seq : w_seqs)
        seq.push_back(word);
      std::copy(w_seqs.begin(), w_seqs.end(), std::back_inserter(seqs));
    }
    return seqs;
  }

public: // by @alreadydone
  std::vector<std::vector<string>>
  findLadders(std::string beginWord, std::string endWord,
              std::vector<std::string> &wordList) {
    std::unordered_map<std::string, std::pair<bool, std::vector<std::string>>>
        words;
    for (auto &s : wordList)
      words.insert({s, {false, {}}});
    std::vector<std::string> qu = {beginWord};
    while (!qu.empty()) {
      bool done = false;
      std::vector<std::string> new_qu;
      for (auto &w : qu)
        words[w].first = true;
      for (auto &w : qu) {
        auto word = w;
        for (auto &c : word) {
          auto coring = c;
          for (c = 'a'; c <= 'z'; c++) {
            if (c != coring) {
              auto it = words.find(word);
              if (it != words.end() && !it->second.first) {
                if (it->second.second.empty())
                  new_qu.push_back(word);
                it->second.second.push_back(w);
                if (word == endWord)
                  done = true;
              }
            }
          }
          c = coring;
        }
      }
      if (done) {
        qu.clear();
        new_qu.clear();
        return get_seqs(endWord, beginWord, words);
      }
      qu = std::move(new_qu);
    }
    return {};
  }
};
