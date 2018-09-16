#include "stdio.h"

struct vec2 {

    float x;
    float y;

    vec2() {
        x = 0;
        y = 0;
    }

    vec2 (float v) {
        x = v;
        y = v;
    }

    vec2 (float x, float y) {
        this -> x = x;
        this -> y = y;
    }

    void add(vec2 v) {
        x += v.x;
        y += v.y;
    }

    void sub(vec2 v) {
        x -= v.x;
        y -= v.y;
    }

    void mul(vec2 v) {
        x *= v.x;
        y *= v.y;
    }

    void div(vec2 v) {
        x /= v.x;
        y /= v.y;
    }

    bool equals (vec2 v) {
        if (v.x == x && v.y == y) {
            return true;
        } else {
            return false;
        }
    }

    void operator+=(vec2 v) {
        this -> x += v.x;
        this -> y += v.y;
    }

    void operator-=(vec2 v) {
        this -> x += v.x;
        this -> y += v.y;
    }

    void operator*=(vec2 v) {
        this -> x += v.x;
        this -> y += v.y;
    }

    void operator/=(vec2 v) {
        this -> x += v.x;
        this -> y += v.y;
    }

    vec2 operator+(vec2 v) {
        return vec2(this -> x + v.x, this -> y + v.y);
    }

    vec2 operator-(vec2 v) {
        return vec2(this -> x - v.x, this -> y - v.y);
    }

    vec2 operator*(vec2 v) {
        return vec2(this -> x * v.x, this -> y * v.y);

    vec2 operator/(vec2 v) {
        return vec2(this -> x / v.x, this -> y / v.y);
    }

    bool operator==(vec2 v) {
        return this->equals(v);
        // if (this -> x == v2.x && this -> y == v2.y) {
        //     return true;
        // } else {
        //     return false;
        // }
    }
};