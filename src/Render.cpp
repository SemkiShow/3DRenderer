#include "Render.hpp"

Vector3::Vector3(double x, double y, double z)
{
    value[0] = x;
    value[1] = y;
    value[2] = z;    
}

double* Vector3::GetValue()
{
    return value;
}

void Vector3::SetValue(double* input)
{
    value[0] = input[0];
    value[1] = input[1];
    value[2] = input[2];
}

void Vector3::SetValue(double x, double y, double z)
{
    value[0] = x;
    value[1] = y;
    value[2] = z;    
}

Vector3& Vector3::operator=(Vector3& other)
{
    if (this != &other)
    {
        value[0] = other.value[0];
        value[1] = other.value[1];
        value[2] = other.value[2];
    }
    return *this;
}

Vector3& Vector3::operator=(double* other)
{
    if (this->value != other)
    {
        value[0] = other[0];
        value[1] = other[1];
        value[2] = other[2];
    }
    return *this;
}

double* Vector3::operator+(Vector3& other)
{
    static double output[3] = {value[0] + other.value[0], value[1] + other.value[1], value[2] + other.value[2]};
    return output;
}

double* Vector3::operator-(Vector3& other)
{
    static double output[3] = {value[0] - other.value[0], value[1] - other.value[1], value[2] - other.value[2]};
    return output;
}

Vector3& Vector3::operator+=(Vector3& other)
{
    if (this != &other)
    {
        value[0] += other.value[0];
        value[1] += other.value[1];
        value[2] += other.value[2];
    }
    return *this;
}

Vector3& Vector3::operator-=(Vector3& other)
{
    if (this != &other)
    {
        value[0] += other.value[0];
        value[1] += other.value[1];
        value[2] += other.value[2];
    }
    return *this;
}

Object3D::Object3D(double positionX, double positionY, double positionZ, double rotationX, double rotationY, double rotationZ, double scaleX, double scaleY, double scaleZ)
{
    position.value[0] = positionX;
    position.value[1] = positionY;
    position.value[2] = positionZ;
    rotation.value[0] = rotationX;
    rotation.value[1] = rotationY;
    rotation.value[2] = rotationZ;
    scale.value[0] = scaleX;
    scale.value[1] = scaleY;
    scale.value[2] = scaleZ;
}

// void Object3D::CreateCube()
// {
//     vertices.push_back(position);
// }
