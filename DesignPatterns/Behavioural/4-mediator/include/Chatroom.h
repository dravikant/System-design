#include "Person.h"
#include <iostream>
#pragma once
using namespace std;

class Chatroom{
    public:
        vector<Person*> people;
        void broadcast(const string & who, const string &message);
        void join(Person* person);
        void message(const string& origin,
                        const string& who,
                            const string& message){
            auto target = find_if(people.begin(),people.end(),[&](const Person *p){return p->name==who;});
            if(target != people.end()){
                (*target)->receive(origin,message);
            }
                            }
        

};