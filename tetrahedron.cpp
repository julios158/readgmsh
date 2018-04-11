//
// Created by julioa on 10/04/18.
//

#include "tetrahedron.h"
#include <iostream>
#include <array>

//print the centroid coordinates of the tetrahedron
void tetrahedron ::set_values (std::array<std::array<double, 3>, 4> nn,std::array<std::array<double, 4>, 1>ne)
{
    nodes = nn;
    elem = ne;
}
// centroid calculation
void tetrahedron::centroid (){

    double n1x = nodes[elem[0][0]][0];
    double n2x = nodes[elem[0][1]][0];
    double n3x = nodes[elem[0][2]][0];
    double n4x = nodes[elem[0][3]][0];

    double n1y = nodes[elem[0][0]][1];
    double n2y = nodes[elem[0][1]][1];
    double n3y = nodes[elem[0][2]][1];
    double n4y = nodes[elem[0][3]][1];

    double n1z = nodes[elem[0][0]][2];
    double n2z = nodes[elem[0][1]][2];
    double n3z = nodes[elem[0][2]][2];
    double n4z = nodes[elem[0][3]][2];

    GC[0][0] = (n1x + n2x + n3x + n4x)/4;
    GC[0][1] = (n1y + n2y + n3y + n4y)/4;
    GC[0][2] = (n1z + n2z + n3z + n4z)/4;

}
// print centroid coordinates
void tetrahedron::print_centroid_coord(std::array<std::array<double, 3>, 1>n)
{
    std::cout << "centroid coordinated of tetrahedron"<< std::endl;
    for (int j = 0; j < n[0].size(); j++ )
    {
        std::cout << "GC[" << j << "] = " << n[0][j] << std::endl;
    }
}
