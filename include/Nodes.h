#ifndef LEM_CENTROID_NODES_H
#define LEM_CENTROID_NODES_H
#include <array>
#include <iostream>

class Nodes
{
    public:
        /** constructor */
        Nodes(unsigned id, const std::array<double, 3>coords);
        Nodes();
        //! Return id of the node
        unsigned id() const { return id_; }
        //! Return coordinates
        //! \param[out] coordinates_ return coordinates of the node
        std::array<double, 3> coordinates() const { return coordinates_; }

    protected:
        //! node id
        unsigned id_;
        //! nodal coordinates
        std::array<double, 3>coordinates_;
};

#endif // LEM_CENTROID_NODES_H
