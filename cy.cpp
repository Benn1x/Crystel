#include <iostream>
#include <string>
#include <stdlib.h>
#include <stdio.h>
#include <cstdlib>
#include <fstream>
#include <dirent.h>
#include <sys/stat.h>
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
      std::cout << "      -f [File Name[-i \"Text input for the File\"] to Create]"<< '\n';
      std::cout << "      -d [Directory Name to Create]" << '\n';
      std::cout << "      -df [File Name to Delete]" << '\n';
      std::cout << "      -dd [Directory Name to Delete]" << '\n';
      std::cout << "      -u Upadte Cy" << '\n';
      std::cout << "      -v Shows The Version of Cy" << '\n';
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
        if(argc > i+1){
          string arg_in  = argv[i+1];
          if (arg_in == "-i") {
            i++;
            i++;
            string FiInp = argv[i];
            ofstream myfile(nFile);
            myfile << FiInp;
          }
        }
      }
    }
    if (arg_i == "-d") {
      i++;
      string nDic = argv[i];
      if(mkdir(nDic.c_str(), 0777)== -1){
          std::cout << "      \033[1;31mAn Error Occurred while performing this Command\033[0m\n" << '\n';
        }else{
          std::cout << "      \033[1;32mThe Directory were sucssesfully created!\033[0m\n" << '\n';
        }
    }
  if(arg_i == "-df"){
    i++;
    string tdFile = argv[i];
    string dcFile = "rm -r "+tdFile;
    string tdFileInput;
    std::cout << '\n';
    std::cout << '\n';
    std::cout << "      Do you relly wont to continue? This would Delete the File: "<< tdFile << "(y|n)";
    std::cin >> tdFileInput;
    std::cout << '\n';
    std::cout << '\n';
    std::cout << '\n';
    if (tdFileInput == "yes"|| tdFileInput == "y") {
      system(dcFile.c_str());
      std::cout << "      \033[1;32mThe File were sucssesfully Delete!\033[0m\n";
    }else{
      std::cout << '\n';
      std::cout << '\n';
      std::cout << "      Process canceled" << '\n';
      std::cout << '\n';
      std::cout << '\n';
    }
  }
  if (arg_i == "-dd") {
    i++;
    string tdD = argv[i];
    string dcD = "rm -r " + tdD;
    string tdDinput;
    std::cout << '\n';
    std::cout << '\n';
    std::cout << "      \033[1;31mDo you relly wont to continue? This would Delete the Directory: "<< tdD << "(y|n)\033[0m";
    std::cin >> tdDinput;
    std::cout << '\n';
    std::cout << '\n';
    std::cout << '\n';
    if (tdDinput == "yes"|| tdDinput == "y") {
      system(dcD.c_str());
      std::cout << "      \033[1;32mThe Directory were sucssesfully Delete!\033[0m\n";
    }else{
      std::cout << '\n';
      std::cout << '\n';
      std::cout << "      Process canceled" << '\n';
      std::cout << '\n';
      std::cout << '\n';
    }
  }
  if(arg_i == "-u"){
    system("wget benn1x.daskju.com/crystel/package/cy.cpp");
    std::cout << "Downlod 1" << '\n';
    system("wget benn1x.daskju.com/crystel/package/Makefile");
    std::cout << "Downlod 2" << '\n';
    system("make compile");
    system("rm cy.cpp");
    system("rm Makefile");
    system("sudo mv cy /usr/bin");
    std::cout << "\033[1;32mUpdate installed! Restart Now Services\033[0m\n" << '\n';

  }
  if (arg_i == "-v") {
    std::cout << "Version: 1.2" << '\n';
  }

  }

  return 0;
}
