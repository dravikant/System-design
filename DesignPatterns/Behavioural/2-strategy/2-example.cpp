#include<iostream>

class GrretingStrategy{
    public:
        virtual void greet(const std::string & name)=0;
};

class BusinessGrretingStrategy : public GrretingStrategy {
public:
    void greet(const std::string & name) override {
        std::cout << "Good morning " << name << ", how do you do?\n";
    }
};

class NormalGrretingStrategy : public GrretingStrategy {
public:
    void greet(const std::string & name)override {
        std::cout << "Hi " << name << ", how are you?\n";
    }
};

class CoolGrretingStrategy: public GrretingStrategy {
public:
    void greet(const std::string & name) override{
        std::cout << "Hey " << name << ", what's up?\n";
    }
};

// Uh oh - code duplication!
// class Politician : public GrretingStrategy {
// public:
//     void greet(const std::string & name) {
//         std::cout << "Good morning " << name << ", how do you do?\n";
//     }
// };

class Person{
    GrretingStrategy *grretingStrategy;
    public:
        Person(GrretingStrategy *grretingStrategy) : grretingStrategy(grretingStrategy){};
        ~Person(){
            delete grretingStrategy;
        }
        void greet(const std::string & name){
            grretingStrategy->greet(name);
        }
};


int main(){

    Person businessPerson(new BusinessGrretingStrategy());
    Person normalPerson(new NormalGrretingStrategy());
    Person coolPerson(new CoolGrretingStrategy());
    Person politician(new BusinessGrretingStrategy());
    
    std::cout << "The businessperson says: ";
    businessPerson.greet("Shaun");
    
    std::cout << "The normal person says: ";
    normalPerson.greet("Shaun");
    
    std::cout << "The cool person says: ";
    coolPerson.greet("Shaun");
    
    std::cout << "The politician says: ";
    politician.greet("Shaun");
    

    return 0;
}