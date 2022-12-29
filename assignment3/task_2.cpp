#include <iostream>
#include "task_1.cpp"

using namespace std;

int main() {
    Circle circle(5);

    double area = circle.get_area();
    cout << "Area = " << area << endl;

    double circumference = circle.get_circumference();
    cout << "Circumference = " << circumference << endl;

    return 0;
}
