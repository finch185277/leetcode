class Solution {
public: // by @jianchao-li
  int ladderLength(std::string beginWord, std::string endWord,
                   std::vector<string> &wordList) {
    std::unordered_set<std::string> dict(wordList.begin(), wordList.end());
    std::queue<std::string> todo;
    todo.push(beginWord);
    int ladder = 1;
    while (!todo.empty()) {
      int n = todo.size();
      for (int i = 0; i < n; i++) {
        std::string word = todo.front();
        todo.pop();
        if (word == endWord)
          return ladder;
        dict.erase(word);
        for (int j = 0; j < word.size(); j++) {
          char c = word[j];
          for (int k = 0; k < 26; k++) {
            word[j] = 'a' + k;
            if (dict.find(word) != dict.end())
              todo.push(word);
          }
          word[j] = c;
        }
      }
      ladder++;
    }
    return 0;
  }
};
