#include <cassert>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
 public:
  vector<vector<string>> findDuplicate(vector<string>& paths) {
    // <content, directory>
    unordered_map<string, vector<string>> hashmap;

    for (string& path : paths) {
      auto cur_pos = path.find(' ');
      string directory = path.substr(0, cur_pos);

      while (cur_pos != string::npos) {
        int start_content_pos = path.find('(', cur_pos);
        int end_content_pos = path.find(')', cur_pos);

        string file_name = path.substr(cur_pos + 1, start_content_pos - cur_pos - 1);
        string content = path.substr(start_content_pos + 1, end_content_pos - start_content_pos - 1);

        if (hashmap.find(content) == hashmap.end()) {
          hashmap[content] = {};
        }
        string full_dir = directory;
        full_dir.push_back('/');
        full_dir.append(file_name);
        hashmap[content].push_back(full_dir);

        cur_pos = path.find(' ', cur_pos + 1);
      }
    }

    vector<vector<string>> ret;
    for (auto& [content, dirs] : hashmap) {
      if (dirs.size() > 1) {
        ret.push_back(dirs);
      }
    }

    return ret;
  }
};

template <typename T>
void print_vector(vector<T> vec) {
  cout << "{";
  for (int i = 0; i < vec.size(); i++) {
    cout << vec[i];
    if (i != vec.size() - 1) {
      cout << ", ";
    }
  }
  cout << "}";
}

int main() {
  Solution solution;
  vector<string> paths;
  vector<vector<string>> output;

  paths = {"root/a 1.txt(abcd) 2.txt(efgh)", "root/c 3.txt(abcd)", "root/c/d 4.txt(efgh)", "root 4.txt(efgh)"};
  output = solution.findDuplicate(paths);

  cout << "Great success!" << '\n';
}
