//
// Created by Jayde Iris Callejas on 2025-09-09.
//

#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include <filesystem>

#include <glm/glm.hpp>
#include <glm/ext.hpp>

void exportOBJ(std::vector<glm::vec3> a, std::vector<glm::vec3> b, std::string filename) {
    filename = std::filesystem::current_path().append("../" + filename).string();
    std::cout << "Parsing " << a.size() * 2 << " vertices to OBJ format.\n";
    std::string objData;
    int vertexIndex = 1; // OBJ vertex indices start at 1 apparently...
    objData += "\n# Face A:\n";
    for (int i = 0; i < a.size(); i++) {
        objData += "v " + std::to_string(a[i].x) + " " + std::to_string(a[i].y) + " " + std::to_string(a[i].z) + "\n";
        vertexIndex++;
    }
    objData += "\n# Face B:\n";
    for (int i = 0; i < b.size(); i++) {
        objData += "v " + std::to_string(b[i].x) + " " + std::to_string(b[i].y) + " " + std::to_string(b[i].z) + "\n";
        vertexIndex++;
    }
    objData += "f 1 2 3\nf 2 3 4\nf 5 6 7\nf6 7 8";
    //std::cout << "OBJ data: " << objData << std::endl; // Uncomment this line to print OBJ data to console.
    std::cout << "Writing OBJ data to \"" << filename << "\".\n";
    std::ofstream obj;
    obj.open (filename);
    obj << objData;
    obj.close();
}