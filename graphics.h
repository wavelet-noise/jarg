#ifndef GRAPHICS_H
#define GRAPHICS_H

#include <QGLFunctions>
#include <QOpenGLShaderProgram>
#include <QOpenGLFunctions_2_1>
#include <QtOpenGL>
#include "jtexture.h"

#define PROGRAM_VERTEX_ATTRIBUTE 0
#define PROGRAM_TEXCOORD_ATTRIBUTE 1
#define PROGRAM_COLOR_ATTRIBUTE 2

typedef QOpenGLFunctions_2_1 JGraphics;
typedef QVector2D vec2;
typedef QVector3D vec3;
typedef QVector4D vec4;
typedef QColor col4;
#define STRINGIFY(x) #x
#define STRINGIFYMACRO(y) STRINGIFY(y)
#define INCLUDIFY(x) <##x##>
#define INCLUDIFYMACRO(y) INCLUDIFY(y)

inline void loadShader(char *name_ver, char *name_frag, QOpenGLShaderProgram *program)
{
    if(program->addShaderFromSourceFile(QOpenGLShader::Vertex, name_ver))
        qDebug() << name_ver << "OK";
    if(program->addShaderFromSourceFile(QOpenGLShader::Fragment, name_frag))
        qDebug() << name_frag << "OK";
    if(program->link())
        qDebug() << "link OK";
}

class abstract_engine
{
public:
    virtual void drawLine(vec2 start, vec2 end, col4 color) = 0;
    virtual void drawQuad(vec2 loc, vec2 size, const Texture &tex) = 0;
    virtual void drawQuadAtlas(vec2 loc, vec2 size, QString tex) = 0;
    virtual void drawRect(vec2 loc, vec2 size, col4 col) = 0;
};


#endif // GRAPHICS_H
