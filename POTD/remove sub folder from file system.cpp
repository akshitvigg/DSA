#include <vector>
#include <string>
#include <unordered_set>
#include <algorithm>

class Solution {
public:
    std::vector<std::string> removeSubfolders(std::vector<std::string>& folder) {
        std::sort(folder.begin(), folder.end(), [](const std::string &a, const std::string &b) {
            return a.size() < b.size();
        });
        std::unordered_set<std::string> set;
        for (const auto &dir : folder) {
            std::string parentDir;
            bool isSubfolder = false;
            for (size_t i = 1; i < dir.size(); i++) {
                if (dir[i] == '/') {
                    parentDir = dir.substr(0, i);
                    if (set.count(parentDir)) {
                        isSubfolder = true;
                        break;
                    }
                }
            }
            if (!isSubfolder) {
                set.insert(dir);
            }
        }
        return std::vector<std::string>(set.begin(), set.end());
    }
};
