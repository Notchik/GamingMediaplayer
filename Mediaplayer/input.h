#ifndef INPUT_H
#define INPUT_H
#pragma once
#include "exeption.h"

class Input : public Exeption
{
public:
    Input(QString name):Exeption(name) {}
};
#endif // INPUT_H
