#include "GpuSpec.h"
#include "CpuSpec.h"
#include "RamSpec.h"
#include "LanSpec.h"
#include "ClusterNode.h"
#include "Cluster.h"

int main() {
    GpuSpec gpu("NVIDIA RTX 3090", 24576);
    CpuSpec cpu("AMD Ryzen 9 5950X", 16);
    RamSpec ram(32768);
    LanSpec lan("10Gbps");

    ClusterNode node;
    node.gpu = gpu;
    node.cpu = cpu;
    node.ram = ram;
    node.lan = lan;

    Cluster cluster;
    cluster.AddNode(node);

    cluster.Export("cluster.txt");

    Cluster importedCluster;
    importedCluster.Import("cluster.txt");

    importedCluster.Print();

    return 0;
}
