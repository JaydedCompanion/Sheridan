//
// Created by Jayde Iris Callejas on 2025-09-09.
//

#include <string>
#include <iostream>
#include <fstream>

#include <glm/glm.hpp>
#include <glm/ext.hpp>

void exportOBJ(glm::vec3 a[], glm::vec3 b[], std::string filename) {
    filename = std::__fs::filesystem::current_path().append("../" + filename);
    std::cout << "Parsing " << a->length() << " vertices to OBJ format.\n";
    std::string objData;
    std::string faceBuffer;
    int vertexIndex = 1; // OBJ vertex indices start at 1 apparently...
    objData += "\n# Face A:\n";
    for (int i = 0; i < a->length(); i++) {
        objData += "v " + std::to_string(a[i].x) + " " + std::to_string(a[i].y) + " " + std::to_string(a[i].z) + "\n";
        faceBuffer += std::to_string(vertexIndex) + " ";
        vertexIndex++;
    }
    objData += "f " + faceBuffer + "\n";
    faceBuffer = "";
    objData += "\n# Face B:\n";
    for (int i = 0; i < b->length(); i++) {
        objData += "v " + std::to_string(b[i].x) + " " + std::to_string(b[i].y) + " " + std::to_string(b[i].z) + "\n";
        faceBuffer += std::to_string(vertexIndex) + " ";
        vertexIndex++;
    }
    objData += "f " + faceBuffer + "\n";
    // std::cout << "OBJ data: " << objData << std::endl; // Uncomment this line to print OBJ data to console.
    std::cout << "Writing OBJ data to \"" << filename << "\".\n";
    std::ofstream obj;
    obj.open (filename);
    obj << objData;
    obj.close();
}