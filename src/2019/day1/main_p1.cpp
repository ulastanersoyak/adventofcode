#include <cmath>
#include <fstream>
#include <iostream>
#include <string>

int
main (int argc, char **argv)
{
  if (argc < 2)
    {
      std::cerr << "usage: " << argv[0] << " <filename>\n";
      return -1;
    }
  std::ifstream file{ argv[1] };
  if (!file)
    {
      std::cerr << "failed to open file " << argv[1];
      return -1;
    }
  std::string line;
  int rs = 0;
  while (std::getline (file, line))
    {
      auto mass = std::stoi (line);
      rs += std::floor ((mass / 3)) - 2;
    }
  file.close ();
  std::cout << rs;
  return 0;
}
