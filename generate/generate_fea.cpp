//
// generate_fea.cpp
//
// (c) 2023 by Edward H. Trager
//
// This file is part of the Circulubuntu font expansion project.
//
#include <iostream>
#include <string>
#include <iomanip>

int main(int argc,const char**argv){

  // Double Struck Zero Offset: dso
  unsigned int dso = 0x1D7D8;

  // PUA Glyphs Offset: pgo
  unsigned int pgo = 0xE9F7;

  // Start the lookup:
  std::cout << "lookup DoubleStruckToEncircled {" << std::endl;
  std::cout << "  lookupflag 0;" << std::endl;
  
  for(unsigned int i=5;i<=9;i++){
    for(unsigned int j=0;j<10;j++){
      if(i==5 && j==0){
        // Skip 50 because our first PUA glyph
        // starts at 51:
	continue;
      }

      std::cout << "    " << "sub \\u" << std::hex << (dso+i) << " \\u" << std::hex << (dso+j) << " by \\uni" << std::hex << pgo << " ;" << std::endl;
      pgo++;

    }
  }

  // Finally, for circled "100" we just do the line manually:
  std::cout << "    sub \\uni1d7d9 \\uni1d7d8 \\uni1d7d8 by \\uniea28 ;" << std::endl;
  // lookup is done:
  std::cout << "} DoubleStruckToEncircled ;" << std::endl;
  std::cout << std::endl;
  // Print the ccmp section:
  std::cout << "feature ccmp{" << std::endl;
  std::cout << "  language dflt;" << std::endl;
  std::cout << "    lookup DoubleStruckToEncircled;" << std::endl;
  std::cout << "} ccmp; " << std::endl;
  return 0;

}
