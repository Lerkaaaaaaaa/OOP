#pragma once

class Health {
private:
    int value;
public:
    explicit Health(int v);
    int getValue() const;
    void decrease(int amount);
    void increase(int amount);
    bool isZero() const;
};