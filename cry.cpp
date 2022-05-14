#include <iostream>
#include <string>
#include <stdlib.h>
#include <stdio.h>
#include <cstdlib>
#include <fstream>
using namespace std;




int main(int argc, char **argv){

  if (argc < 2 ) {
    std::cout <<  '\n';
    std::cout <<  '\n';
    std::cout << "      Command Usage: arg[1] arg[2]" << '\n';
    std::cout << "      For More Informations --Help or -h" << '\n';
    std::cout <<  '\n';
    std::cout <<  '\n';
    exit(EXIT_FAILURE);
  }

  for (int i = 0; i < argc; ++i){
    string arg_i = argv[i];
    if (arg_i=="-h" || arg_i == "--Help") {
      std::cout <<  '\n';
      std::cout <<  '\n';
      std::cout << "      -f [File Name[-i input in file]]"<< '\n';
      std::cout << "      -d [Directory Name]" << '\n';
      std::cout <<  '\n';
      std::cout <<  '\n';
    }
    if (arg_i == "-f") {
      i++;
      string nFile = argv[i];
      string coFile = "touch "+ nFile;
      int cFile = system(coFile.c_str());
      if(256 == cFile){
        std::cout << "      \033[1;31mAn Error Occurred while performing this Command\033[0m\n" << '\n';
      }
      else{
        std::cout << "      \033[1;32mThe File were sucssesfully created!\033[0m\n";
        if(argc >i+1){
          string arg_i1 = argv[i+1];
          int ui = i + 2;
          int uj;
          if (arg_i1 == "-i") {
            ofstream myfile(nFile);
            for (size_t j = ui; j < argc; j++) {
              string arg_j = argv[j];
              if (arg_j == "{end}") {
                uj = j;
                myfile.close();
                break;
              }
              if (arg_j == "\n") {
                myfile << "\n";
              }else{
                string input = " " + arg_j;
                myfile << input;
              }
            }
            i = uj;
          }
        }
      }
    }
    if (arg_i == "-d") {
      i++;
      string nDic = argv[i];
      string coDic = "mkdir "+ nDic;
      const int cDic = system(coDic.c_str());
      if(256 == cDic){
        std::cout << "      \033[1;31mAn Error Occurred while performing this Command\033[0m\n" << '\n';
      }else{
        std::cout << "      \033[1;32mThe Directory were sucssesfully created!\033[0m\n" << '\n';
      }
    }

  }

  return 0;
}
