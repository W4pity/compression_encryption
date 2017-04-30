#include "compressor.hh"
#include <fstream>
#include <ostream>
#include <vector>

Compressor::Compressor(std::string file)
  :file_(file)
{}

void Compressor::run()
{
  std::vector<char> tabofbytes;
  std::vector<char> compress_tab;
  int size = 0;
  std::ifstream f(file_);
  if (f)
  {
    char current;
    int counter = 0;
    char c;
    std::string line;
    f.get(current);
    f.seekg(0,f.beg);
    while(std::getline(f, line))
    {
      size += line.size()+1;
      current = line[0];
      for (int i = 0; i < line.size(); ++i)
      {
      
   //     std::cout << "c :" << c << " current: " << current << " i: " << counter << std::endl;
        if (current == line[i] && counter < 9)
          counter++;
        else if (current != '\n')
        {
          compress_tab.push_back('#');
          compress_tab.push_back(std::to_string(counter)[0]);
          compress_tab.push_back(current);
          current = line[i];
          counter = 1;
        }
      }
      if (line.size() > 1)
      {
        compress_tab.push_back('#');
        compress_tab.push_back(std::to_string(counter)[0]);
        compress_tab.push_back(current);
      }
      compress_tab.push_back('#');
      compress_tab.push_back('1');
      compress_tab.push_back('\n');
      //current = '\n';
      

    }
    f.close();
  }

  std::ofstream fi(file_+".w4");
  for (auto s = 0; s < compress_tab.size(); s++)
  {
    fi << compress_tab[s];
  }
  f.close();
  //std::cout << (int)'^@' << std::endl;
  int s1 = compress_tab.size()*100;
  int s2 = s1 / size;
  
  //int res1 = s1 * 100;
  std::cout << "compressed at: " << s2 << " %" << std::endl;
}