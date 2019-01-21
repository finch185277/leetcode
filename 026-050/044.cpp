class Solution {
public:
  bool isMatch(string s, string p) {
    int sidx = 0, pidx = 0;  // match record min posible position of sidx
    int match, staridx = -1; // staridx record the last position of '*'
    while (sidx < s.size()) {
      if (pidx < p.size() && (p[pidx] == '?' || s[sidx] == p[pidx])) {
        sidx++;
        pidx++;
      } else if (pidx < p.size() && p[pidx] == '*') { // '*' found
        staridx = pidx;
        match = sidx;
        pidx++;
      } else if (staridx != -1) { // sidx back to match + 1,
        pidx = staridx + 1;       // pidx back to staridx + 1,
        match++;                  // and continue linear search
        sidx = match;
      } else
        return false;
    }
    while (pidx < p.size() && p[pidx] == '*') // check the elements remain in p
      pidx++;
    if (pidx == p.size())
      return true;
    else
      return false;
  }
};
