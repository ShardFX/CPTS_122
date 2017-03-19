#pragma once

#include "BST.h"

#include <fstream>
#include <sstream>

using std::string;

void fillBST(BST &table, string filename);

void convertAndDisplay(string convertFile, BST refTable);