#include <iostream>

#include "class/decompressor.hh"
int main(int argc, char** argv)
{
  Decompressor decompressor{argv[1]};
  decompressor.run();
  return 0;
}
