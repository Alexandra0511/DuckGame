#include "object2D.h"

#include <vector>

#include "core/engine.h"
#include "utils/gl_utils.h"


Mesh* myObjects::CreateSquare(
    const std::string& name,
    glm::vec3 leftBottomCorner,
    float length,
    glm::vec3 color,
    bool fill)
{
    glm::vec3 corner = leftBottomCorner;

    std::vector<VertexFormat> vertices =
    {
        VertexFormat(corner, color),
        VertexFormat(corner + glm::vec3(length, 0, 0), color),
        VertexFormat(corner + glm::vec3(length, length, 0), color),
        VertexFormat(corner + glm::vec3(0, length, 0), color)
    };

    Mesh* square = new Mesh(name);
    std::vector<unsigned int> indices = { 0, 1, 2, 3 };

    if (!fill) {
        square->SetDrawMode(GL_LINE_LOOP);
    }
    else {
        // Draw 2 triangles. Add the remaining 2 indices
        indices.push_back(0);
        indices.push_back(2);
    }

    square->InitFromData(vertices, indices);
    return square;
}

Mesh* myObjects::CreateTriangle(const std::string& name,
    glm::vec3 corner1, 
    glm::vec3 corner2, 
    glm::vec3 corner3,
    glm::vec3 color){

    std::vector<VertexFormat> vertices =
    {
        VertexFormat(corner1, color),
        VertexFormat(corner2, color),
        VertexFormat(corner3, color)
    };

    Mesh* triangle = new Mesh(name);
    std::vector<unsigned int> indices = { 0, 1, 2 };

    triangle->SetDrawMode(GL_TRIANGLES);

    triangle->InitFromData(vertices, indices);
    return triangle;
}

Mesh* myObjects::CreateRectangle(
    const std::string& name,
    glm::vec3 leftBottomCorner,
    float length,
    float heigth,
    glm::vec3 color,
    bool fill)
{
    glm::vec3 corner = leftBottomCorner;

    std::vector<VertexFormat> vertices =
    {
        VertexFormat(corner, color),
        VertexFormat(corner + glm::vec3(length, 0, 0), color),
        VertexFormat(corner + glm::vec3(length, heigth, 0), color),
        VertexFormat(corner + glm::vec3(0, heigth, 0), color)
    };

    Mesh* rectangle = new Mesh(name);
    std::vector<unsigned int> indices = { 0, 1, 2, 3 };

    if (!fill) {
        rectangle->SetDrawMode(GL_LINE_LOOP);
    }
    else {
        // Draw 2 triangles. Add the remaining 2 indices
        indices.push_back(0);
        indices.push_back(2);
    }

    rectangle->InitFromData(vertices, indices);
    return rectangle;
}

Mesh* myObjects::CreateCircle(
    const std::string& name,
    glm::vec3 center,
    float radius,
    glm::vec3 color,
    bool fill)
{
    int numTriangles = 100;
    float pi = 3.1415926f;
    std::vector<unsigned int> indices;
    std::vector<VertexFormat> vertices;
    

    Mesh* circle = new Mesh(name);
    for (int i = 0; i < numTriangles; i++) {
        float angle = 2.0f * pi * float(i) / float(numTriangles);//get the current angle

        float x = radius * cosf(angle);
        float y = radius * sinf(angle);
        vertices.push_back(VertexFormat(glm::vec3(center.x + x, center.y + y, 0), color));
        indices.push_back(i);
    }
   

    if (fill) {
        circle->SetDrawMode(GL_TRIANGLE_FAN);
    }
    else {
        circle->SetDrawMode(GL_LINE_LOOP);
    }

    circle->InitFromData(vertices, indices);
    return circle;
}

