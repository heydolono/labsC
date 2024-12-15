#include "LanSpec.h"

LanSpec::LanSpec(std::string speed) : speed(speed) {}

void LanSpec::Print() const {
    std::cout << "LAN: " << speed << std::endl;
}

void LanSpec::Export(std::ofstream& out) const {
    out << "LAN," << speed << std::endl;
}

void LanSpec::Import(std::ifstream& in) {
    std::string type;
    std::getline(in, type, ',');
    std::getline(in, speed);
}
