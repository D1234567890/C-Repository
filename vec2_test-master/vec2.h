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
};