#include <string>
#include <vector>
#include <fstream>

extern bool verticalSync;

class Settings
{
    public:
        void Save(std::string fileName);
        void Load(std::string fileName);
};
