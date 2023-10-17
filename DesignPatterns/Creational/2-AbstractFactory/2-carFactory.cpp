#include<iostream>
#include<string>
using namespace std;

class Door{

    public:
        Door(){};
        virtual void Open()=0;
};

class GasCarDoor : public Door
{
    public:
        GasCarDoor()
        {
            cout << "Making a door for a gas car." << endl;
        }
        void Open() override
        {
            cout << "click" << endl;
	}
};

class ElectricCarDoor : public Door
{
    public:
        ElectricCarDoor()
        {
            cout << "Making a door for an electric car" << endl;
        }
        void Open() override
        {
            cout << "shhhhh" << endl;
        }
};

class Engine{
    public:
        Engine(){};
        virtual void Run()=0;
};

class GasEngine : public Engine
{
    public:
        GasEngine()
        {
            
            cout << "Making a gas engine." << endl;
        }
        void Run()
        {
            cout << "vroom" << endl;
        }
};

class ElectricEngine : public Engine
{
    public:
        ElectricEngine()
        {
            cout << "Making an electric engine." << endl;
        }
        void Run()
        {
            cout << "SHHHH" << endl;
	}
};


class CarFactory
{
public:
	virtual Door* BuildDoor() = 0;
	virtual Engine* BuildEngine() = 0;
};

class GasCarFactory : public CarFactory{
    public:
        Door * BuildDoor() override
        {
            return new GasCarDoor();
        }
        Engine* BuildEngine() override
        {
            return new GasEngine();
        }
};

class ElectricCarFactory :public CarFactory
{
    public:
        Door * BuildDoor() override
        {
            return new ElectricCarDoor();
        }
        Engine* BuildEngine() override
        {
            return new ElectricEngine();
        }
};

int main()
{
    CarFactory *carplant;
    
    int choice;
	cout << "Select a car type: " << endl;
	cout << "1: Gasoline" << endl;
	cout << "2: Electric" << endl;
	cout << "Selection: ";
	cin >> choice;
	cout << endl;

    switch (choice)
    {
    case 1:
        
        carplant = new GasCarFactory;
        break;
    
    case 2:
        carplant = new ElectricCarFactory;
        break;
    default:
        carplant = NULL;
        break;
    }

    if(carplant != NULL){
       Door* mydoor = carplant->BuildDoor();
       Engine* myengine = carplant->BuildEngine();

       mydoor->Open();
       myengine->Run();
    }

}
