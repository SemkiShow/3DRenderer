#include "UI.hpp"
#include "Render.hpp"

Settings settings;

int main()
{
    // Non-SFML init
    Restart();
    srand(time(0));
    settings.Load("settings.txt");

    sf::RenderWindow window(sf::VideoMode({windowSize[0], windowSize[1]}), "3DRenderer");
    InitUI(&window);

    // Render init
    Vector3 vectorOne(1, 1, 1);
    Vector3 vectorTwo(2, 3, 4);
    Vector3 vectorThree(0, 0, 0);
  
    Object3D cube(new Vector3(0, 0, 0), new Vector3(0, 0, 0), new Vector3(1, 1, 1));
    
    while (window.isOpen())
    {
        DrawUI(&window);
        cube.CreateCube();
        // vectorThree = vectorOne + vectorTwo;
        // std::cout << vectorThree.value[0] << ", " << vectorThree.value[1] << ", " << vectorThree.value[2] << '\n';
    }
    
    settings.Save("settings.txt");
    ImGui::SFML::Shutdown();
}
