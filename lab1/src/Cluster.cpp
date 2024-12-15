#include "Cluster.h"
#include <iostream>
#include <fstream>

void Cluster::AddNode(const ClusterNode& node) {
    nodes.push_back(node);
}

void Cluster::Print() const {
    for (size_t i = 0; i < nodes.size(); ++i) {
        std::cout << "Node " << i + 1 << ":" << std::endl;
        nodes[i].Print();
        std::cout << std::endl;
    }
}

void Cluster::Export(const std::string& filename) const {
    std::ofstream out(filename);
    if (!out) {
        std::cerr << "Error: Cannot open file for export!" << std::endl;
        return;
    }
    for (const auto& node : nodes) {
        node.Export(out);
    }
    out.close();
}

void Cluster::Import(const std::string& filename) {
    std::ifstream in(filename);
    if (!in) {
        std::cerr << "Error: Cannot open file for import!" << std::endl;
        return;
    }
    nodes.clear();
    while (in.peek() != EOF) {
        ClusterNode node;
        node.Import(in);
        nodes.push_back(node);
    }
    in.close();
}
