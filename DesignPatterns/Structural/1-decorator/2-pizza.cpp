#include<iostream>
#include<memory>
using namespace std;

class Pizza{
    public:
        virtual string description() const =0;
        virtual double price() const =0;
        virtual ~Pizza() = default;
};

class MargheritaPizza : public Pizza{
    public:
        string description() const override{
            return "MargheritaPizza";
        }
        double price() const override{
            return 9.99;
        }
};

class HawaiianPizza : public Pizza
{
    public:
        string description() const override
        {
            return "Hawaiian Pizza";
        }

        double price() const override
        {
            return 11.99;
        }
};

class PepperoniPizza : public Pizza
{
    public:
        string description() const override
        {
            return "Pepperoni Pizza";
        }

        double price() const override
        {
            return 12.99;
        }
};

//decorator interface
class ToppingDecorator : public Pizza{
    private:
        const unique_ptr<Pizza> m_pizza;
    public:
        /*
        without explicit, you could potentially create a Decorator object implicitly, 
        which may lead to unintended behavior or errors. For instance:

        Component* component = new ConcreteComponent();
        Decorator decorator = component; // Implicit conversion

        */
        explicit ToppingDecorator(unique_ptr<Pizza> pizza) : m_pizza(move(pizza)) {}

        string description() const override
        {
            return m_pizza->description();
        }

        double price() const override
        {
            return m_pizza->price();
        }

        virtual ~ToppingDecorator()=default;
        
};

class MushroomDecorator : public ToppingDecorator{

    public:

        explicit MushroomDecorator(unique_ptr<Pizza> pizza) : ToppingDecorator(move(pizza)){}

        string description() const override
        {
            return ToppingDecorator::description() + " with mushrooms ";
        }

        double price() const override
        {
            return ToppingDecorator::price() + 0.99;
        }
};

class ExtraCheeseDecorator : public ToppingDecorator {
    public:

        explicit ExtraCheeseDecorator(unique_ptr<Pizza> pizza) : ToppingDecorator(move(pizza)){} 

        string description() const override
        {
            return ToppingDecorator::description() + " with extra cheese ";
        }

        double price() const override
        {
            return ToppingDecorator::price() + 1.99;
        }
};

class TomatoDecorator : public ToppingDecorator
{
    public:
        explicit TomatoDecorator(unique_ptr<Pizza> pizza) : ToppingDecorator(move(pizza)) {}

        string description() const override
        {
            return ToppingDecorator::description() + ", plus tomatoes";
        }

        double price() const override
        {
            return ToppingDecorator::price() + 0.79;
        }
};

int main(){

    auto margheritaPizza = std::make_unique<MargheritaPizza>();
    auto margheritaPizzawithMushrooms = std::make_unique<MushroomDecorator>(std::make_unique<MargheritaPizza>());
    auto margheritaExtraCheeseMushrooms = std::make_unique<ExtraCheeseDecorator>(std::make_unique<MushroomDecorator>(std::make_unique<MargheritaPizza>()));

    cout<<margheritaExtraCheeseMushrooms->description()<<" costs "<<margheritaExtraCheeseMushrooms->price()<<endl;

    return 0;
}