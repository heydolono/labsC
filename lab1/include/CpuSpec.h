#ifndef CPUSPEC_H
#define CPUSPEC_H

#include <string>
#include <iostream>
#include <fstream>

class CpuSpec {
public:
    std::string model;
    int cores;

    CpuSpec(std::string model = "", int cores = 0);
    void Print() const;
    void Export(std::ofstream& out) const;
    void Import(std::ifstream& in);
};

#endif // CPUSPEC_H
