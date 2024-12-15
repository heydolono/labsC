#include "GpuSpec.h"
#include "CpuSpec.h"
#include "RamSpec.h"
#include "LanSpec.h"
#include "ClusterNode.h"
#include "Cluster.h"
#include <gtest/gtest.h>

TEST(GpuSpecTest, Initialization) {
    GpuSpec gpu("NVIDIA RTX 3090", 24576);
    EXPECT_EQ(gpu.model, "NVIDIA RTX 3090");
    EXPECT_EQ(gpu.memory, 24576);
}

TEST(ClusterTest, AddNode) {
    Cluster cluster;
    ClusterNode node;
    node.gpu = GpuSpec("NVIDIA RTX 3090", 24576);
    cluster.AddNode(node);
    EXPECT_EQ(cluster.nodes.size(), 1);
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
