#include "decompressor.hh"
#include <fstream>
#include <ostream>
#include <vector>

Decompressor::Decompressor(std::string file)
  :file_(file)
{}

void Decompressor::run()
{
  std::vector<char> tabofbytes;
  std::vector<char> decompress_tab;
  
  std::ifstream f(file_);
  if (f)
  {
    char current;
    int counter = 0;
    char c;
    f.get(current);
    f.seekg(0,f.beg);
    while(f.get(c))
    {

      if (current == '#')
      {
        std::string::size_type sz;
        f.get(c);
        std::string strchar{&c};
        int r = std::stoi(strchar, &sz);
        char ch;
        f.get(ch);

       // std::cout << "okokokoko  --->  " << r << std::endl;
        for (int i = 0; i < r; ++i)
        {
          decompress_tab.push_back(ch);
        }
      }
    }
    f.close();
  }
  std::string newfile = file_.substr(0, file_.size()-3);
  std::ofstream fi(newfile);
  
  for (auto s : decompress_tab)
  {
    fi << s;
  }
  fi.close();
  
}