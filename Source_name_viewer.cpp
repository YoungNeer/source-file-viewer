/*
Program : Source-NViewer
Author : Neer
Version : 1.0

    Sometimes you may want to know the source-file name of a c++ program for various reason.
    It happened to me that i wanted the source-file name of my friends c++ program so that
    i can locate it (locate filename) on his computer and see the source. So thats why I made this program.
    Let me tell you that this story is just made up by me right now. Actually i made this for fun

*/
#include <iostream>
#include <fstream>
#include <stdlib.h>
using namespace std;
int previous=0,next=0,lno;
bool found=false;
void perform(){
  ifstream file;
  file.open("~temp");
  string line,name=";";
  while(file){
    lno++;
    getline(file,line);
    if (found&&line!="_ZStL8__ioinit")
      name=line;
    if (line=="__frame_dummy_init_array_entry"){
      previous=lno;
      found=true;}
    else if (line=="_ZStL8__ioinit")
      next=lno;
    if (next-previous==2)
      break;
  }
  if (name!=";")
    cout<<"The name of the source file is : "<<name<<endl;
  else
    cout<<"Sorry, the program couldn't find the name of the source file";
  file.close();
  remove("~temp");
}
int main(int argc,char *args[]){
  string filename;
  if (argc==1){
  cout<<"Enter the filename:";
  cin>>filename;}
  else if (argc>1){
  filename=args[1];
  if (filename=="--help" or filename=="-h"){

    cout<<"Usage: "<<args[0]<<" <filename>\n";
    cout<<"SRC++ unveils the name of the source-file of a C++ program\n";
    exit(0);}}
  ifstream fo(filename.c_str());
  if (!fo) {
    cout<<"The file doesn't exist!\n";
    fo.close();}
  else{
    filename = "strings "+filename+">> ~temp";
    system(filename.c_str());
    fo.close();
    perform();
}
}
