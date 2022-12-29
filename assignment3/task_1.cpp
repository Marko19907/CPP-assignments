#include <cmath>

const double PI = 3.141592;

class Circle {
public:
    explicit Circle(double radius_);

    double get_area() const;

    double get_circumference() const;

private:
    double radius;
};

Circle::Circle(double radius_) : radius(radius_) {}

double Circle::get_area() const {
    return PI * pow(radius,2);
}

double Circle::get_circumference() const {
    return 2.0 * PI * radius;
}
