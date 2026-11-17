#pragma once

class Attack {
private:
    int value;
public:
    explicit Attack(int v);
    int getValue() const;
    int calculateDamage(int targetArmor) const;
};
