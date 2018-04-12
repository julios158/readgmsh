// File: tetrahedron.h
// Details: Implementation of  tetrahedron class for calculate a centroid of a tetrahedron.
// Author: Julio Rueda on 10/04/18.
// Version: 2.0 - 2014; 1.0 - 2011.
//

#ifndef LEM_CENTROID_TETRAHEDRON_H
#define LEM_CENTROID_TETRAHEDRON_H
#include <array>
#include <iostream>


class Tetrahedron {
    // attributes
    std::array<double, 3> centroid;
/*--------------------------------------------
TET
--------------------------------------------

               n4
             / | \
            /  |  \
           /   |   \
         /     |     \
        /      |      \
       /       |       \
     /         |        \
    /          |          \
   /           |           \
 n1------------|-----------n3
   \           |           /
     \         |         /
       \       |       /
         \     |     /
           \   |   /
             \ | /
               n2
--------------------------------------------*/

public:
    std::array<std::array<double, 3>, 4>coord_points;
    //calculate the centroid coordinates of the tetrahedron
    // input: coordinates of 4 point  coord(ni,(x,y,z))
    void  compute_centroid ();
    //print the centroid coordinates of the tetrahedron
    void print_centroid_coord();
};

#endif //CENTROID_TETRAHEDRON_H
