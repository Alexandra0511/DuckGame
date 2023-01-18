#include "lab_m1/Tema1/tema1.h"

#include <vector>
#include <iostream>

#include "lab_m1/Tema1/transformari.h"
#include "lab_m1/Tema1/object2D.h"
#include "components/text_renderer.h"

#include <cstdlib>
#include <ctime>

using namespace std;
using namespace m1;
using namespace gfxc;



/*
 *  To find out more about `FrameStart`, `Update`, `FrameEnd`
 *  and the order in which they are called, see `world.cpp`.
 */


Tema1::Tema1()
{
}


Tema1::~Tema1()
{
}


void Tema1::Init()
{
    glm::ivec2 resolution = window->GetResolution();
    auto camera = GetSceneCamera();
    camera->SetOrthographic(0, (float)resolution.x, 0, (float)resolution.y, 0.01f, 400);
    camera->SetPosition(glm::vec3(0, 0, 50));
    camera->SetRotation(glm::vec3(0, 0, 0));
    camera->Update();
    GetCameraInput()->SetActive(false);
    //cout << resolution.y;
    glm::vec3 corner = glm::vec3(0, 0, 0);
    float squareSide = 100;
    float grassHeigth = 200;
    float radius = 30;

    // Initialize tx and ty (the translation steps)
    time_t t;
    srand((unsigned int)std::time(0));
    translateX = (rand() % 1000 + 100);
    translateY = -200;
    
    cout << "translateX" << translateX <<endl;
    // Initialize sx and sy (the scale factors)
    scaleX = 1;
    scaleY = 1;
    speed = 250;
    rateAparute = 0;
    // Initialize angularStep
    angularStep = -0.3;
    angularStep2 = 0.3;
    aux = (float )((rand() % 130 + 10) / (float)100);
   
    alfa = aux;
    alfac = aux;
    
    movementX = true;
    movementY = true;
    bullets = 3;
    lives = 3;
    score = 0;
    gameOver = false;
    gameWon = false;
    lvl = 1;
    
    str1 = new gfxc::TextRenderer(window->props.selfDir, resolution.x, resolution.y);
    str1->Load(PATH_JOIN(window->props.selfDir, RESOURCE_PATH::FONTS, "Hack-Bold.ttf"), 100);
    
    str2 = new gfxc::TextRenderer(window->props.selfDir, resolution.x, resolution.y);
    str2->Load(PATH_JOIN(window->props.selfDir, RESOURCE_PATH::FONTS, "Hack-Bold.ttf"), 60);

    level = new gfxc::TextRenderer(window->props.selfDir, resolution.x, resolution.y);
    level->Load(PATH_JOIN(window->props.selfDir, RESOURCE_PATH::FONTS, "Hack-Bold.ttf"), 40);
    /*Mesh* background = new Mesh("background");
    background->LoadMesh(PATH_JOIN(window->props.selfDir, RESOURCE_PATH::MODELS, "background/"), "background.fbx");
    AddMeshToList(background);*/
    
 
    //iarba
    Mesh* rectangle1 = myObjects::CreateRectangle("rectangle1", corner, resolution.x, grassHeigth, glm::vec3(0.04, 0.2, 0), true);
    AddMeshToList(rectangle1);
    
    //corp
    Mesh* triangle1 = myObjects::CreateTriangle("triangle1", glm::vec3(10, 200, 0), glm::vec3(10, 280, 0), glm::vec3(160, 240, 0), glm::vec3(0.50, 0.00, 0.08));
    AddMeshToList(triangle1);

    //cap
    Mesh* circle1 = myObjects::CreateCircle("circle1", glm::vec3(160, 240, 0), radius,  glm::vec3(0.00, 0.20, 0.07), true);
    AddMeshToList(circle1);

    //ochi
    Mesh* circle2 = myObjects::CreateCircle("circle2", glm::vec3(175, 250, 0), 6, glm::vec3(1, 1, 1), true);
    AddMeshToList(circle2);
    Mesh* circle3 = myObjects::CreateCircle("circle3", glm::vec3(175, 250, 0), 3, glm::vec3(0, 0, 0), true);
    AddMeshToList(circle3);

    //cioc
    Mesh* triangle2 = myObjects::CreateTriangle("triangle2", glm::vec3(185, 230, 0), glm::vec3(185, 250, 0), glm::vec3(220, 240, 0), glm::vec3(1.00, 0.84, 0.00));
    AddMeshToList(triangle2);

    //aripa jos
    Mesh* triangle3 = myObjects::CreateTriangle("triangle3", glm::vec3(45, 250, 0), glm::vec3(105, 250, 0), glm::vec3(75, 140, 0), glm::vec3(0.50, 0.00, 0.08));
    AddMeshToList(triangle3);

    //aripa sus
    Mesh* triangle4 = myObjects::CreateTriangle("triangle4", glm::vec3(45, 230, 0), glm::vec3(105, 230, 0), glm::vec3(75, 340, 0), glm::vec3(0.50, 0.00, 0.08));
    AddMeshToList(triangle4);

    //vieti
    Mesh* circle4 = myObjects::CreateCircle("circle4", glm::vec3(1000, 690, 0), 20, glm::vec3(1, 0, 0), true);
    AddMeshToList(circle4);
    Mesh* circle5 = myObjects::CreateCircle("circle5", glm::vec3(1050, 690, 0), 20, glm::vec3(1, 0, 0), true);
    AddMeshToList(circle5);
    Mesh* circle6 = myObjects::CreateCircle("circle6", glm::vec3(1100, 690, 0), 20, glm::vec3(1, 0, 0), true);
    AddMeshToList(circle6);

    //gloante
    Mesh* rectangle2 = myObjects::CreateRectangle("rectangle2", glm::vec3(1150, 670, 0), 20, 40, glm::vec3(0, 0.2, 0), false);
    AddMeshToList(rectangle2);
    Mesh* rectangle3 = myObjects::CreateRectangle("rectangle3", glm::vec3(1190, 670, 0), 20, 40, glm::vec3(0, 0.2, 0), false);
    AddMeshToList(rectangle3);
    Mesh* rectangle4 = myObjects::CreateRectangle("rectangle4", glm::vec3(1230, 670, 0), 20, 40, glm::vec3(0, 0.2, 0), false);
    AddMeshToList(rectangle4);

    //scor
    Mesh* rectangle5 = myObjects::CreateRectangle("rectangle5", glm::vec3(1050, 610, 0), 200, 50, glm::vec3(0, 0.2, 0), false);
    AddMeshToList(rectangle5);
    Mesh* rectangle6 = myObjects::CreateRectangle("rectangle6", glm::vec3(1050, 611, 0), 10, 49, glm::vec3(0, 0.2, 0), true);
    AddMeshToList(rectangle6);

}


