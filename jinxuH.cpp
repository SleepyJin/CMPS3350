//Jinxu Han

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cstring>
#include <cmath>
#include <X11/Xlib.h>
#include <X11/keysym.h>
#include <GL/glx.h>
#include "jinxuH.h"
#include "fonts.h"
/*
struct Vec {
    float x, y, z;
};

struct Shape {
    float width, height;
    float radius;
    Vec center;
};

struct Box {
    Shape table[3];
    Shape truck;
    //    Shape circle;
    //    Particle particle[MAX_PARTICLES];
    int n;
    int bubbler;
    int mouse[2];
    Box() {
        n=0;
        bubbler=0;

    }
};



int main()
{
    Box box = new Box;
    object(&box);
}i
i*/
void object(Box *box)
{
    //declare game object
    //Box box;
    //box.n=0;
    //declare a box shape
    for (int i = 0; i < 4; i++) {
        box->table[i].width = 40;
        box->table[i].height = 40;
    }
        //position of the table
         box->table[0].center.x = 190;
         box->table[0].center.y = 200;
	 //table2
         box->table[1].center.x = 390;
         box->table[1].center.y = 200;
	 //table3
         box->table[2].center.x = 190;
         box->table[2].center.y = 100;
	 //table4
         box->table[3].center.x = 390;
         box->table[3].center.y = 100;
    box->truck.width = 170;
    box->truck.height = 7;
    //position of the truck
    box->truck.center.x = 170;
    box->truck.center.y = 366;

}

void drawbox(Box *box)
{
    float w, h;
  //  glClear(GL_COLOR_BUFFER_BIT);
    //Draw shapes...

    //draw table box
    Shape *s;
    for (int i=0; i<4;i++){
       // glColor3ub(249,29,88);
        s = &box->table[i];
        glPushMatrix();
        glTranslatef(s->center.x, s->center.y, s->center.z);
        w = s->width;
        h = s->height;
        glBegin(GL_QUADS);
        glVertex2i(-w,-h);
        glVertex2i(-w, h);
        glVertex2i( w, h);
        glVertex2i( w,-h);
        glEnd();
        glPopMatrix();
    }
    //draw truck box

   // glColor3ub(246,29,29);
    s = &box->truck;
    glPushMatrix();
    glTranslatef(s->center.x, s->center.y, s->center.z);
    w = s->width;
    h = s->height;
    glBegin(GL_QUADS);
    glVertex2i(-w,-h);
    glVertex2i(-w, h);
    glVertex2i( w, h);
    glVertex2i( w,-h);
    glEnd();
    glPopMatrix();


}
