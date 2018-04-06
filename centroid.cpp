// example: one class, two objects
#include <iostream>
#include <array>

class tetrahedron  {
    std::array<double, 3> n1;
    std::array<double, 3> n2;
    std::array<double, 3> n3;
    std::array<double, 3> n4;

public:
    //set values of coordinate points of the tetrahedron 
    void set_values (std::array<double, 3>,std::array<double, 3>,std::array<double, 3>,std::array<double, 3>);
    //calculate the centroid coordinates of the tetrahedron
    void  centroid (std::array<double, 3>  & GC){

        GC[0] = (n1 [0] + n2 [0] + n3 [0] + n4 [0])/4;
        GC[1] = (n1 [1] + n2 [1] + n3 [1] + n4 [1])/4;
        GC[2] = (n1 [2] + n2 [2] + n3 [2] + n4 [2])/4;

    }
   //print the centroid coordinates of the tetrahedron
    void print_centroid_coord(const std::array<double, 3> &n)
    {
        std::cout << "centroid coordinated of tetrahedron"<< std::endl;
        for (int j = 0; j < n.size(); j++ )
        {
            std::cout << "GC[" << j << "] = " << n[j] << std::endl;
        }
    }
};
// constructor
void tetrahedron ::set_values (std::array<double, 3> p1,std::array<double, 3>p2,std::array<double, 3>p3,std::array<double, 3>p4)
{
    n1 = p1;
    n2 = p2;
    n3 = p3;
    n4 = p4;
}

int main () {
    tetrahedron tet;
    std::array<double, 3> a1{ {3,2,-1} };
    std::array<double, 3> a2{ {5,0, 2} };
    std::array<double, 3> a3{ {-4,5,7} };
    std::array<double, 3> a4{ {-2,4,1} };

    tet.set_values (a1,a2,a3,a4);
    std::array<double, 3> gc;
    tet.centroid(gc);
    tet.print_centroid_coord(gc);
}