void Tema1::FrameStart()
{
    // Clears the color buffer (using the previously set color) and depth buffer
    glClearColor(0.3, 0.6, 1, 1);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glm::ivec2 resolution = window->GetResolution();
    // Sets the screen area where to draw
    glViewport(0, 0, resolution.x, resolution.y);
}


void Tema1::Update(float deltaTimeSeconds)
{
    
    glm::ivec2 resolution = window->GetResolution();
    modelMatrix = glm::mat3(1);
    
    time += deltaTimeSeconds;
    
    level->RenderText("Level " + to_string(lvl), 10.0f, 10.0f, 1.0f, glm::vec3(1, 1, 1));
    //scor
    RenderMesh2D(meshes["rectangle5"], shaders["VertexColor"], modelMatrix);
    modelMatrix *= transformari::Translate(1050, 611);
    modelMatrix *= transformari::Scale(score, 1);
    modelMatrix *= transformari::Translate(-1050, -611);
    RenderMesh2D(meshes["rectangle6"], shaders["VertexColor"], modelMatrix);

    modelMatrix = glm::mat3(1);
    RenderMesh2D(meshes["rectangle1"], shaders["VertexColor"], modelMatrix);
    if (lives >= 1) {
        RenderMesh2D(meshes["circle4"], shaders["VertexColor"], modelMatrix);
    }
    if (lives >= 2) {
        RenderMesh2D(meshes["circle5"], shaders["VertexColor"], modelMatrix);
    }
    if (lives == 3) {
        RenderMesh2D(meshes["circle6"], shaders["VertexColor"], modelMatrix);
    }

    if (bullets >= 1) {
        RenderMesh2D(meshes["rectangle2"], shaders["VertexColor"], modelMatrix);
    }
    if (bullets >= 2) {
        RenderMesh2D(meshes["rectangle3"], shaders["VertexColor"], modelMatrix);
    }
    if (bullets == 3) {
        RenderMesh2D(meshes["rectangle4"], shaders["VertexColor"], modelMatrix);
    }

    modelMatrix *= transformari::Translate(translateX, translateY);
    modelMatrix *= transformari::Translate(160, 240);
    modelMatrix *= transformari::Rotate(alfa);
    modelMatrix *= transformari::Translate(-160, -240);
    RenderMesh2D(meshes["circle3"], shaders["VertexColor"], modelMatrix);
    RenderMesh2D(meshes["circle2"], shaders["VertexColor"], modelMatrix);
    RenderMesh2D(meshes["circle1"], shaders["VertexColor"], modelMatrix);

    RenderMesh2D(meshes["triangle1"], shaders["VertexColor"], modelMatrix);


    angularStep += deltaTimeSeconds / 1.5f;
    RenderMesh2D(meshes["triangle2"], shaders["VertexColor"], modelMatrix);
    angularStep2 -= deltaTimeSeconds / 1.5f;
    if (angularStep >= 0.445) {
        angularStep = -0.3;
    }
    if (angularStep2 <= -0.445) {
        angularStep2 = 0.3;
    }

    modelMatrix2 = glm::mat3(1);
    modelMatrix2 *= transformari::Translate(translateX, translateY);
 
    modelMatrix2 *= transformari::Translate(160, 240);
    modelMatrix2 *= transformari::Rotate(alfa);
    modelMatrix2 *= transformari::Translate(-160, -240);



    modelMatrix2 *= transformari::Translate(105, 220);
    modelMatrix2 *= transformari::Rotate(angularStep2);
    modelMatrix2 *= transformari::Translate(-105, -220);
    RenderMesh2D(meshes["triangle3"], shaders["VertexColor"], modelMatrix2);


    modelMatrix *= transformari::Translate(105, 280);
    modelMatrix *= transformari::Rotate(angularStep);
    modelMatrix *= transformari::Translate(-105, -280);
    RenderMesh2D(meshes["triangle4"], shaders["VertexColor"], modelMatrix);

    
    if (lives == 0) {
        gameOver = true;
    }
    
    if (score >= 20) {
        gameWon = true;
    }

    if (gameOver) {
        std::string gata = "GAME OVER :( ";
        std::string again = "Press space to start again";
        float xPos = 300.0f;
        float yPos = 200.0f;
        str1->RenderText(gata, 300.0f, 200.0f, 1.0f, glm::vec3(1, 1, 1));
        str2->RenderText(again, 250.0f, 310.0f, 1.0f, glm::vec3(1, 1, 1));
    }

    if (gameWon) {
        modelMatrix = glm::mat3(1);
        std::string gata = "YOU WON :) ";
        std::string again = "Press space to start again";
        float xPos = 300.0f;
        float yPos = 200.0f;
        str1->RenderText(gata, 300.0f, 200.0f, 1.0f, glm::vec3(1, 1, 1));
        str2->RenderText(again, 250.0f, 310.0f, 1.0f, glm::vec3(1, 1, 1));
    }

    
    if (rataMoarta == false && time < 6) {
        if (movementX) {
            translateX += deltaTimeSeconds * speed;

            // coliziunea cu peretele din dreapta
            if (translateX >= resolution.x - 150) {
                movementX = false;
                alfa += movementY ? pi - 2 * alfac : -pi + 2 * alfac;
            }
        }
        else {
            translateX -= deltaTimeSeconds * speed;

            // coliziunea cu peretele din stanga
            if (translateX <= -50) {
                movementX = true;
                alfa += movementY ? -pi + 2 * alfac : pi - 2 * alfac;
            }
        }

        if (movementY) {
            translateY += deltaTimeSeconds * speed;

            // coliziunea cu peretele de sus
            if (translateY >= resolution.y - 250) {
                movementY = false;

                alfa += movementX ? -2 * alfac : 2 * alfac;
            }
        }
        else {
            translateY -= deltaTimeSeconds * speed;

            // coliziunea cu peretele de jos
            if (translateY <= 0) {
                movementY = true;

                alfa += movementX ? 2 * alfac : -2 * alfac;
            }
        }


        while (alfa < 0) {
            alfa += 2 * pi;
        }
        while (alfa > 2 * pi) {
            alfa -= 2 * pi;
        }
    }
    //rata omorata
    else if (rataMoarta == true ) {
        translateY -= deltaTimeSeconds * speed;
        angularStep = 0;
        angularStep2 = 0;
        alfa = 3 * pi / 2;

    }
    //rata evadata
    else if (rataMoarta == false && time >= 6) {
        translateY += deltaTimeSeconds * speed;
        angularStep = 0;
        angularStep2 = 0;
        alfa = pi / 2;
    }
    
    // rata evadata
    if (translateY > resolution.y && rataMoarta == false) {
        lives--;
    }

    // aparitia unei noi rate
    if (translateY < -200 || translateY > resolution.y || gameOver || score >= 20) {
        rataMoarta = false;
        rateAparute++;
        translateX = (rand() % 1000 + 100);
        time = 0;
       
        angularStep = -0.3;
        angularStep2 = 0.3;
        aux = (float)((rand() % 130 + 10) / (float)100);
        
        alfa = aux;
        alfac = aux;
       
        movementX = true;
        movementY = true;
        bullets = 3;
        if (rateAparute % 5 == 0 && rateAparute > 0 && gameOver!=true) {
            speed += 100;
            if (lvl != 5) {
                lvl++;
            }
        }
    }

    // resetarea pozitionarii pentru rata nou aparuta
    if (translateY > resolution.y || gameOver || score >= 20) {
        translateY = -200;
    }
    

    //background
    /*modelMatrix = glm::mat3(1);
    modelMatrix *= transformari::Translate(650, 500);
    modelMatrix *= transformari::Scale(650, 600);
    //RenderMesh2D(meshes["background"], shaders["Simple"], modelMatrix);*/
    
}


