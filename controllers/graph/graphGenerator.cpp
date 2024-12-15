#include <iostream>
#include <fstream>
#include <cstdlib>

void generateGraphvizFiles(const std::string& dotContent, const std::string& fileName) {
    // Define the paths for the DOT and PNG files
    std::string dotFilePath = "../src/" + fileName + ".dot";
    std::string pngFilePath = "../src/" + fileName + ".png";

    // Create and write the DOT file
    std::ofstream dotFile(dotFilePath);
    if (dotFile.is_open()) {
        dotFile << dotContent;
        dotFile.close();
        std::cout << "DOT file created at: " << dotFilePath << std::endl;
    } else {
        std::cerr << "Unable to open file for writing: " << dotFilePath << std::endl;
        return;
    }

    // Generate the PNG file using the DOT file
    std::string command = "dot -Tpng " + dotFilePath + " -o " + pngFilePath;
    int result = std::system(command.c_str());
    if (result == 0) {
        std::cout << "PNG file created at: " << pngFilePath << std::endl;
    } else {
        std::cerr << "Error generating PNG file." << std::endl;
    }



}