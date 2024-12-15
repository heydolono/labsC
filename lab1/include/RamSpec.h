#ifndef RAMSPEC_H
#define RAMSPEC_H

#include <iostream>
#include <fstream>

class RamSpec {
public:
    int size;

    RamSpec(int size = 0);
    void Print() const;
    void Export(std::ofstream& out) const;
    void Import(std::ifstream& in);
};

#endif // RAMSPEC_H
