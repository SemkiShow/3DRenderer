#include "imgui-SFML.h"
#include "UI.hpp"
#include "Render.hpp"
#include "Settings.hpp"

Settings settings;

int main()
{
    // Non-SFML init
    Restart();
    srand(time(0));
    settings.Load("settings.txt");

    sf::RenderWindow window(sf::VideoMode({windowSize[0], windowSize[1] + menuOffset}), "3DRenderer");
    InitUI(&window);

    // Render init
    Object3D cube(new Vector3(0, 0, 0), new Vector3(0, 0, 0), new Vector3(1, 1, 1));
    cube.CreateCube();
    
    while (window.isOpen())
    {
        DrawUI(&window);
    }
    
    settings.Save("settings.txt");
    ImGui::SFML::Shutdown();
}
