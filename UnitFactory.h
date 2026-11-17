#pragma once
#include <memory>
#include <string>
#include "Unit.h"

class UnitFactory {
public:
    virtual ~UnitFactory() = default;
    virtual std::unique_ptr<Unit> createUnit(const std::string& type, int x, int y) const = 0;
};
