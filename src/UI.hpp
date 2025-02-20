#include "imgui.h"
#include "imgui-SFML.h"
#include "Render.hpp"

#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include <vector>
#include <random>
#include <ctime>
#include <fstream>
#include <algorithm>

extern int menuOffset;
extern unsigned int windowWidth;
extern unsigned int windowHeight;
extern unsigned int windowSize[2];
extern bool verticalSync;

extern bool isSettings;
extern bool lastVSync;
    
class Settings
{
    public:
        void Save(std::string fileName);
        void Load(std::string fileName);
};

void ShowSettings(bool* isOpen);
void Restart();
void ShowMenuBar();
