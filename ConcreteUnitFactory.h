#pragma once
#include "UnitFactory.h"

class ConcreteUnitFactory : public UnitFactory {
public:
    std::unique_ptr<Unit> createUnit(const std::string& type, int x, int y) const override;
};
