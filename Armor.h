#pragma once

class Armor {
private:
    int value;
public:
    explicit Armor(int v);
    int getValue() const;
    int reduceDamage(int damage) const;
};
