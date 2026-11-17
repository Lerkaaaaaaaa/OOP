#include "Attack.h"

Attack::Attack(int v) : value(v) {}

int Attack::getValue() const { return value; }

int Attack::calculateDamage(int targetArmor) const {
    int dmg = value - targetArmor;
    return (dmg > 0) ? dmg : 0;
}