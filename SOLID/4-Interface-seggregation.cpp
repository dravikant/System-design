/*
The Interface Segregation Principle (ISP) 
suggests that a class should not be forced to implement interfaces it doesn't use.

*/

#include<iostream>
using namespace std;

class Shape{
    public:
    virtual double computeArea() =0;
    virtual double computeVolume() =0;
};

class Circle : public Shape {

    private:
        double radius;

    public:
    double computeArea()override{
        return radius*radius*3.14;
    }

    double computeVolume() override {
        throw std::logic_error("2D shapes do not have volume.");
    }



};


//to fix this


class TwoDimensionalShape {
public:
    virtual double area() const = 0;
};

// Separate 3DShape interface with area and volume methods
class ThreeDimensionalShape {
public:
    virtual double area() const = 0;
    virtual double volume() const = 0;
};

// 2D shapes
class Circle : public TwoDimensionalShape {
private:
    double radius;

public:
    Circle(double r) : radius(r) {}

    double area() const override {
        return 3.14159265359 * radius * radius;
    }
};

// 3D shapes
class Sphere : public ThreeDimensionalShape {
private:
    double radius;

public:
    Sphere(double r) : radius(r) {}

    double area() const override {
        return 4.0 * 3.14159265359 * radius * radius;
    }

    double volume() const override {
        return (4.0 / 3.0) * 3.14159265359 * radius * radius * radius;
    }
};

int main() {
    Circle circle(3.0);
    Sphere sphere(2.0);

    std::cout << "Circle Area: " << circle.area() << std::endl;

    std::cout << "Sphere Area: " << sphere.area() << std::endl;
    std::cout << "Sphere Volume: " << sphere.volume() << std::endl;

    return 0;
}





