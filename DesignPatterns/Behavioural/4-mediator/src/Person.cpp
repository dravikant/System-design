#include "Person.h"
#include "Chatroom.h"
using namespace std;

Person::Person(const string& name){
    this->name=name;
}

void Person::say(const string& message)const{
    room->broadcast(name,message);
}

void Person::personal_message(const string &who,const string&messages)const{
    room->message(name,who,messages);
}

void Person::receive(const string& origin,const string& message){
    string s{origin+":"+message};
      std::cout << "[" << name << "'s chat session]" << s << "\n";
      chat_log.emplace_back(s);

}

bool Person::operator==(const Person& rhs)const{
    return this->name == rhs.name;
}

bool Person::operator!=(const Person &rhs) const {
  return !(rhs == *this);
}

