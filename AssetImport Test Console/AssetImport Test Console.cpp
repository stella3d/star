// AssetImport Test Console.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "PlyImporter.h"
using namespace StarEditor;

bool has_suffix(const std::string& str, const std::string& suffix)
{
    return str.size() >= suffix.size() &&
        str.compare(str.size() - suffix.size(), suffix.size(), suffix) == 0;
}

int main(int argc, char* argv[])
{
    std::cout << "Argument Count: " << argc << std::endl;

    //for (size_t i = 0; i < argc; i++)
    //    std::cout << argv[i] << std::endl;

    if (argc < 2)
        std::cout << "\nRequires a filename as the second argument!" << std::endl;

    std::string fileArgument = argv[1];
    if (has_suffix(fileArgument, ".ply"))
    {
        std::cout << "\nPLY file import requested!  Which is good because it's all this supports" << std::endl;

        PlyImporter importer = * new PlyImporter();
        importer.ImportFile(fileArgument);

        std::cout << "\nmade it to the end without crashing!" << std::endl;
    }
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
