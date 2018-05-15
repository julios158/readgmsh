#include <iostream>
#include "read_mesh_file.h"
#include <vector>
//! \briefClass for ReadGmsh file.
//! \details read and store nodes coordinates and nodal incidence of elements
//! \@param inputstream_ file
ReadGmsh::ReadGmsh(std::istream & _is): inputstream_(_is) {
}

ReadGmsh::~ReadGmsh() {
}

//! \Search for a section named "$sectionName" in the ReadGmsh's stream.
//! \@param  section_name name of the section to search for
//! \@return true if the section is found, false otherwise
 bool ReadGmsh::find_section(std::string section_name) {//the function findSection look for the interest line
	std::string line;
	std::string line_name;
	bool found_section_name = false;

	while(getline(inputstream_, line)) {

		std::istringstream linestream(line);
		linestream >> line_name;
		found_section_name = (line_name == section_name);

		if(found_section_name) {
			break;
		}
	}
	return found_section_name;
}
//! \Read mesh nodes from an input file.
//! \@return nodes coordinates
std::vector <std::vector<double> > ReadGmsh::read_coords_nodes()
{
    find_section("$Nodes");
    std::string line;
	std::istringstream linestream;
    getline(inputstream_, line);
	linestream.str(line);
	int nnodes; int id_temp;
	D3dim_ = false; // default dimension analysis
	linestream >> nnodes;
    std::vector <std::vector<double> > coords_nodes(nnodes, std::vector<double>(3, 0));
    // read node coordinates
    for(int i = 0; i < nnodes; i++){
            getline(inputstream_, line);
			linestream.str(line);
			linestream.clear();
			linestream >> id_temp;
            for(int k = 0; k < 3; k++) {
                linestream >> coords_nodes.at(i).at(k);
            }
            // checking two or three dimensional mesh
            if ( coords_nodes.at(i).at(2) != 0. )
                D3dim_ = 3;
     }
      return coords_nodes;
}
//! \Read mesh nodal incidence from an input file.
void ReadGmsh::read_nodal_incidence()
{
    find_section("$Elements");
    std::string line;
	std::istringstream linestream;
    getline(inputstream_, line);
	linestream.str(line);
	int nelements; int id_temp; int elem_type; int temp;
	linestream >> nelements;
    for(int i = 0; i < nelements; i++){
            getline(inputstream_, line);
			linestream.str(line);
			linestream.clear();
			linestream >> id_temp >> elem_type;
			std::vector<int> incidence;
			if ( elem_type == 1 ){ //line element, 2 nodes
                    int no1; int no2;
                    linestream>>temp>>temp>>temp>>no1>> no2;
                    incidence.push_back(no1-1);incidence.push_back(no2-1);
                    line_elements_.push_back(incidence);
                    }
            if ( elem_type == 2 ){ // triangle element, 3 nodes
                    int no1; int no2; int no3;
                    linestream>>temp>>temp>>temp>>no1>> no2 >> no3;
                    incidence.push_back(no1-1);
                    incidence.push_back(no2-1);
                    incidence.push_back(no3-1);
                    triangle_elements_.push_back(incidence);
                    }
            if ( elem_type == 4 ){ //tetrahedron element, 4 nodes
                    int no1; int no2; int no3; int no4;
                    linestream>>temp>>temp>>temp>>no1>> no2 >> no3 >> no4;
                    incidence.push_back(no1-1);
                    incidence.push_back(no2-1);
                    incidence.push_back(no3-1);
                    incidence.push_back(no4-1);
                    tetrahedron_elements_.push_back(incidence);
                    }
     }
}

