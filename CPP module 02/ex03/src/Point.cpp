#include "../includes/Point.hpp"
#include "../includes/Fixed.hpp"

Point::Point() : x(0), y(0) {}

Point::Point(const Fixed x, const Fixed y) : x(x), y(y) {}

Point::Point(const Point& point) : x(point.x), y(point.y) {
}

Point& Point::operator= (Point &point) {
    return point;
}

Point::~Point() {}

const Fixed& Point::getX() const {
    return this->x;
}

const Fixed& Point::getY() const {
    return this->y;
}
