#include <iostream>
#include <string> 
#include <thread>
#include <chrono>
#include "snowman.hpp"

using namespace std; 
/**
 * simple program that create random snowmans and print each snowman with his specific type . 
 * the program will end automaticly after 20 seconds . 
 * 
 * 
 * 
 */
int main(){
    const int TIME_LIMIT=20; //seconds
    const int PARTS=8;// the number of snowman available parts 
    time_t seconds= TIME_LIMIT; //the program run time limit will be 20 seconds
    time_t start=time(NULL);
    time_t end=start +seconds; 
    while(start<end){

//create random snowman 
int index=0;
string type;
while (index<PARTS){
  int part=(rand()%4+1); 
  type+=to_string(part); 
index++; 
}

//the snowman type that was generated 
cout<<"type:"<<type<<endl;

try{
ariel::snowman(stoi(type));
}
catch (exception ex) { 
    cout<<"exception :" << ex.what() << "type:"<<type<<endl;
}
cout<<endl; 
start=time(NULL);
std::this_thread::sleep_for(chrono::seconds(2)); //sleep for 2 seconds to print the snowmans slower 

}
return 0; 
}