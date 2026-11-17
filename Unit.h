#pragma once
#include <memory>
#include <string>
#include "Health.h"
#include "Armor.h"
#include "Attack.h"

class Unit {
protected:
    Health health;
    Armor armor;
    Attack attack;
    int x, y;

public:
    Unit(int h, int a, int atk, int startX, int startY);
    virtual ~Unit() = default;

    virtual std::unique_ptr<Unit> clone() const = 0;
    virtual std::string getType() const = 0;

    void move(int newX, int newY);
    int getX() const;
    int getY() const;
    int getHealth() const;
};
