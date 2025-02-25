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

double* Vector3::operator+(Vector3* other)
{
    static double output[3] = {value[0] + other->value[0], value[1] + other->value[1], value[2] + other->value[2]};
    return output;
}

double* Vector3::operator-(Vector3* other)
{
    static double output[3] = {value[0] - other->value[0], value[1] - other->value[1], value[2] - other->value[2]};
    return output;
}

Vector3& Vector3::operator+=(Vector3* other)
{
    if (this != other)
    {
        value[0] += other->value[0];
        value[1] += other->value[1];
        value[2] += other->value[2];
    }
    return *this;
}

Vector3& Vector3::operator-=(Vector3* other)
{
    if (this != other)
    {
        value[0] += other->value[0];
        value[1] += other->value[1];
        value[2] += other->value[2];
    }
    return *this;
}

Vector3& ValueToVector3(double* value)
{
    Vector3 output(0, 0, 0);
    output.value[0] = value[0];
    output.value[1] = value[1];
    output.value[2] = value[2];
    return output;
}

Object3D::Object3D(Vector3* _pos, Vector3* _rot, Vector3* _scl)
{
    position = _pos;
    rotation = _rot;
    scale = _scl;
}

void Object3D::CreateCube()
{
    vertices.clear();
    edges.clear();
    Vector3 tmpVector(0, 0, 0);

    // Starting point
    tmpVector = *position;
    vertices.push_back(tmpVector);

    // X
    tmpVector.value[0] += scale->value[0];
    vertices.push_back(tmpVector);

    // XY
    tmpVector.value[1] += scale->value[1];
    vertices.push_back(tmpVector);

    // XYZ
    tmpVector.value[2] += scale->value[1];
    vertices.push_back(tmpVector);

    // Y
    tmpVector = *position;
    tmpVector.value[1] += scale->value[1];
    vertices.push_back(tmpVector);

    // YZ
    tmpVector.value[2] += scale->value[2];
    vertices.push_back(tmpVector);
    
    // XZ
    tmpVector = *position;
    tmpVector.value[0] += scale->value[0];
    tmpVector.value[2] += scale->value[2];
    vertices.push_back(tmpVector);

    // Z
    tmpVector = *position;
    tmpVector.value[2] += scale->value[2];
    vertices.push_back(tmpVector);

}
