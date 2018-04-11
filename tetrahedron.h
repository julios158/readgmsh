//
// Created by julioa on 10/04/18.
//

#ifndef CENTROID_TETRAHEDRON_H
#define CENTROID_TETRAHEDRON_H
#include <iostream>
#include <array>


class tetrahedron {
    // attributes
    std::array<std::array<double, 3>, 4> nodes;
    std::array<std::array<double, 4>, 1> elem;

public:
    // constructor of null base
    tetrahedron () {}

    // destructor
    ~tetrahedron() {}

    std::array<std::array<double, 3>, 1>GC;

    //set values of coordinate points of the tetrahedron
    void set_values (std::array<std::array<double, 3>, 4>,std::array<std::array<double, 4>, 1>);
    //calculate the centroid coordinates of the tetrahedron
    void  centroid ();
    //print the centroid coordinates of the tetrahedron
    void print_centroid_coord(std::array<std::array<double, 3>, 1>);
};

#endif //CENTROID_TETRAHEDRON_H
