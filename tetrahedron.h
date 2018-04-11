//
// Created by julioa on 10/04/18.
//

#ifndef CENTROID_TETRAHEDRON_H
#define CENTROID_TETRAHEDRON_H
#include <array>
#include <iostream>


class Tetrahedron {
    // attributes
    std::array<double, 3> centroid;


public:
    //calculate the centroid coordinates of the tetrahedron
    void  tetrahedron_centroid (std::array<std::array<double, 3>, 4>);
    //print the centroid coordinates of the tetrahedron
    void print_centroid_coord();
};

#endif //CENTROID_TETRAHEDRON_H
