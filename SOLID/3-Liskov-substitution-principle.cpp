/*

If class B is subtype of A, then we should be able to replace object of A with B 
without breaking the behaviour of program

Subclass should extend the functionality of parent class and not narrow it down


*/

#include<iostream>
using namespace std;


class Bird {
    public:

    virtual void fly() =0;
};

class Ostrich : public Bird{

    void fly() override{
        throw std::logic_error("Ostrich can not fly");
    }

};

int main(){
    Bird *bird = new Ostrich();
    try{
        bird->fly();
    }catch(exception &e){
        cout<<e.what()<<endl;
    }

    delete bird;

    return 0;
}


//possible fix


#include <iostream>

class Bird {
public:
   
   
};

class FlyingBird : public Bird {
public:
    void fly()  {
        std::cout << "A flying bird is flying." << std::endl;
    }
};

class NonFlyingBird : public Bird {
public:
    void fly()  {
        std::cout << "A non-flying bird is not flying." << std::endl;
    }
};

class Ostrich : public NonFlyingBird {
};

int main() {
    FlyingBird* flyingBird = new FlyingBird();
    NonFlyingBird* ostrich = new Ostrich();

    flyingBird->fly(); // A flying bird is flying.
    // ostrich->fly(); // A non-flying bird is not flying.

    delete flyingBird;
    delete ostrich;
    return 0;
}
