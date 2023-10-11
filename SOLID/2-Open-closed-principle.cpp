/*
open for extension but closed for modification

*/

#include<string>
using namespace std;

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

class PersonSaver{

    public: 

        void saveDB(const Person1 &p1){

        }
};

//if we have new requirement to save to file instead of db?

//change it

class PersonSaver{

    public: 

        virtual void save(const Person1 &p1)=0;
};

class FileSaver: public PersonSaver{

    public: 
    void save(const Person1 &p1) override{

    }

};

class DBSaver: public PersonSaver{

    public: 
    void save(const Person1 &p1) override{

    }
};

int main(){
    Person1 p1("Raj",30);
     DBSaver dbSaver;
    FileSaver fileSaver;

    // Use them to save the person's data
    dbSaver.save(p1);
    fileSaver.save(p1);

    return 0;
}