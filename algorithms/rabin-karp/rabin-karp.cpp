
#include <string>
#include <functional>
#include <iostream>

// returns index of substring
// if substring doesn't exist, returns -1
int rabinKarp(std::string s, std::string pattern)
{
  int patternLength = pattern.length();
  int stringLength  = s.length();

  size_t hpattern = std::hash<std::string>{}(pattern);


  for(int i = 0; i < (stringLength - patternLength); i++)
  {
    size_t hs =
      std::hash<std::string>{}(s.substr(i, (i + patternLength) - i));
    if(hs == hpattern)
    {
      if(pattern.compare(s.substr(i, (i + patternLength) - i)) == 0)
      {
        return i;
      }
    }

  }
  return -1;
}

// for testing
int main()
{
  std::string large = "i rlly like cats m8";
  std::string cool = "cats";

  std::cout << "String: " << large << '\n';
  std::cout << "Substr: " << cool  << '\n';
  std::cout << "Index of cats: " << rabinKarp(large, cool) << '\n';
  return 0;
}
