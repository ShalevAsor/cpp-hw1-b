#include "snowman.hpp"
#include <stdexcept>
#include <string>
#include <iostream>
#include <algorithm>
#include <array>
using namespace ariel;
using namespace std; 



/**
 * Implemantion of snowman creator, each method attached with explanations
 * H=head , X=left hand, L=left eye, N= nose , R= right eye, Y=right hand, T=top body B=buttom body
    HHHHH
    HHHHH
   X(LNR)Y
   X(TTT)Y
    (BBB)
 */



/**
 *This class represents all the snowman body parts and possibility options 
 *The 2D array combination contains all the body parts of the snowman
 * 
 */
struct SnowManParts{

    public:
        const int HAT=0; 
        const int LEYE=1;//left eye
        const int NOSE=2;
        const int REYE=3; // right eye
        const int LHAND=4; // left hand 
        const int RHAND=5; // right hand
        const int TBODY=6; // Top body
        const int BBODY=7;// Buttom body
        static const int PARTS=8; // parts = hat, left eye , nose ... 
        static const int TYPES=4; // each part has 4 types 
      
        //this array represents all the snowman combination available||Straw hat   ,   Mexican hat  ,       Fez         , Russion hat                                                
        std::array<std::array<string,TYPES>,PARTS> combination {{{"     \n _===_","  ___ \n .....","   _  \n  /_\\ ","  ___ \n (_*_)"},
           //Dot  , Bigger, Biggest, closed
            {"(." , "(o"  , "(O"    , "(-" }, 
           //Normal  Dot   Line   None   Dot,Bigger, Biggest,closed
            {","    ,"."  ,"_" , " "  } , {".)" , "o)"  , "O)"    , "-)" } ,    
           //Normal,upwards,Downwards,None
             {"<" ,  "\\"   , "/"  ,   " "} , 
           //Normal,upwards,Downwards,None
             {">" ,  "/"   , "\\"  ,   " "}  ,
           //Buttons, Vest ,inwards Arm,None|           Buttons,   Feet       , Flat  ,  None
             {"( : )" , "(] [)" ,"(> <)" , "(   )"} , { "( : )" , "(\" \")" ,"(___)" , "(   )"}  }};
          
        SnowManParts() = default;
};
 // return the index of the type - if the type is 3 , the index is 2 
int type_index(int type){
   int index= type-1; 
    return index;
}
// char to int 
int ctoi(char c){
    return c-'0';
}
// return the string represents the hat by the given type 
string hat(SnowManParts sp,string type){
 string hat =sp.combination.at(sp.HAT).at(type_index(ctoi(type[sp.HAT])));
  return hat; 
}
/**
 * This method return the string represents the head of the snowman. 
 */ 
string head(SnowManParts sp,string type,bool left_hand,bool right_hand){
string head=" ";
int left_eye_index=2;
int nose=1; 
int right_eye_index=3;
// if left_hand == true the left hand is added with the head 
if(left_hand){ head=sp.combination.at(sp.LHAND).at(type_index(ctoi(type[sp.LHAND])));}
// add the left eye then the nose then the right eye 
 head+=sp.combination.at(sp.LEYE).at(type_index(ctoi(type[left_eye_index])));
 head+=sp.combination.at(sp.NOSE).at(type_index(ctoi(type[nose])));
 head+=sp.combination.at(sp.REYE).at(type_index(ctoi(type[right_eye_index])));
// if right_hand == true the right hand is added with the head 
if(right_hand){head+=sp.combination.at(sp.RHAND).at(type_index(ctoi(type[sp.RHAND])));}
  
  return head;
}

/**
 * This method return the string represents the  top body of the snowman
 * 
 */
string top_body(SnowManParts sp,string type,bool left_hand,bool right_hand){
string body=" ";
if(!left_hand){ body=sp.combination.at(sp.LHAND).at(type_index(ctoi(type[sp.LHAND])));}// the left hand is false so the hand should added to the body
body+=sp.combination.at(sp.TBODY).at(type_index(ctoi(type[sp.TBODY])));// add the top body by the given type

if(!right_hand){body+=sp.combination.at(sp.RHAND).at(type_index(ctoi(type[sp.RHAND])));} // same as left hand
  
  return body;
}
/**
 * return the string represents the buttom body of the snowman 
 */
string buttom_body(SnowManParts sp,string type){
  string dbody=" "+sp.combination.at(sp.BBODY).at(type_index(ctoi(type[sp.BBODY])));  
    return dbody; 
}

std::string ariel::snowman(int type){
    const int hand_up=2;// 2 is the type of the hand (left and right) that should be added in the head 
    const int MAX_RANGE=4;// the type range is [1,4]
    const int MIN_RANGE=1;
    string snowman;
    string input = std::to_string(type); // convert the type from int to string 
    int input_length = input.length();
    if(input_length!=SnowManParts::PARTS){throw std::out_of_range{"the input should be 8 digit number!"};}
    for(int i=0;i<input_length;i++){
      if(ctoi(input[i])>MAX_RANGE||ctoi(input[i])<MIN_RANGE){throw std::out_of_range{"the range is [1,4]!"};}
    }
    SnowManParts sp;
    bool left_up=false;
    bool right_up=false;
    if(ctoi(input[sp.LHAND])==hand_up){left_up=true;}// the left hand should be added with the head 
    if(ctoi(input[sp.RHAND])==hand_up){right_up=true;}
    // create the snowman 
    snowman=hat(sp,input)+'\n'+head(sp,input,left_up,right_up)+'\n'+top_body(sp,input,left_up,right_up)+'\n'+buttom_body(sp,input);  
    cout<<snowman<<endl;
return snowman; 
}