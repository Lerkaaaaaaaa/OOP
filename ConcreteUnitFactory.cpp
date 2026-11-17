#include "ConcreteUnitFactory.h"
#include "Swordsman.h"
#include "Spearman.h"
#include "LightArcher.h"
#include "HeavyArcher.h"
#include "Cataphract.h"
#include "HorseArcher.h"

std::unique_ptr<Unit> ConcreteUnitFactory::createUnit(const std::string& type, int x, int y) const {
    if (type == "Swordsman") return std::make_unique<Swordsman>(x, y);
    if (type == "Spearman") return std::make_unique<Spearman>(x, y);
    if (type == "LightArcher") return std::make_unique<LightArcher>(x, y);
    if (type == "HeavyArcher") return std::make_unique<HeavyArcher>(x, y);
    if (type == "Cataphract") return std::make_unique<Cataphract>(x, y);
    if (type == "HorseArcher") return std::make_unique<HorseArcher>(x, y);
    return nullptr;
}