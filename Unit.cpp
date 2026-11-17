#include "Unit.h"

Unit::Unit(int h, int a, int atk, int startX, int startY)
    : health(h), armor(a), attack(atk), x(startX), y(startY) {
}

void Unit::move(int newX, int newY) { x = newX; y = newY; }
int Unit::getX() const { return x; }
int Unit::getY() const { return y; }
int Unit::getHealth() const { return health.getValue(); }