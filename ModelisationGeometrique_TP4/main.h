#pragma once

#include "GL/glew.h"
#include "GL/glut.h"    
#include <stdio.h>      
#include <stdlib.h>     
#include <math.h>
#include "MeshWriter.h"

#define WIDTH  800
#define HEIGHT 600

#define RED   0
#define GREEN 0
#define BLUE  0
#define ALPHA 1
#define PI 3.14159

#define KEY_ESC 27

// Set lighting intensity and color
GLfloat qaAmbientLight[] = { 0.1, 0.1, 0.1, 1.0 };
GLfloat qaDiffuseLight[] = { 1.0, 1.0, 1.0, 1.0 };
GLfloat qaSpecularLight[] = { 1.0, 1.0, 1.0, 1.0 };
GLfloat emitLight[] = { 0.9, 0.9, 0.9, 0.01 };
GLfloat Noemit[] = { 0.0, 0.0, 0.0, 1.0 };

// Light source position
GLfloat qaLightPosition[] = { 0, 0, 0, 1 }; // Positional Light
GLfloat qaLightDirection[] = { 10, 10, 10, 0 }; // Directional Light

Mesh mesh;
int num_mesh = 0;
int mode_rendu;
int last_x, last_y;
double dist;
float x_rot, y_rot, z_rot;
bool look = false;
bool mode_texture, mode_fill;
GLuint *buffers;

void init_scene();
void render_scene();
GLvoid initGL();
GLvoid window_display();
GLvoid window_reshape(GLsizei width, GLsizei height);
GLvoid window_key(unsigned char key, int x, int y);
GLvoid window_mouse_click(int button, int state, int x, int y);
GLvoid window_mouse(int x, int y);
GLvoid window_idle();
void rotateBy(int x, int y, int z);
void changeMesh();
void traceMaillage();