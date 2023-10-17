#include<iostream>
#include<string>
using namespace std;

class Coffee{
    protected:
        string type;
    public:
        Coffee(string type):type(type){};
        string  getType(){
            return type;
        }
};

class Espresso : public Coffee{
    public:
        Espresso():Coffee("Espresso"){
           
            cout << endl << "Making a cup of espresso" << endl;
		    cout << "Grind and brew one scoop of espresso beans." << endl;
        }
};

class Cappuccino : public Coffee{
    public:
        Cappuccino():Coffee("Cappuccino"){
           
            cout << endl << "Making a cup of Cappuccino" << endl;
		    cout << "Grind and brew one scoop of Cappuccino beans." << endl;
        }
};

class CofeeMakerFactory{
    private:
        Coffee *coffee;
    public:
        Coffee* getCoffee(){

            int choice;

            cout << "Select type of coffee to make: " << endl;
            cout << "1: Espresso" << endl;
            cout << "2: Cappuccino" << endl;
            cout << "Selection: " << endl;
            cin >> choice;

            switch (choice)
            {
            case 1:
                /* code */
                return new Espresso;
                break;
            case 2:
                return new Cappuccino;
                break;
            default:
                cout << "Invalid Selection" << endl;
			    return NULL;
            }

        }
};

int main(){
    CofeeMakerFactory cofeeMakerFactory;

    Coffee *coffee=cofeeMakerFactory.getCoffee();

    cout<<coffee->getType()<<endl;

    return 0;
} 