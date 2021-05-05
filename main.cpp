#include <iostream>
#include <fstream>
#include <vector>
using namespace std;
void print(string print){cout << print;};
string inputfile;string outputfile;string seedfile;
void generate(string outputfilename){
  ofstream opf;
  opf.open(outputfilename);
  opf << "test1";
  opf.close();
};
void encrypt(string inputfile,string outputfile,string seedfile){};
int main(int argc, char *argv[]) {
  vector<string> args{argv, argv + argc};
  if (args[1] == "-g"){
    generate(args[2]);
  } else if (args[1] == "-e") {
    if (args[2] == "-i" || "-o" || "-s") {//start if/else chain
      if (args[2] == "-i") {//i
        inputfile = args[3];
        if (args[4] == "-o"){//i o
          outputfile = args[5];
          seedfile = args[7];
        } else if (args[4] == "-s") { //i s
          outputfile = args[7];
          seedfile = args[5];
        }
      } else if (args[2] == "-o") {// o
        outputfile = args[3];
        if (args[4] == "-i"){//o i
          inputfile = args[5];
          seedfile = args[7];
        } else if (args[4] == "-s") {//o s
          inputfile = args[7];
          seedfile = args[5];
        } 
      }else if (args[2] == "-o") {//s
        seedfile = args[3];
        if (args[4] == "-i"){//s i
          inputfile = args[5];
          outputfile = args[7];
        } else if (args[4] == "-o") {//s o
          inputfile = args[7];
          outputfile = args[5];
        }
      };
    encrypt(inputfile,outputfile,seedfile);
    } else {
      cout << "you either put an invalid option or you put nothing or oy tried to use -g in this!";
    }
  }
}
