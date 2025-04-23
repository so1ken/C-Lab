#include <iostream>
#include <vector>
#include <map>
using namespace std;

int main(){
  FILE *input_file = fopen("input.txt", "r");
  if(!input_file) {
    cerr << "Не удалось открыть файл!" << endl;
    return 1;
  }
  vector<string> words;
  char buffer[256];
  while(!feof(input_file)) {
    if(fscanf(input_file, "%255s", buffer) == 1) {
      words.push_back(buffer);
    }
  }
  fclose(input_file);
  map<string, vector<string>> root_words;
  for(int i = 0; i < words.size(); i++){
    for(int j = 0; j < words.size(); j++){
      if(j == i) continue;
      if (words[j].substr(0, words[i].size()) == words[i]) {
        root_words[words[i]].push_back(words[j]);
      }
    }
  }
  size_t max_long = 0;
  string longest = "";

  size_t max_important = 0;
  string important = "";

  for(const pair<string, vector<string>>& item : root_words) {
    if(item.first.size() > max_long) {
      longest = item.first;
      max_long = item.first.size();
    }

    if (item.second.size() > max_important) {
      important = item.first;
      max_important = item.second.size();
    }
  }

  FILE *output_file = fopen("output.txt", "w");
  if (!output_file)
  {
    std::cerr << "Не удалось открыть файл для записи!" << std::endl;
    return 1;
  }

  if(!longest.empty()){
    fprintf(output_file, "%s ", longest.c_str());
    for (const string &word : root_words[longest])
    {
      fprintf(output_file, "%s ", word.c_str());
    }
    fprintf(output_file, "\n");
  } else {
    fprintf(output_file, "NO\n");
  }

  if (!important.empty()) {
    fprintf(output_file, "%s %d", important.c_str(), max_important);
  }

  fclose(output_file);
  return 0;
}
