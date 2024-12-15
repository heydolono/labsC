#include "RamSpec.h"
#include <string>

RamSpec::RamSpec(int size) : size(size) {}

void RamSpec::Print() const {
    std::cout << "RAM: " << size << " MB" << std::endl;
}

void RamSpec::Export(std::ofstream& out) const {
    out << "RAM," << size << std::endl;
}

void RamSpec::Import(std::ifstream& in) {
    std::string type;
    std::getline(in, type, ',');
    in >> size;
    in.ignore();
}
