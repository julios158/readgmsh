// example: one class, two objects
#include <array>
#include <fstream>
#include <iostream>
#include <string>
#include "tetrahedron.h"


int main () {

    Tetrahedron tet;
    // Tetrahedron coordinates point
    std::array<std::array<double, 3>, 4> points{{ {3,2,-1}, {5, 0, 2},{-4,5,7}, {-2,4,1}}};

    tet.tetrahedron_centroid(points);
   // std::array<double, 3>gc= tet.centroid;
    tet.print_centroid_coord();


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

    infile.close();

   // system ("pause");


}