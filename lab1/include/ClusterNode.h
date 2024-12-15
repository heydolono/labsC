#ifndef CLUSTERNODE_H
#define CLUSTERNODE_H

#include "GpuSpec.h"
#include "CpuSpec.h"
#include "RamSpec.h"
#include "LanSpec.h"

class ClusterNode {
public:
    GpuSpec gpu;
    CpuSpec cpu;
    RamSpec ram;
    LanSpec lan;

    void Print() const;
    void Export(std::ofstream& out) const;
    void Import(std::ifstream& in);
};

#endif // CLUSTERNODE_H
