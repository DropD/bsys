#include <concepts>
#include <iostream>


namespace gtest_simple {

template <typename T>
concept SquarePlusOneAble = requires(T a, int b) {
    { a + b };
} && requires (T a) {
    { a * a };
};

template <SquarePlusOneAble T>
T square_plus_one(T operand) {
    return (operand * operand) + 1;
}

class vec2di_ew {
    public:
    vec2di_ew(int xvalue, int yvalue): x(xvalue), y(yvalue) {}
    vec2di_ew(int xvalue): x(xvalue) {}
    vec2di_ew operator+(int b) {
        return vec2di_ew{ this->x + b, this->y };
    }
    vec2di_ew operator*(vec2di_ew b) {
        return vec2di_ew{ this->x * b.x, this->y * b.y };
    }
    int x, y;
};

std::ostream& operator<<(std::ostream& os, const vec2di_ew& a) {
    os << "vec2di_ew(" << a.x << ", " << a.y << ")";
    return os;
}

class vec2di_dot {
    public:
    vec2di_dot(int xvalue, int yvalue): x(xvalue), y(yvalue) {}
    vec2di_dot operator+(vec2di_dot b) {
        return vec2di_dot{ this->x + b.x, this->y + b.y};
    }
    int operator*(vec2di_dot b) {
        return (this->x * b.x) + (this->y * b.y);
    }
    int x, y;
};

std::ostream& operator<<(std::ostream& os, const vec2di_dot& a) {
    os << "vec2di_dot(" << a.x << ", " << a.y << ")";
    return os;
}
}
