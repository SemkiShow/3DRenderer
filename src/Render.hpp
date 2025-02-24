#include <iostream>
#include <vector>

class Vector3
{
    public:
        double value[3] = {0, 0, 0};
        Vector3(double x, double y, double z);
        double* GetValue();
        void SetValue(double* input);
        void SetValue(double x, double y, double z);
        Vector3& operator=(Vector3& other);
        Vector3& operator=(double* other);
        double* operator+(Vector3& other);
        double* operator-(Vector3& other);
        Vector3& operator+=(Vector3& other);
        Vector3& operator-=(Vector3& other);
};

class Object3D
{
    public:
        Object3D(double positionX, double positionY, double positionZ, double rotationX, double rotationY, double rotationZ, double scaleX, double scaleY, double scaleZ);
        std::vector<Vector3> vertices;
        std::vector<int[2]> edges;
        Vector3 position;
        Vector3 rotation;
        Vector3 scale;
        void CreateCube();
};
