#ifndef CLUSTER_H
#define CLUSTER_H

#include <vector>
#include "ClusterNode.h"

class Cluster {
public:
    std::vector<ClusterNode> nodes;

    void AddNode(const ClusterNode& node);
    void Print() const;
    void Export(const std::string& filename) const;
    void Import(const std::string& filename);
};

#endif // CLUSTER_H
