#include <iostream>
using namespace std;

class Shape {
public:
    int position;
    char color;
    float borderThickness;

    virtual void draw() = 0;
    virtual void calculateArea() = 0;
    virtual void calculatePerimeter() = 0;

    virtual ~Shape() {}
};

class Circle : public Shape {
    float radius;

public:
    Circle(float r) : radius(r) {}

    void draw() override {
        cout << "Drawing Circle of radius " << radius << endl;
    }

    void calculateArea() override {
        cout << "Area of Circle: " << 3.142 * radius * radius << endl;
    }

    void calculatePerimeter() override {
        cout << "Perimeter of Circle: " << 2 * 3.142 * radius << endl;
    }
};

class Triangle : public Shape {
    float base, height, side1, side2, side3;

public:
    Triangle(float b, float h, float s1, float s2, float s3)
        : base(b), height(h), side1(s1), side2(s2), side3(s3) {}

    void draw() override {
        cout << "Drawing Triangle with base " << base << " and height " << height << endl;
    }

    void calculateArea() override {
        cout << "Area of Triangle: " << (0.5 * base * height) << endl;
    }

    void calculatePerimeter() override {
        cout << "Perimeter of Triangle: " << (side1 + side2 + side3) << endl;
    }
};

class Rectangle : public Shape {
    float length, width;

public:
    Rectangle(float l, float w) : length(l), width(w) {}

    void draw() override {
        cout << "Drawing Rectangle of length " << length << " and width " << width << endl;
    }

    void calculateArea() override {
        cout << "Area of Rectangle: " << (length * width) << endl;
    }

    void calculatePerimeter() override {
        cout << "Perimeter of Rectangle: " << (2 * (length + width)) << endl;
    }
};

class Polygon : public Shape {
    float sideLength;
    int numSides;

public:
    Polygon(float s, int n) : sideLength(s), numSides(n) {}

    void draw() override {
        cout << "Drawing Polygon with " << numSides << " sides of length " << sideLength << endl;
    }

    void calculateArea() override {
        cout << "Approximate Area of Polygon: " << (numSides * sideLength * sideLength * 0.25) << endl;
    }

    void calculatePerimeter() override {
        cout << "Perimeter of Polygon: " << (numSides * sideLength) << endl;
    }
};

int main() {
    Shape* shapes[4];

    shapes[0] = new Circle(5);
    shapes[1] = new Triangle(3, 4, 3, 4, 5);
    shapes[2] = new Rectangle(4, 6);
    shapes[3] = new Polygon(4, 5);

    for (int i = 0; i < 4; i++) {
        shapes[i]->draw();
        shapes[i]->calculateArea();
        shapes[i]->calculatePerimeter();
        cout << "---------------------------------" << endl;
    }

    for (int i = 0; i < 4; i++) {
        delete shapes[i];
    }

    return 0;
}
