#include "Render.hpp"
#include "Vectors.hpp"

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
