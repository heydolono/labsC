#ifndef GPUSPEC_H
#define GPUSPEC_H

#include <string>
#include <iostream>
#include <fstream>

class GpuSpec {
public:
    std::string model;
    int memory;

    GpuSpec(std::string model = "", int memory = 0);
    void Print() const;
    void Export(std::ofstream& out) const;
    void Import(std::ifstream& in);
};

#endif // GPUSPEC_H
