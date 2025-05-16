#include "Settings.hpp"

bool verticalSync = true;

void Settings::Save(std::string fileName)
{
    // Read the file
    std::fstream settingsFile;
    settingsFile.open(fileName, std::ios::out);
    settingsFile << "vsync=" << (verticalSync ? "true" : "false") << '\n';
    settingsFile.close();
}

void Settings::Load(std::string fileName)
{
    // Read the file
    std::fstream settingsFile;
    settingsFile.open(fileName, std::ios::in);
    std::vector<std::string> settingsList;
    std::string buf = "";
    while (std::getline(settingsFile, buf))
        settingsList.push_back(buf);
    settingsFile.close();

    // Process the file
    verticalSync = settingsList[0].substr(6) == "true" ? true : false;
}
