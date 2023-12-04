#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <math.h>

int get_num(std::vector<std::string> &all_lines, int i, int j){
  int rs = 0;
  std::vector<int> num_arr;
  while(std::isdigit(all_lines[i][j])){
    j--;    
  }
  j++;
  while(std::isdigit(all_lines[i][j])){
    num_arr.push_back(all_lines[i][j] - '0');
    all_lines[i][j] = '.';
    j++;
  }
  for(int j = 0, i = num_arr.size() - 1 ;i >= 0; j++, i--){
    rs += num_arr[i] * pow(10, j);
  }
  return rs;
}

int main(int argc, char **argv){
  if(argc < 2){
     std::cerr<<"usage: "<<argv[0]<<" <filename>\n";
    return -1; 
  }
  std::ifstream file{argv[1]};
  if(!file){
    std::cerr<<"failed to open file "<<argv[1];
    return -1;
  }
  std::vector<std::string> all_lines;
  std::string str;
  int rs = 0;
  while(std::getline(file, str)){
    all_lines.push_back(str);
  }
  for(int i = 0; i < all_lines.size(); i++){
    for(int j = 0; j < all_lines[i].size(); j++){
      if((!(std::isdigit(all_lines[i][j]))) && (!(std::isalpha(all_lines[i][j]))) && all_lines[i][j] != '.')
      {
        if(std::isdigit(all_lines[i][j + 1])){
          rs+=get_num(all_lines, i, j + 1);
        }
        if(std::isdigit(all_lines[i][j - 1])){         
          rs+=get_num(all_lines, i, j - 1);
        }
        if(std::isdigit(all_lines[i + 1][j + 1])){
          rs+=get_num(all_lines, i + 1, j + 1);
        }
        if(std::isdigit(all_lines[i + 1][j - 1])){
          rs+=get_num(all_lines, i + 1, j - 1);
        }
        if(std::isdigit(all_lines[i - 1][j + 1])){
          rs+=get_num(all_lines, i - 1, j + 1);
        }
        if(std::isdigit(all_lines[i - 1][j - 1])){
          rs+=get_num(all_lines, i - 1, j - 1);
        }
        if(std::isdigit(all_lines[i - 1][j])){
          rs+=get_num(all_lines, i - 1, j);
        }
        if(std::isdigit(all_lines[i + 1][j])){
          rs+=get_num(all_lines, i + 1, j);
        }
      }
    }
  }
  std::cout<<rs;
  return 0;
}
