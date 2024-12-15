#ifndef LANSPEC_H
#define LANSPEC_H

#include <string>
#include <iostream>
#include <fstream>

class LanSpec {
public:
    std::string speed;

    LanSpec(std::string speed = "");
    void Print() const;
    void Export(std::ofstream& out) const;
    void Import(std::ifstream& in);
};

#endif // LANSPEC_H
