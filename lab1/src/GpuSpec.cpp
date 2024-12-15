#include "GpuSpec.h"

GpuSpec::GpuSpec(std::string model, int memory) : model(model), memory(memory) {}

void GpuSpec::Print() const {
    std::cout << "GPU: " << model << ", Memory: " << memory << " MB" << std::endl;
}

void GpuSpec::Export(std::ofstream& out) const {
    out << "GPU," << model << "," << memory << std::endl;
}

void GpuSpec::Import(std::ifstream& in) {
    std::string type;
    std::getline(in, type, ',');
    std::getline(in, model, ',');
    in >> memory;
    in.ignore();
}
