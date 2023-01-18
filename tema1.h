#pragma once

#include "components/simple_scene.h"
#include "components/text_renderer.h"


namespace m1
{
    class Tema1 : public gfxc::SimpleScene
    {
    public:
        Tema1();
        ~Tema1();

        void Init() override;

    private:
        void FrameStart() override;
        void Update(float deltaTimeSeconds) override;
        void FrameEnd() override;
        void Display();
       
        void OnInputUpdate(float deltaTime, int mods) override;
        void OnKeyPress(int key, int mods) override;
        void OnKeyRelease(int key, int mods) override;
        void OnMouseMove(int mouseX, int mouseY, int deltaX, int deltaY) override;
        void OnMouseBtnPress(int mouseX, int mouseY, int button, int mods) override;
        void OnMouseBtnRelease(int mouseX, int mouseY, int button, int mods) override;
        void OnMouseScroll(int mouseX, int mouseY, int offsetX, int offsetY) override;
        void OnWindowResize(int width, int height) override;

    protected:
        float cx, cy;
        glm::mat3 modelMatrix;
        glm::mat3 modelMatrix2;
        float translateX, translateY;
        float scaleX, scaleY;
        float angularStep;
        float angularStep2;
        float alfa;
        float alfac;
        float pi = 3.1415926f;
        bool movementX;
        int speed;
        bool movementY;
        int cornerXmin = 0;
        int cornerYmin = 190;
        int cornerXmax = 220;
        int cornerYmax = 290;
        int bullets;
        int lives;

        bool rataMoarta = false;
        float time = 0;
        float aux;
        int score;
        int rateAparute;
        bool gameOver;
        bool gameWon;
        int lvl;
        gfxc::TextRenderer* str1;
        gfxc::TextRenderer* str2;
        gfxc::TextRenderer* level;
      
        // TODO(student): If you need any other class variables, define them here.

    };
}   // namespace m1
#pragma once
