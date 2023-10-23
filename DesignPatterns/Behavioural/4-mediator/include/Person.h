#pragma once
#include<iostream>
using namespace std;

class Chatroom;

class Person{
    public:
    string name;
    Chatroom* room=NULL;
    vector<string> chat_log;
    
        Person(const string &name);
        void say(const string& message)const;
        void personal_message(const string& who,const string& message)const;
        void receive(const string& origin,const string& message);
        bool operator==(const Person& rhs)const;
        bool operator!=(const Person& rhs)const;


};