#include "Nodes.h"
#include <array>
#include <iostream>

Nodes::Nodes(){};
Nodes::Nodes(unsigned id, const std::array<double, 3>coords)
{id_=id; coordinates_=coords;};

