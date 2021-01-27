#pragma once
#include <Windows.h>
#include <gl/glew.h>
#include <gl/GL.h>
#include <gl/GLU.h>
#include <gl/glut.h>

const int width = 640;
const int height = 480;

void drawKinectData();
bool init(int argc, char* argv[]);
void draw();
void execute();