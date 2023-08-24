class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> ret;
        int n = words.size(), start = 0, width = words[0].size();
        for (int i = 1; i < n; ++i) {
            if (width + words[i].size() + (i - start) > maxWidth) {
                ret.push_back(writeLine(words, maxWidth, start, i - 1, width));
                start = i;
                width = 0;
            }
            width += words[i].size();
        }
        string tmp = words[start];
        for (int i = start + 1; i < n; ++i) {
            tmp.append(" ");
            tmp.append(words[i]);
        }
        tmp.append(string(maxWidth - width - (n - 1 - start), ' '));
        ret.push_back(tmp);
        return ret;
    }

    string writeLine(vector<string>& words, int maxWidth, int start, int end, int width) {
        string ret = words[start];
        if (end - start == 0) {
            ret.append(string(maxWidth - width, ' '));
            return ret;
        }
        int least = (maxWidth - width) / (end - start), more = (maxWidth - width) % (end - start);
        for (int i = start + 1; i <= end; ++i) {
            ret.append(string(least, ' '));
            if (more-- > 0) {
                ret.append(" ");
            }
            ret.append(words[i]);
        }
        return ret;
    }
};