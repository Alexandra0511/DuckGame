#pragma once

#include <string>

#include "core/gpu/mesh.h"
#include "utils/glm_utils.h"


namespace myObjects
{

    // Create square with given bottom left corner, length and color
    Mesh* CreateSquare(const std::string& name, glm::vec3 leftBottomCorner, float length, glm::vec3 color, bool fill = false);
    Mesh* CreateTriangle(const std::string& name, glm::vec3 corner1, glm::vec3 corner2, glm::vec3 corner3, glm::vec3 color);
    Mesh* CreateRectangle(const std::string& name, glm::vec3 leftBottomCorner, float length, float heigth, glm::vec3 color, bool fill = false);
    Mesh* CreateCircle(const std::string& name, glm::vec3 center, float radius, glm::vec3 color, bool fill);
}
#pragma once
