#include <iostream>
#include "class/compressor.hh"
int main(int argc, char** argv)
{
  Compressor compressor{argv[1]};
  compressor.run();
  return 0;
}
