#ifndef GLPRIMITIVE_H
#define GLPRIMITIVE_H

class Material;
class Matrix4f;
class Vector3f;

//Draws the primitives using opengl commands.
namespace GLPrimitive
{
    void sphere(float r, Material *mat, Matrix4f *t);
    void box(float lx, float ly, float lz, Material *mat, Matrix4f *t);
    void cylinder(float r, float l, Material *mat, Matrix4f *t);
    void capsule(float r, float l, Material *mat, Matrix4f *t);

    void wire_sphere(float r, Material *mat, Matrix4f *t);
    void wire_box(float lx, float ly, float lz, Material *mat, Matrix4f *t);
    void wire_cylinder(float r, float l, Material *mat, Matrix4f *t);
    void wire_capsule(float r, float l, Material *mat, Matrix4f *t);

    //future implementation
    //void triMesh();
    //void convexHull();

    //not tied to any object
    //part of the static world
    //void plane(float a, float b, float c, float d);

    void plane(float s, Material *mat, Matrix4f *t);
    void floor(float s, Material *mat);
    void circle(float r, Material *mat, Matrix4f *t);
    void vector( Vector3f vector, Vector3f pos, Material *mat);

    //Billboard
    void bb_circle(float r, Material *mat);

    //don't represent a solid object
    //start at the object center and go to z direction
    void ray(float length);
}

#endif // GLPRIMITIVE_H
