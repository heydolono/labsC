#include "ClusterNode.h"

void ClusterNode::Print() const {
    gpu.Print();
    cpu.Print();
    ram.Print();
    lan.Print();
}

void ClusterNode::Export(std::ofstream& out) const {
    gpu.Export(out);
    cpu.Export(out);
    ram.Export(out);
    lan.Export(out);
}

void ClusterNode::Import(std::ifstream& in) {
    gpu.Import(in);
    cpu.Import(in);
    ram.Import(in);
    lan.Import(in);
}