void Tema1::FrameEnd()
{
}


/*
 *  These are callback functions. To find more about callbacks and
 *  how they behave, see `input_controller.h`.
 */


void Tema1::OnInputUpdate(float deltaTime, int mods)
{

}


void Tema1::OnKeyPress(int key, int mods)
{
    // restartarea jocului
    if (key == GLFW_KEY_SPACE) {
        score = 0;
        speed = 250;
        rateAparute = 0;
        lives = 3;
        gameOver = false;
        gameWon = false;
        lvl = 0;
    }
}


void Tema1::OnKeyRelease(int key, int mods)
{
    // Add key release event
}


void Tema1::OnMouseMove(int mouseX, int mouseY, int deltaX, int deltaY)
{
    // Add mouse move event
}


void Tema1::OnMouseBtnPress(int mouseX, int mouseY, int button, int mods)
{
    // Add mouse button press event 
    glm::ivec2 resolution = window->GetResolution();
    
    
    float x1 = mouseX - translateX - 160;
    float y1 = resolution.y - mouseY - translateY - 240;

    float x2 = x1 * cos(-alfa) - y1 * sin(-alfa) + 160;
    float y2 = x1 * sin(-alfa) + y1 * cos(-alfa) + 240;

    if (IS_BIT_SET(button, GLFW_MOUSE_BUTTON_LEFT)) {
        if ((x2 <= cornerXmax && x2 >= cornerXmin && y2 <= cornerYmax && y2 >= cornerYmin) && (rataMoarta == false) && (time < 6)) {
            rataMoarta = true;
            score++;  
        }
        bullets--;
    }

    
   // rata ratata
    if (bullets == 0 && rataMoarta == false) {
        time = 6;
        bullets = 3;
    }
   
    

}


void Tema1::OnMouseBtnRelease(int mouseX, int mouseY, int button, int mods)
{
    // Add mouse button release event
}


void Tema1::OnMouseScroll(int mouseX, int mouseY, int offsetX, int offsetY)
{
}


void Tema1::OnWindowResize(int width, int height)
{
}
