#include "CpuSpec.h"

CpuSpec::CpuSpec(std::string model, int cores) : model(model), cores(cores) {}

void CpuSpec::Print() const {
    std::cout << "CPU: " << model << ", Cores: " << cores << std::endl;
}

void CpuSpec::Export(std::ofstream& out) const {
    out << "CPU," << model << "," << cores << std::endl;
}

void CpuSpec::Import(std::ifstream& in) {
    std::string type;
    std::getline(in, type, ',');
    std::getline(in, model, ',');
    in >> cores;
    in.ignore();
}
