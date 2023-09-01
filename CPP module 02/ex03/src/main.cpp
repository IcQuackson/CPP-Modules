#include "../includes/Fixed.hpp"
#include "../includes/Point.hpp"

int main() {
    Point point1;
    Point point2(2.4f, 2.3f);

    // Test bsp
    Point a(0.0f, 0.0f);
    Point b(4.0f, 0.0f);
    Point c(0.0f, 4.0f);
    Point p0(2.0f, 2.1f);   // Outside tringle (should return false)
    Point p1(2.0f, 2.0f);   // Boundary of tringle (should return false)
    Point p2(1.0f, 1.0f);   // Inside the triangle (should return true)
    Point p3(4.5f, 4.5f);   // Outside the triangle (should return false)
    Point p4(-1.0f, -1.0f); // Outside the triangle (should return false)
    Point p5(0.0f, 0.0f);   // Vertix (should return false)
    Point p6(0.0f, 0.1f);   // edge (should return false)
    Point p7(0.1f, 0.1f);   // inside (should return false)
    Point p8(-0.1f, -0.1f);   // outside (should return false)


    std::cout << "Point p0: " << bsp(a, b, c, p0) << std::endl; // false
    std::cout << "Point p1: " << bsp(a, b, c, p1) << std::endl; // false
    std::cout << "Point p2: " << bsp(a, b, c, p2) << std::endl; // true
    std::cout << "Point p3: " << bsp(a, b, c, p3) << std::endl; // false
    std::cout << "Point p4: " << bsp(a, b, c, p4) << std::endl; // false
    std::cout << "Point p5: " << bsp(a, b, c, p5) << std::endl; // false
    std::cout << "Point p6: " << bsp(a, b, c, p6) << std::endl; // false
    std::cout << "Point p7: " << bsp(a, b, c, p7) << std::endl; // true
    std::cout << "Point p8: " << bsp(a, b, c, p8) << std::endl; // false

}
