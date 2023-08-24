class Solution {
public:
  vector<string> fullJustify(vector<string>& words, int maxWidth) {
    int start = 0;
    vector<string> text;
    while (start < words.size()) {
      int width = words[start].size();
      int end = start + 1;
      while (end < words.size()) {
        int new_width = width + words[end].size() + 1;
        if (new_width > maxWidth) {
          break;
        }
        width = new_width;
        ++end;
      }
      // Now we pack words[start, end) into a line.
      int count = end - start;
      string& line = text.emplace_back();
      line.append(words[start]);

      int extra_space_per_gap = 0;
      int one_more_space_gaps = 0;
      if (count > 1 && end < words.size()) {  // Not last line or single word line.
        int gap = count - 1;
        int extra_space = maxWidth - width;
        extra_space_per_gap = extra_space / gap;
        one_more_space_gaps = extra_space % gap;
      }
      for (int i = 1; i < count; ++i) {
        int space_count = 1 + extra_space_per_gap + (one_more_space_gaps-- > 0);
        line.resize(line.size() + space_count, ' ');
        line.append(words[start + i]);
      }
      line.resize(maxWidth, ' ');
      start = end;
    }
    return text;
  }
};