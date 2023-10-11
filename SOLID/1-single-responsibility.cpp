/*

It states that a class should have only one reason to change, 
which means that a class should have only one responsibility. 
In other words, a class should have only one job or function.

*/

#include<iostream>
using namespace std;

class Person{

    private:
        string name;
        int age;

    public:
        Person(string name, int age) : name(name), age(age) {};

        void display(){
            std::cout << "Name: " << name << ", Age: " << age << std::endl;
        }

        void save(){
            //
        }
};


int main(){
    Person p1("Raj",30);
    p1.display();
    p1.save();
}


//two responsibilities: displaying personal information and saving it

class Person1{
    private:
        string name;
        int age;
    public:
        Person1(string name, int age) : name(name), age(age) {};

        string getName(){
            return name;
        }

        int getAge(){
            return age;
        }
};

class PersonPrinter{

    public:

        void display(const Person1 &p1){

        }

};

class PersonSaver{

    public: 

        void saveDB(const Person1 &p1){

        }
};

int main(){

    Person1 p1("Raj",30);
    PersonPrinter printer;
    PersonSaver saver;
    printer.display(p1);
    saver.saveDB(p1);
}