#pragma once

/**
    This file declares the BVH class which represents
    Bounding Volume Hierarchy Acceleration Structure
    using AABB(Axis Aligned Bounding Box).
    Courtesy :- https://github.com/VertexC/glass-chess
**/

#include "Acceleration.hpp"
#include "../utilities/BBox.hpp"

class World;

// Node of a BVH Tree
struct Node {
    BBox bbox;
    int start, num_primitives, offset;
};

// Node to keep track of objects inside a node
struct BvhEntry {
    int parent;
    int left, right;
};

// Node to store traversal information
struct BVHTraversal {
    int i; // node             
    float mint; // minimum hit time for this node.          
    BVHTraversal() {}
    BVHTraversal(int _i, float _mint) : i(_i), mint(_mint) {}
};
// Acceleration BVH Class
class BVH : public Acceleration {
    protected:
        std::vector<Geometry*> geom_array; // Vector of Geometry
        Node* bvhTree;                     // Root Node
        int node_num, leaf_num;            // Number of nodes and leafs.

    public:
        // constructors
        BVH() = default;
        BVH(World* w_ptr);

        // destructor
        virtual ~BVH();

        void build();
        virtual ShadeInfo hit(const Ray &ray) override;
};