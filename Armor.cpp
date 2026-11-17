#include "Armor.h"

Armor::Armor(int v) : value(v) {
    if (v < 0) value = 0;
}

int Armor::getValue() const { return value; }

int Armor::reduceDamage(int damage) const {
    int reduced = damage - value;
    return (reduced > 0) ? reduced : 0;
}