// example: one class, two objects
#include <iostream>
#include <array>
#include <fstream>
#include <string>
#include "tetrahedron.h"


int main () {

    tetrahedron tet;
    //  nodes coordinates
    std::array<std::array<double, 3>, 4> nodes{{ {3,2,-1}, {5, 0, 2},{-4,5,7}, {-2,4,1}}};
    // nodal incidence
    std::array<std::array<double, 4>, 1> elem{{ 0,1,2,3 }};

    tet.set_values (nodes,elem);
    tet.centroid();
    std::array<std::array<double, 3>, 1>gc= tet.GC;
    tet.print_centroid_coord(gc);


    std::string line;
    std::ifstream infile;
    infile.open("/home/julioa/CLionProjects/centroid/cube.msh");

    if(!infile.is_open())
    {
        std::cout << " could not open file" << std::endl;
        std::cout << " program Terminating....\n";
        exit(EXIT_FAILURE);
    }

    while(line != "$EndElements") // To get you all the lines.
    {
        getline(infile,line); // Saves the line in STRING.
        std::cout<<line; // Prints our STRING.
    }

    //infile.close();

   // system ("pause");


}