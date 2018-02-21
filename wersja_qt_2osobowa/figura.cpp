#include "figura.h"

figura::figura(float x, float y, kolor k)
    : rX(0), rY(0), rZ(0), widoczny(true), textura(0)
{
    _kolor = k;
    UstawGeometrie(x, y, 1, 1, 1, 1);
}

void figura::set_position(float x, float y)
{
    m_x = x;
    m_y = y;
}

void figura::move(float dx, float dy)
{
    m_x += dx;
    m_y += dy;
}

void figura::change_color(kolor k)
{
    _kolor = k;
}

void figura::rotate(float rotX, float rotY, float rotZ)
{
    rX += rotX;
    rY += rotY;
    rZ += rotZ;
}

void figura::set_rotate(float rotX, float rotY, float rotZ)
{
    rX = rotX;
    rY = rotY;
    rZ = rotZ;

}

int figura::LoadGLTextures(const char * file_name, int filter)
{

    /* load an image file directly as a new OpenGL texture */

    textura = SOIL_load_OGL_texture
        (
            file_name,
            SOIL_LOAD_AUTO,
            SOIL_CREATE_NEW_ID,
            SOIL_FLAG_INVERT_Y | SOIL_FLAG_MIPMAPS | SOIL_FLAG_POWER_OF_TWO
            );

    if (textura == 0)
        return false;
    int minfil = 0;
    int magfil = 0;

    switch (filter)
    {
    case 0:
    {
        magfil = GL_NEAREST;
        minfil = GL_NEAREST;
    }
    case 1:
    {
        magfil = GL_LINEAR;
        minfil = GL_LINEAR;
    }
    case 2:
    {
        magfil = GL_NEAREST_MIPMAP_NEAREST;
        minfil = GL_NEAREST_MIPMAP_NEAREST;
    }
    case 3:
    {
        magfil = GL_NEAREST_MIPMAP_LINEAR;
        minfil = GL_NEAREST_MIPMAP_LINEAR;
    }
    case 4:
    {
        magfil = GL_LINEAR_MIPMAP_NEAREST;
        minfil = GL_LINEAR_MIPMAP_NEAREST;
    }
    case 5:
    {
        magfil = GL_LINEAR_MIPMAP_LINEAR;
        minfil = GL_LINEAR_MIPMAP_LINEAR;
    }
    default:
    {
        magfil = GL_LINEAR;
        minfil = GL_LINEAR;
    }
    }
    // Typical Texture Generation Using Data From The Bitmap
    glBindTexture(GL_TEXTURE_2D, textura);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR_MIPMAP_LINEAR);
    float color[] = { 1,0,0,1 };
    glTexParameterfv(GL_TEXTURE_2D, GL_TEXTURE_BORDER_COLOR, color);

    return true;
}


int LoadGLTexture(GLuint &textura, const char *file_name)                              // Load Bitmaps And Convert To Textures
{
    /* load an image file directly as a new OpenGL texture */
    textura = SOIL_load_OGL_texture
        (
            file_name,
            SOIL_LOAD_AUTO,
            SOIL_CREATE_NEW_ID,
            SOIL_FLAG_INVERT_Y
            );

    if (textura == 0)
        return false;


    // Typical Texture Generation Using Data From The Bitmap
    glBindTexture(GL_TEXTURE_2D, textura);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

    return true;                                        // Return Success
}

