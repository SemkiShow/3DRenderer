#include "Constants.h"
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
        double* operator+(Vector3* other);
        double* operator-(Vector3* other);
        Vector3& operator+=(Vector3* other);
        Vector3& operator-=(Vector3* other);
};

Vector3& ValueToVector3(double* value);

class Object3D
{
    public:
        Object3D(Vector3* _pos, Vector3* _rot, Vector3* _scl);
        Vector3* position;
        Vector3* rotation;
        Vector3* scale;
        std::vector<Vector3> vertices;
        std::vector<int[2]> edges;
        void CreateCube();
};
