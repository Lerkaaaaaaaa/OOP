#include "Health.h"

Health::Health(int v) : value(v) {
    if (v < 0) value = 0;
}
int Health::getValue() const { return value; }
void Health::decrease(int amount) {
    value = (value > amount) ? value - amount : 0;
}
void Health::increase(int amount) { value += amount; }
bool Health::isZero() const { return value == 0; }