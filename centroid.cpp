// example: one class, two objects
#include <iostream>

class tetrahedron  {
    double cx[4];
    double cy[4];
    double cz[4];
  public:
    void set_values (double,double,double,double);
    double * centroid (){
    	double GC[3];

    	GC[0] = (cx [0] + cx [1] + cx [2] + cx [3])/4;
    	GC[1] = (cy [0] + cy [1] + cy [2] + cy [3])/4;
    	GC[2] = (cz [0] + cz [1] + cz [2] + cz [3])/4;

    	return GC;
    }
};

void tetrahedron ::set_values (double n1, double n2, double n3, double n4) {
	cx [0]  = n1[0]; 
	cx [1]  = n2[0];
	cx [2]  = n3[0]; 
	cx [3]  = n2[0];
	cy [0]  = n1[1]; 
	cy [1]  = n2[1];
	cy [2]  = n3[1]; 
	cy [3]  = n2[1];
	cz [0]  = n1[2]; 
	cz [1]  = n2[2];
	cz [2]  = n3[2]; 
	cz [3]  = n2[2];
}

int main () {
  tetrahedron tet;
  double n1[3], n2[3], n3[3], n4[3];
  n1[3] = {3,2,-1};
  n2[3] = {5,0,2};
  n3[3] = {-4,5,7};
  n4[3] = {-2,4,1};
  tet.set_values (n1,n2,n3,n4);
  double *gc;
  gc = tet.centroid();
  for ( int i = 0; i < 3; i++ ) {
      cout << "*(gc + " << i << ") : ";
      cout << *(gc + i) << endl;
   }
 
  return 0;
}