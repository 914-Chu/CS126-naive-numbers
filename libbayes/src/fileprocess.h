#pragma once

#include "model.hpp"
#include <iostream>
#include <vector>
#include <string>

using namespace std;

namespace fileprocess{

    istream & operator >> (istream &in,  string &file_name);
    ostream & operator << (ostream &out, const string &file_name);
}