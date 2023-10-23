#include "Person.h"
#include "Chatroom.h"
using namespace std;

int main(){
    Chatroom room;
     Person john{"John"};
  Person jane{"Jane"};
  room.join(&john);
  room.join(&jane);
  john.say("hi room");
  jane.say("oh, hey john");

  Person simon{"Simon"};
  room.join(&simon);
  simon.say("hi everyone!");

  jane.personal_message("Simon", "glad you found us, simon!");

  return 0;
}

/*
% g++ -I./include main.cpp src/Person.cpp src/Chatroom.cpp -std=c++11 -o chatroom

% ./chatroom 
[John's chat session]room:Jane joins the chat
[Jane's chat session]John:hi room
[John's chat session]Jane:oh, hey john
[John's chat session]room:Simon joins the chat
[Jane's chat session]room:Simon joins the chat
[John's chat session]Simon:hi everyone!
[Jane's chat session]Simon:hi everyone!
[Simon's chat session]Jane:glad you found us, simon!
*/