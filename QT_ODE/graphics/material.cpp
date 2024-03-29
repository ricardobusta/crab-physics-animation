#include "material.h"

#include <QtOpenGL>

Material::Material()
{
    for(int i=0;i<4;i++){
        specular[i]=1;
        diffuse[i]=1;
        emission[i]=0;
    }
    shininess[0]=30;
}

void Material::setColor(float component[], int color){
    switch(color){
        case MAT_RED:
            component[0] = 1;
            component[1] = 0;
            component[2] = 0;
            component[3] = 1;
            break;
        case MAT_GREEN:
            component[0] = 0;
            component[1] = 1;
            component[2] = 0;
            component[3] = 1;
            break;
        case MAT_BLUE:
            component[0] = 0;
            component[1] = 0;
            component[2] = 1;
            component[3] = 1;
            break;
        case MAT_YELLOW:
            component[0] = 1;
            component[1] = 1;
            component[2] = 0;
            component[3] = 1;
            break;
        case MAT_CYAN:
            component[0] = 0;
            component[1] = 1;
            component[2] = 1;
            component[3] = 1;
            break;
        case MAT_MAGENTA:
            component[0] = 1;
            component[1] = 0;
            component[2] = 1;
            component[3] = 1;
            break;
        case MAT_WHITE:
            component[0] = 1;
            component[1] = 1;
            component[2] = 1;
            component[3] = 1;
            break;
        case MAT_GRAY_75:
            component[0] = 0.75;
            component[1] = 0.75;
            component[2] = 0.75;
            component[3] = 1;
            break;
        case MAT_GRAY_50:
            component[0] = 0.5;
            component[1] = 0.5;
            component[2] = 0.5;
            component[3] = 1;
            break;
        case MAT_GRAY_25:
            component[0] = 0.25;
            component[1] = 0.25;
            component[2] = 0.25;
            component[3] = 1;
            break;
        case MAT_ORANGE:
            component[0] = 1;
            component[1] = 0.4;
            component[2] = 0;
            component[3] = 1;
            break;
        case MAT_DARK_RED:
            component[0] = 0.5;
            component[1] = 0;
            component[2] = 0;
            component[3] = 1;
            break;
        case MAT_DARK_GREEN:
            component[0] = 0;
            component[1] = 0.5;
            component[2] = 0;
            component[3] = 1;
            break;
        case MAT_DARK_BLUE:
            component[0] = 0;
            component[1] = 0;
            component[2] = 0.5;
            component[3] = 1;
            break;
        case MAT_DARK_YELLOW:
            component[0] = 0.5;
            component[1] = 0.5;
            component[2] = 0;
            component[3] = 1;
            break;
        case MAT_DARK_CYAN:
            component[0] = 0;
            component[1] = 0.5;
            component[2] = 0.5;
            component[3] = 1;
            break;
        case MAT_DARK_MAGENTA:
            component[0] = 0.5;
            component[1] = 0;
            component[2] = 0.5;
            component[3] = 1;
            break;
        case MAT_BLACK:
            component[0] = 0;
            component[1] = 0;
            component[2] = 0;
            component[3] = 1;
            break;
        case MAT_DARK_ORANGE:
            component[0] = 0.5;
            component[1] = 0.2;
            component[2] = 0;
            component[3] = 1;
            break;
        default:
            break;
    }
}

void Material::setDiffuse(int color){
   setColor(diffuse, color);

   diffuse_2[0] = 0.5*diffuse[0];
   diffuse_2[1] = 0.5*diffuse[1];
   diffuse_2[2] = 0.5*diffuse[2];
   diffuse_2[3] = diffuse[3];

   diffuse_inv[0] = 1.0-diffuse[0];
   diffuse_inv[1] = 1.0-diffuse[1];
   diffuse_inv[2] = 1.0-diffuse[2];
//   diffuse_inv[0] = 0;
//   diffuse_inv[1] = 1;
//   diffuse_inv[2] = 0;
   diffuse_inv[3] = diffuse[3];
}

void Material::setSpecular(int color){
    setColor(specular, color);
}

void Material::setEmission(int color){
    setColor(emission, color);
}

void Material::gl(){
    glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, specular);
    glMaterialfv(GL_FRONT_AND_BACK, GL_SHININESS, shininess);
    glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, diffuse);
    glMaterialfv(GL_FRONT_AND_BACK, GL_EMISSION, emission);
}

void Material::glHalf(){
    glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, specular);
    glMaterialfv(GL_FRONT_AND_BACK, GL_SHININESS, shininess);
    glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, diffuse_2);
    glMaterialfv(GL_FRONT_AND_BACK, GL_EMISSION, emission);
}

void Material::glInverse(){
    glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, specular);
    glMaterialfv(GL_FRONT_AND_BACK, GL_SHININESS, shininess);
    glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, diffuse_inv);
    glMaterialfv(GL_FRONT_AND_BACK, GL_EMISSION, emission);
}
