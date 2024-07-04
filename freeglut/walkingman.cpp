#include <windows.h>
#include <stdlib.h>
#include <glut.h>
#include <math.h>
#include <iostream>

#define PI 3.141592653
#define SCREEN_WIDTH 700
#define SCREEN_HEIGHT 700
#define FPS 30
#define RAINSIZE 50

int winWidth = 700, winHeight = 700, counter = 0;
time_t t;
float rotationAngle = 0;

struct drop {
	float x = 400;
	float y = 400;
	float inc = 0.01;
	float radius = 5;
	float scale = 1.0;
	float rotationAngle = 0;
	float rotationInc = 1;
};

drop rain[RAINSIZE];

void initRain() {
	srand((unsigned)time(&t));
	for (int i = 0; i < RAINSIZE; i++) {
		rain[i].x = rand() % winWidth;
		rain[i].y = rand() % winHeight;
		rain[i].inc = 1.5 + (float)(rand() % 100) / 1000.0;
		rain[i].radius = (float)(rand() % 8);
		rain[i].scale = (float)(rand() % 20000) / 1000.0;
		rain[i].rotationAngle = (float)(rand() % 3000) / 1000.0;
		rain[i].rotationInc = (float)(rand() % 100) / 1000.0;
		if ((rand() % 100) > 50) {
			rain[i].rotationInc = -rain[i].rotationInc;
		}
	}
}

void drawParticleShape(int i) {
	glBegin(GL_POINTS);
	glVertex2d(rain[i].x, rain[i].y);
	glEnd();
	glBegin(GL_LINES);
	glVertex2d(rain[i].x, rain[i].y);
	glVertex2d(rain[i].x, rain[i].y + rain[i].radius * 2);
	glEnd();
}

void drawDrop(int i) {
	glColor3f(0.0, 0.0, 2.0);
	glLineWidth(2);
	drawParticleShape(i);
	rain[i].y -= rain[i].inc;
	if (rain[i].y < 0) {
		rain[i].y = winHeight;
	}
}

void drawRain() {
	for (int i = 0; i < RAINSIZE; i++) {
		drawDrop(i);
	}
}

// this is the initialisation function, called once only
void init() {
	glClearColor(0.0, 0.0, 0.0, 0.0); // set what colour you want the background to be
	glMatrixMode(GL_PROJECTION); // set the matrix mode, we will look at this later
	gluOrtho2D(0.0, winWidth, 0.0, winHeight);
}

float elapsedTime = 0, base_time = 0, fps = 0, frames;

void calcFPS() {
	elapsedTime = glutGet(GLUT_ELAPSED_TIME);
	if ((elapsedTime - base_time) > 1000.0) {
		fps = frames * 1000.0 / (elapsedTime - base_time);
		printf("fps: %f", fps);
		base_time = elapsedTime;
		frames = 0;
	}
	frames++;
}

// This is the display function it is called when ever you want to draw something
// all drawing should be called form here
void display_rain() {
	glClear(GL_COLOR_BUFFER_BIT);
	drawRain();
	calcFPS();
	glFlush();
	counter++;
	glutPostRedisplay();
}

// This is the idle function it is called whenever the program is idle
// This has the effect of repeatedly calling the display function
void r_idle() {
	//display();
}



static float cloud1 = -20;
static float cloud2 = -60;

int x = 30;
int y = 50;
int dx = 10;//velocity
int dy = 15;
int walk = 0;
float plane_drift = 0;

void MyTimerFunc(int value);

// create triangle shape
void triangles(int x, int y, int x1, int y1, int x2, int y2) {
	glBegin(GL_TRIANGLES);
	glVertex2i(x, y);
	glVertex2i(x1, y1);
	glVertex2i(x2, y2);
	glEnd();
}

// create rectangle shape
void rectangle(int x, int y, int w, int h) {
	glBegin(GL_POLYGON);
	glVertex2i(x, y);
	glVertex2i(x + w, y);
	glVertex2i(x + w, y + h);
	glVertex2i(x, y + h);
	glEnd();
}


void straight_lines(int x1, int y1, int x2, int y2) {
	glBegin(GL_LINES);
	glVertex2i(x1, y1);
	glVertex2i(x2, y2);
	glEnd();
}

void person(int n, int x, int y, int r) {
	//draw round head
	double inc = 2 * PI / (double)n;
	glBegin(GL_POLYGON);
	for (double theta = 0.0; theta <= 2 * PI; theta += inc) {
		glVertex2i(r * cos(theta) + x, r * sin(theta) + y);
	}
	glEnd();
}

void loveShape(int n, int x, int y, int r) {
	double inc = 2 * PI / (double)n;
	glColor3ub(220, 20, 60);
	glBegin(GL_POLYGON);
	for (double theta = 0.0; theta <= 2 * PI; theta += inc) {
		glVertex2i(r * 16 * pow(sin(theta), 3) + x, r * (13 * cos(theta) - 5 * cos(2 * theta) - 2 * cos(3 * theta) - cos(4 * theta)) + y);
	}
	glEnd();
}

void semicircle(int n, int x, int y, int r) {
	double inc2 = PI / (double)n;
	glBegin(GL_POLYGON);
	for (double theta = 0.0; theta <= PI; theta += inc2) {
		glVertex2i(r * cos(theta) + x, r * sin(theta) + y);
	}
	glEnd();
}

// create cloud move
void cloud_move() {
	cloud1 += .1;
	if (cloud1 > 700) {
		cloud1 = -20;
	}
	glutPostRedisplay();
	cloud2 += .1;
	if (cloud2 > 1000) {
		cloud2 = -20;
	}
}

void moving_cloud() {
	glColor3ub(255, 255, 255);
	cloud_move();
	glPushMatrix();
	glTranslatef(cloud1, 1, 0);

	//1st cloud 
	//top
	person(20, 95, 600, 45);
	//bottom
	person(20, 80, 570, 40);
	//left
	person(20, 50, 580, 30);
	//right
	person(20, 130, 580, 35);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(cloud2, -2, 0);
	//2nd cloud
	//top
	person(20, 490, 450, 45);
	//bottom
	person(20, 470, 420, 38);
	//left
	person(20, 440, 445, 30);
	//right
	person(20, 530, 450, 35);
	glPopMatrix();

}

void plane(int x, int y, int w) {
	int h = 0.75 * w;
	glBegin(GL_POLYGON);
	glVertex2i(x - w / 2, y + h);
	glVertex2i(x + w + w, y + h);
	glVertex2i(x + w, y + h + h / 2);
	glVertex2i(x, y + h + h / 2);
	glEnd();

}

void triangle() {
	glColor3ub(255, 255, 255);
	glBegin(GL_TRIANGLE_FAN);
	glVertex2i(120, 250);
	glVertex2i(180, 250);
	glVertex2i(180, 200);
	glEnd();
}

void triangle1() {
	glColor3ub(255, 255, 255);
	glBegin(GL_TRIANGLE_FAN);
	glVertex2i(550, 250);
	glVertex2i(600, 250);
	glVertex2i(530, 200);
	glEnd();
}

void triangle2() {
	glColor3ub(0, 0, 0);
	glBegin(GL_TRIANGLES);
	glVertex2i(100, 350);
	glVertex2i(200, 400);
	glVertex2i(300, 350);
	glEnd();
}

void land() {
	glColor3ub(204, 102, 0);
	glBegin(GL_POLYGON);
	glVertex2i(0, 350);
	glVertex2i(700, 335);
	glVertex2i(700, 0);
	glVertex2i(0, 0);
	glEnd();
}

void land2() {
	glColor3ub(153, 76, 0);
	glBegin(GL_TRIANGLES);
	glVertex2i(0, 240);
	glVertex2i(500, 0);
	glVertex2i(0, 0);
	glEnd();
}

void tree_element() {
	//tree bark color
	glColor3ub(139, 69, 19);
	glBegin(GL_POLYGON);
	glVertex2i(460, 320);
	glVertex2i(475, 200);
	glVertex2i(490, 170);
	glVertex2i(460, 170);
	glEnd();
}

void tree_elements() {
	//tree bark color
	glColor3ub(139, 69, 19);
	glBegin(GL_POLYGON);
	glVertex2i(350, 320);
	glVertex2i(335, 200);
	glVertex2i(350, 170);
	glVertex2i(320, 170);
	glEnd();
}

void roof() {
	glColor3ub(0, 51, 102);
	glBegin(GL_POLYGON);
	glVertex2i(200, 400);
	glVertex2i(400, 400);
	glVertex2i(500, 350);
	glVertex2i(300, 350);
	glEnd();
}

void frontwall() {
	glColor3ub(255, 128, 0);
	glBegin(GL_POLYGON);
	glVertex2i(100, 350);
	glVertex2i(300, 350);
	glVertex2i(300, 120);
	glVertex2i(100, 120);
	glEnd();
}

void rightwall() {
	glColor3ub(255, 255, 255);
	glBegin(GL_POLYGON);
	glVertex2i(300, 350);
	glVertex2i(500, 350);
	glVertex2i(500, 120);
	glVertex2i(300, 120);
	glEnd();
}

void door() {
	glColor3ub(255, 255, 255);
	glBegin(GL_POLYGON);
	glVertex2i(150, 240);
	glVertex2i(250, 240);
	glVertex2i(250, 120);
	glVertex2i(150, 120);
	glEnd();
}

void door_line() {
	glColor3ub(0, 0, 0);
	glBegin(GL_LINES);
	glVertex2i(200, 240);
	glVertex2i(200, 120);
	glEnd();
}

void window1() {
	glColor3ub(255, 128, 0);
	glBegin(GL_POLYGON);
	glVertex2i(310, 300);
	glVertex2i(390, 300);
	glVertex2i(390, 250);
	glVertex2i(310, 250);
	glEnd();
}

void window1_Line() {
	glColor3f(0, 0, 0);
	glLineWidth(5);
	glBegin(GL_LINES);
	glVertex2i(350, 300);
	glVertex2i(350, 250);
	glVertex2i(310, 275);
	glVertex2i(390, 275);
	glEnd();
}

void window2() {
	glColor3ub(255, 128, 0);
	glBegin(GL_POLYGON);
	glVertex2i(400, 300);
	glVertex2i(480, 300);
	glVertex2i(480, 250);
	glVertex2i(400, 250);
	glEnd();
}

void window2_Line() {
	glColor3ub(0, 0, 0);
	glBegin(GL_LINES);
	glVertex2i(440, 300);
	glVertex2i(440, 250);
	glVertex2i(400, 275);
	glVertex2i(480, 275);
	glEnd();
}

void talk() {
	glColor3ub(255, 255, 255);//white colour
	person(50, 150, 300, 70);//head
	triangle();
}

void talk1() {
	glColor3ub(255, 255, 255);//white colour
	person(50, 600, 300, 100);//head
	triangle1();
}


//scene 1
void display() {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glColor3ub(135, 206, 250);
	rectangle(0, 400, 700, 300);//background
	glColor3ub(0, 100, 0);
	rectangle(0, 0, 700, 400);

	//tree
	glColor3ub(139, 69, 19);
	rectangle(300, 260, 50, 200);//tree bark
	glColor3ub(0, 128, 0);
	person(10, 330, 600, 180);//tree leaves

	glColor3ub(255, 255, 255);
	glRasterPos3f(360, 360, 0);
	char text[] = "20 Years Ago.....";

	for (int i = 0; i < strlen(text); i++) {
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, text[i]);
	}
	glRasterPos3f(360, 330, 0);
	char text1[] = "When they were young";
	for (int i = 0; i < strlen(text1); i++) {
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, text1[i]);
	}

	//boy
	glColor3ub(255, 255, 255);//boy colour pink
	person(25, 250, 200, 40);//head
	glLineWidth(10);
	straight_lines(250, 200, 250, 80);//body
	straight_lines(260, 170, 220, 130);//left hand
	straight_lines(220, 130, 230, 120);//left hand down
	straight_lines(250, 160, 280, 130);//right hand
	straight_lines(280, 130, 290, 160);//right hand down
	straight_lines(250, 80, 240, 50);//left foot
	straight_lines(240, 50, 210, 30);//left foot up
	straight_lines(250, 80, 260, 70);//right foot
	straight_lines(260, 70, 250, 30);//right foot

	//girl
	glColor3ub(255, 105, 180);//girl colour pink
	person(25, 420, 200, 40);//head
	straight_lines(420, 200, 420, 80);//body
	straight_lines(430, 170, 390, 130);//left hand
	straight_lines(390, 130, 400, 120);//left hand down
	straight_lines(420, 160, 450, 130);//right hand
	straight_lines(450, 130, 460, 160);//right hand down
	straight_lines(420, 80, 410, 50);//left foot
	straight_lines(410, 50, 380, 30);//left foot up
	straight_lines(420, 80, 430, 70);//right foot
	straight_lines(430, 70, 420, 30);//right foot

	glFlush();
	glutSwapBuffers();
}

//scene1
void display2() {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glColor3ub(135, 206, 250);
	rectangle(0, 400, 700, 300);//background
	glColor3ub(0, 100, 0);
	rectangle(0, 0, 700, 400);

	//tree
	glColor3ub(139, 69, 19);
	rectangle(240, 260, 50, 200);//tree bark
	glColor3ub(0, 128, 0);
	person(10, 270, 600, 180);//tree leaves

	glColor3ub(255, 255, 255);
	glRasterPos3f(360, 360, 0);
	char text[] = "20 Years Ago.....";

	for (int i = 0; i < strlen(text); i++) {
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, text[i]);
	}

	glRasterPos3f(360, 330, 0);
	char text1[] = "When they were young";
	for (int i = 0; i < strlen(text1); i++) {
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, text1[i]);
	}


	//boy
	glColor3ub(255, 255, 255);//boy colour pink
	person(25, 250, 200, 40);//head
	glLineWidth(10);
	straight_lines(250, 200, 250, 80);//body
	straight_lines(250, 170, 250, 130);//left hand
	straight_lines(250, 130, 260, 120);//left hand down
	straight_lines(250, 160, 260, 130);//right hand
	straight_lines(260, 130, 270, 140);//right hand down
	straight_lines(250, 80, 240, 60);//left foot
	straight_lines(240, 60, 220, 70);//left foot up
	straight_lines(250, 80, 270, 60);//right foot
	straight_lines(270, 60, 260, 30);//right foot

	//girl
	glColor3ub(255, 105, 180);//girl colour pink
	person(25, 420, 200, 40);//head
	straight_lines(420, 200, 420, 80);//body
	straight_lines(420, 170, 410, 130);//left hand
	straight_lines(410, 130, 420, 120);//left hand down
	straight_lines(420, 160, 430, 130);//right hand
	straight_lines(430, 130, 450, 140);//right hand down
	straight_lines(420, 80, 410, 60);//left foot
	straight_lines(410, 60, 380, 70);//left foot up
	straight_lines(420, 80, 440, 60);//right foot
	straight_lines(440, 60, 430, 30);//right foot

	glFlush();
	glutSwapBuffers();
}

//scene1
void display3() {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glColor3ub(135, 206, 250);
	rectangle(0, 400, 700, 300);//background
	glColor3ub(0, 100, 0);
	rectangle(0, 0, 700, 400);

	//tree
	glColor3ub(139, 69, 19);
	rectangle(160, 260, 50, 200);//tree bark
	glColor3ub(0, 128, 0);
	person(10, 190, 600, 180);//tree leaves

	talk();
	glColor3ub(255, 255, 255);
	glRasterPos3f(360, 360, 0);
	char text[] = "20 Years Ago.....";

	for (int i = 0; i < strlen(text); i++) {
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, text[i]);
	}
	glRasterPos3f(360, 330, 0);
	char text1[] = "When they were young";
	for (int i = 0; i < strlen(text1); i++) {
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, text1[i]);
	}

	glColor3ub(0, 0, 0);
	glRasterPos3f(110, 290, 0);
	char text2[] = "Hey, wait for me..";
	for (int i = 0; i < strlen(text2); i++) {
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, text2[i]);
	}

	//boy
	glColor3ub(255, 255, 255);//boy colour pink
	person(25, 250, 200, 40);//head
	glLineWidth(10);
	straight_lines(250, 200, 250, 80);//body
	straight_lines(260, 170, 220, 130);//left hand
	straight_lines(220, 130, 230, 120);//left hand down
	straight_lines(250, 160, 280, 130);//right hand
	straight_lines(280, 130, 290, 160);//right hand down
	straight_lines(250, 80, 240, 50);//left foot
	straight_lines(240, 50, 210, 30);//left foot up
	straight_lines(250, 80, 260, 70);//right foot
	straight_lines(260, 70, 250, 30);//right foot

	//girl
	glColor3ub(255, 105, 180);//girl colour pink
	person(25, 420, 200, 40);//head
	straight_lines(420, 200, 420, 80);//body
	straight_lines(430, 170, 390, 130);//left hand
	straight_lines(390, 130, 400, 120);//left hand down
	straight_lines(420, 160, 450, 130);//right hand
	straight_lines(450, 130, 460, 160);//right hand down
	straight_lines(420, 80, 410, 50);//left foot
	straight_lines(410, 50, 380, 30);//left foot up
	straight_lines(420, 80, 430, 70);//right foot
	straight_lines(430, 70, 420, 30);//right foot

	glFlush();
	glutSwapBuffers();
}

//scene 2
void display4() {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glColor3ub(162, 173, 208);
	rectangle(0, 300, 700, 400);//background
	glColor3ub(0, 100, 0);
	rectangle(0, 0, 700, 300);

	//tree
	glColor3ub(139, 69, 19);
	rectangle(280, 230, 150, 700);//tree bark
	glColor3ub(0, 128, 0);
	person(10, 350, 800, 380);//tree leaves

	glColor3ub(255, 255, 102);
	glRasterPos3f(100, 360, 0);
	char text[] = "Unfortunately....";

	for (int i = 0; i < strlen(text); i++) {
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, text[i]);
	}


	//boy
	glColor3ub(255, 255, 255);//boy colour pink
	person(25, 230, 200, 50);//head
	glLineWidth(10);
	straight_lines(230, 200, 230, 0);//body
	straight_lines(230, 150, 250, 100);// hand
	//straight_lines(250, 100, 320, 120);// hand up
	straight_lines(250, 100, 280, 80);// hand up

	//girl
	glColor3ub(255, 105, 180);//girl colour pink
	person(25, 480, 200, 50);//head
	straight_lines(480, 200, 480, 0);//body
	straight_lines(480, 150, 460, 100);// hand
	//straight_lines(460, 100, 390, 120);// hand up
	straight_lines(460, 100, 420, 80);// hand up

	glFlush();
	glutSwapBuffers();
}

//scene2
void display5() {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glColor3ub(162, 173, 208);
	rectangle(0, 300, 700, 400);//background
	glColor3ub(0, 100, 0);
	rectangle(0, 0, 700, 300);

	//tree
	glColor3ub(139, 69, 19);
	rectangle(280, 230, 150, 700);//tree bark
	glColor3ub(0, 128, 0);
	person(10, 350, 800, 380);//tree leaves

	talk1();
	glColor3ub(0, 0, 0);
	glRasterPos3f(510, 320, 0);
	char text2[] = "I want to tell you something.";
	for (int i = 0; i < strlen(text2); i++) {
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, text2[i]);
	}

	glColor3ub(0, 0, 0);
	glRasterPos3f(510, 300, 0);
	char text3[] = "I'll have to follow my parents'";
	for (int i = 0; i < strlen(text3); i++) {
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, text3[i]);
	}

	glColor3ub(0, 0, 0);
	glRasterPos3f(510, 280, 0);
	char text4[] = "and move to another country.";
	for (int i = 0; i < strlen(text4); i++) {
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, text4[i]);
	}

	//boy
	glColor3ub(255, 255, 255);//boy colour pink
	person(25, 230, 200, 50);//head
	glLineWidth(10);
	straight_lines(230, 200, 230, 0);//body
	straight_lines(230, 150, 250, 100);// hand
	//straight_lines(250, 100, 320, 120);// hand up
	straight_lines(250, 100, 280, 80);// hand up

	//girl
	glColor3ub(255, 105, 180);//girl colour pink
	person(25, 480, 200, 50);//head
	straight_lines(480, 200, 480, 0);//body
	straight_lines(480, 150, 460, 100);// hand
	straight_lines(460, 100, 390, 120);// hand up
	//straight_lines(460, 100, 420, 80);// hand up

	glFlush();
	glutSwapBuffers();
}

//scene 3
void display6() {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glColor3ub(162, 162, 208);
	rectangle(0, 400, 700, 300);//background sky
	glColor3ub(0, 100, 0);
	rectangle(0, 0, 700, 400);//background grass
	//tree
	glColor3ub(139, 69, 19);
	rectangle(0, 0, 100, 650);//tree bark
	glColor3ub(0, 128, 0);
	person(10, 10, 650, 300);//tree leaves
	//boy_waving
	glColor3ub(255, 255, 255);//boy colour white
	person(25, 100, 200, 50);//head
	straight_lines(100, 200, 100, 0);//body
	straight_lines(100, 100, 200, 200);//r hand
	straight_lines(100, 100, 30, 10);//l hand
	//girl mother
	glColor3ub(0, 255, 255);//girl mother colour light blue
	person(25, 500, 520, 50);//head
	straight_lines(500, 520, 500, 200);//body
	straight_lines(500, 420, 420, 350);//left hand
	straight_lines(500, 420, 600, 350);//right hand
	straight_lines(500, 200, 420, 150);//left foot
	straight_lines(500, 200, 600, 150);//right foot
	//girl
	glColor3ub(255, 105, 180);//girl colour pink
	person(25, 300, 320, 50);//head
	straight_lines(300, 320, 300, 200);//body
	straight_lines(300, 250, 250, 280);//left hand
	straight_lines(300, 250, 350, 220);//right hand
	straight_lines(300, 200, 260, 150);//left foot
	straight_lines(300, 200, 350, 150);//right foot

	glFlush();
	glutSwapBuffers();
}

void display7() {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glColor3ub(162, 162, 208);
	rectangle(0, 400, 700, 700);//background sky
	glColor3ub(0, 100, 0);
	rectangle(0, 0, 700, 400);//background grass
	//tree
	glColor3ub(139, 69, 19);
	rectangle(0, 0, 100, 650);//tree bark
	glColor3ub(0, 128, 0);
	person(10, 10, 650, 300);//tree leaves
	//boy2ndanimation
	glColor3ub(255, 255, 255);
	person(25, 100, 200, 50);
	straight_lines(100, 200, 100, 0);
	straight_lines(100, 100, 200, 150);
	straight_lines(100, 100, 30, 10);
	glColor3ub(0, 255, 255);
	//mom
	glColor3ub(0, 255, 255);
	person(25, 500, 520, 50);
	straight_lines(500, 520, 500, 200);
	straight_lines(500, 420, 420, 350);
	straight_lines(500, 420, 600, 350);
	straight_lines(500, 200, 420, 150);
	straight_lines(500, 200, 600, 150);
	//girl2nd
	glColor3ub(255, 105, 180);
	person(25, 300, 320, 50);//h
	straight_lines(300, 320, 300, 200);//b
	straight_lines(300, 250, 250, 250);//lh
	straight_lines(300, 250, 350, 220);//rh
	straight_lines(300, 200, 260, 150);//rf
	straight_lines(300, 200, 350, 150);//lf
	glFlush();
	glutSwapBuffers();
}

void display8() {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glColor3ub(162, 162, 208);
	rectangle(0, 400, 700, 700);
	glColor3ub(0, 100, 0);
	rectangle(0, 0, 700, 400);
	//tree
	glColor3ub(139, 69, 19);
	rectangle(0, 0, 100, 650);//tree bark
	glColor3ub(0, 128, 0);
	person(10, 10, 650, 300);//tree leaves
	//walking scene
	if (walk < 500) {
		//boy2nd
		glColor3ub(255, 255, 255);
		person(25, 100, 200, 50);
		straight_lines(100, 200, 100, 0);
		straight_lines(100, 100, 200, 150);
		straight_lines(100, 100, 30, 10);
		glColor3ub(0, 255, 255);
		//mom
		glColor3ub(0, 255, 255);
		person(25, 500 + walk, 520, 50);
		straight_lines(500 + walk, 520, 500 + walk, 200);
		straight_lines(500 + walk, 420, 420 + walk, 350);
		straight_lines(500 + walk, 420, 600 + walk, 350);
		straight_lines(500 + walk, 200, 420 + walk, 150);
		straight_lines(500 + walk, 200, 600 + walk, 150);
		//girl2nd
		glColor3ub(255, 105, 180);
		person(25, 300 + walk, 320, 50);//h
		straight_lines(300 + walk, 320, 300 + walk, 200);//b
		straight_lines(300 + walk, 250, 250 + walk, 250);//lh
		straight_lines(300 + walk, 250, 350 + walk, 220);//rh
		straight_lines(300 + walk, 200, 260 + walk, 150);//rf
		straight_lines(300 + walk, 200, 350 + walk, 150);//lf
		glFlush();
		glutSwapBuffers();
		walk += 1;
	}

}

void display9() {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glColor3ub(162, 173, 208);
	rectangle(0, 400, 700, 700);
	glColor3ub(0, 100, 0);
	rectangle(0, 0, 700, 400);
	//tree
	glColor3ub(139, 69, 19);
	rectangle(0, 0, 100, 650);//tree bark
	glColor3ub(0, 128, 0);
	person(10, 10, 650, 300);//tree leaves
	//boy2nd
	glColor3ub(255, 255, 255);
	person(25, 100, 200, 50);
	straight_lines(100, 200, 100, 0);
	straight_lines(100, 100, 200, 150);
	straight_lines(100, 100, 30, 10);
	glFlush();
	glutSwapBuffers();
}

void display10() {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	//plane scene
	glColor3ub(0, 0, 128);
	rectangle(0, 0, 700, 700);
	glColor3f(255, 255, 255);
	glRasterPos3f(400, 180, 0);
	char text1[] = "20 Years Later.....";
	for (int i = 0; i < strlen(text1); i++) {
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, text1[i]);
	}
	if (plane_drift < 1000) {
		glColor3ub(255, 255, 255);
		//cloud1
		person(20, 95, 600, 45);
		person(20, 80, 570, 40);
		person(20, 50, 580, 30);
		person(20, 130, 580, 35);
		//cloud2
		person(20, 100, 300, 45);
		person(20, 90, 270, 40);
		person(20, 70, 280, 30);
		person(20, 130, 280, 35);
		//cloud3
		person(20, 400, 300, 45);
		person(20, 370, 260, 40);
		person(20, 350, 270, 30);
		person(20, 430, 270, 35);
		//cloud4
		person(20, 520, 500, 45);
		person(20, 490, 470, 40);
		person(20, 470, 480, 30);
		person(20, 550, 480, 35);
		//plane
		glColor3ub(178, 34, 34);
		triangles(250 + plane_drift, 460, 70 + plane_drift, 650, 350 + plane_drift, 460);//wings1
		glColor3ub(211, 211, 211);
		rectangle(20 + plane_drift, 400, 400, 90);//plane body
		person(25, 410 + plane_drift, 451, 40);//plane head
		person(25, 410 + plane_drift, 439, 40);//plane head
		glColor3ub(178, 34, 34);
		triangles(20 + plane_drift, 400, 0 + plane_drift, 550, 150 + plane_drift, 400);//tails
		triangles(200 + plane_drift, 420, 0 + plane_drift, 300, 370 + plane_drift, 420);//wings2
		plane_drift += 0.5;
	}
	glFlush();
	glutSwapBuffers();
}

//scene 5
void display11() {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glColor3ub(162, 162, 208); //color of the sky
	rectangle(0, 200, 700, 700); //size of the background
	moving_cloud();
	//ground color
	glColor3ub(102, 51, 0);
	rectangle(0, 0, 700, 200);

	//top of front wall (1st roof)
	triangle2();
	//roof
	roof();

	//grass 1
	glColor3ub(0, 128, 0);
	triangles(20, 170, 20, 250, 50, 170);
	triangles(50, 170, 65, 250, 80, 170);
	triangles(80, 170, 110, 250, 110, 170);

	//pebbles 1
	glColor3ub(128, 128, 128);
	person(25, 20, 170, 9);
	person(25, 40, 170, 9);
	person(25, 60, 170, 9);
	person(25, 80, 170, 9);
	person(25, 100, 170, 9);

	//front wall;
	frontwall();
	//door
	door();
	door_line();
	//right wall;
	rightwall();
	//window one
	window1();
	window1_Line();
	window2();
	window2_Line();

	//tree
	glColor3ub(139, 69, 19);
	rectangle(525, 120, 50, 200);//tree bark
	glColor3ub(0, 128, 0);
	person(10, 550, 450, 180);//tree leaves

	//grass 2
	triangles(470, 120, 470, 200, 500, 120);
	triangles(500, 120, 515, 200, 530, 120);
	triangles(530, 120, 560, 200, 560, 120);

	//pebbles 2
	glColor3ub(128, 128, 128);
	person(25, 470, 120, 9);
	person(25, 490, 120, 9);
	person(25, 510, 120, 9);
	person(25, 530, 120, 9);
	person(25, 550, 120, 9);

	//pebbles 3
	glColor3ub(128, 128, 128);
	person(25, 600, 180, 9);
	person(25, 640, 180, 9);
	person(25, 680, 180, 9);
	person(25, 620, 160, 9);
	person(25, 660, 160, 9);
	person(25, 600, 140, 9);
	person(25, 640, 140, 9);
	person(25, 680, 140, 9);

	//girl2nd
	glColor3ub(255, 105, 180);
	person(25, 100, 170, 30);//head
	straight_lines(100, 180, 100, 80);//body
	straight_lines(70, 100, 100, 130);//left hand
	straight_lines(100, 130, 130, 100);//right hand
	straight_lines(80, 30, 100, 80);//left leg
	straight_lines(100, 80, 120, 30);//right leg

	glFlush();
	glutSwapBuffers();
}

//scene 6 
void display12() {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glColor3ub(204, 255, 255);//color
	rectangle(0, 0, 700, 700);//background size
	land();
	land2();
	moving_cloud();

	//tree
	glColor3ub(139, 69, 19);
	rectangle(350, 170, 110, 300);//tree bark
	tree_element();
	tree_elements();

	//tree leaves
	glColor3ub(0, 128, 0);
	person(20, 400, 530, 150);//tree leaves

	//grass 1
	triangles(320, 170, 320, 250, 350, 170);
	triangles(350, 170, 365, 250, 380, 170);
	triangles(380, 170, 410, 250, 410, 170);

	//grass 2
	triangles(500, 250, 500, 330, 530, 250);
	triangles(530, 250, 545, 330, 560, 250);
	triangles(560, 250, 590, 330, 590, 250);

	//grass 3
	triangles(100, 300, 100, 380, 130, 300);
	triangles(130, 300, 145, 380, 160, 300);
	triangles(160, 300, 190, 380, 190, 300);

	//boy 2
	glColor3ub(255, 255, 255);
	person(25, 100, 240, 45);//head
	straight_lines(100, 200, 120, 80);//body
	straight_lines(60, 100, 105, 180);//left hand
	straight_lines(90, 70, 105, 180);//right hand
	straight_lines(120, 80, 140, 140);//left leg
	straight_lines(140, 140, 150, 90);//left leg 1
	straight_lines(120, 80, 160, 150);//right leg
	straight_lines(160, 150, 190, 90);//right leg 1

	glFlush();
	glutSwapBuffers();

}


//scene 7 
void display13() {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	display_rain();
	display_rain();

	glColor3ub(47, 79, 79);
	rectangle(120, 0, 200, 550);//building 2 (BG)

	glColor3ub(47, 79, 79);
	rectangle(400, 0, 150, 640);//building 2 (BG)

	glColor3ub(112, 128, 144);
	rectangle(-50, 0, 130, 500);//building 1

	glColor3ub(112, 128, 144);
	rectangle(100, 0, 130, 400);//building 2


	glColor3ub(112, 128, 144);
	rectangle(250, 0, 200, 450);//building 3

	glColor3ub(112, 128, 144);
	rectangle(470, 0, 140, 600);//building 3

	glColor3ub(112, 128, 144);
	rectangle(630, 0, 140, 550);//building 4

	glColor3ub(255, 105, 180);
	person(25, 85 + walk, 200, 50);//h
	straight_lines(50 + walk, 200, 50 + walk, -5);//b
	straight_lines(50 + walk, 140, 90 + walk, 50);//lh
	straight_lines(50 + walk, 140, 10 + walk, 50);//rh
	glFlush();
	walk += 1;

	glFlush();
	glutSwapBuffers();
}

//scene 8 
void display14() {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	display_rain();
	display_rain();
	glColor3ub(59, 59, 59);
	rectangle(0, 0, 1000, 200);//land

	glColor3ub(255, 105, 180);
	person(25, 300 + walk, 320, 50);//h
	straight_lines(300 + walk, 320, 300 + walk, 200);//b
	straight_lines(300 + walk, 250, 250 + walk, 220);//lh
	straight_lines(300 + walk, 250, 350 + walk, 220);//rh
	straight_lines(300 + walk, 200, 260 + walk, 150);//rf
	straight_lines(300 + walk, 200, 350 + walk, 150);//lf
	glFlush();
	walk -= 1;

	glFlush();
	glutSwapBuffers();
}

//scene9 
void display15() {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	rectangle(0, 200, 700, 700); //size of the background
	display_rain();
	glColor3ub(0, 153, 76); //ground color on rainy day, we have grass
	rectangle(0, 0, 700, 200);
	glColor3ub(139, 69, 19);
	rectangle(300, 160, 50, 500);//tree bark
	glColor3ub(0, 128, 0);
	person(10, 330, 500, 180);//tree leaves

	//grass 1
	glColor3ub(0, 128, 0);
	triangles(20, 170, 20, 250, 50, 170);
	triangles(50, 170, 65, 250, 80, 170);
	triangles(80, 170, 110, 250, 110, 170);

	//grass 2
	triangles(470, 120, 470, 200, 500, 120);
	triangles(500, 120, 515, 200, 530, 120);
	triangles(530, 120, 560, 200, 560, 120);

	// girl run 
	glColor3ub(255, 105, 180);
	person(25, 600, 170, 30);//head
	straight_lines(600, 80, 600, 180);//body
	straight_lines(640, 100, 600, 130);//left hand
	straight_lines(600, 130, 560, 110);//right hand
	straight_lines(650, 30, 600, 80);//left leg
	straight_lines(600, 80, 550, 30);//right leg

	//boy
	glColor3ub(255, 255, 255);
	person(25, 240, 170, 30);//head
	straight_lines(240, 180, 240, 80);//body
	straight_lines(210, 100, 240, 130);//left hand
	straight_lines(240, 130, 270, 100);//right hand
	straight_lines(220, 30, 240, 80);//left leg
	straight_lines(240, 80, 260, 30);//right leg

	//umbrella
	glColor3ub(255, 255, 255);
	semicircle(25, 280, 170, 90);

	//umbrella stick
	glColor3ub(255, 255, 255);
	straight_lines(280, 200, 275, 100);

	glFlush();
	glutSwapBuffers();
}

void display16() {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	rectangle(0, 200, 700, 700); //size of the background
	display_rain();
	glColor3ub(0, 153, 76); //ground color on rainy day, we have grass
	rectangle(0, 0, 700, 200);
	glColor3ub(139, 69, 19);
	rectangle(300, 160, 50, 500);//tree bark
	glColor3ub(0, 128, 0);
	person(10, 330, 500, 180);//tree leaves

	//grass 1
	glColor3ub(0, 128, 0);
	triangles(20, 170, 20, 250, 50, 170);
	triangles(50, 170, 65, 250, 80, 170);
	triangles(80, 170, 110, 250, 110, 170);

	//grass 2
	triangles(470, 120, 470, 200, 500, 120);
	triangles(500, 120, 515, 200, 530, 120);
	triangles(530, 120, 560, 200, 560, 120);

	// girl run n stop
	glColor3ub(255, 105, 180);
	person(25, 500, 170, 30);//head
	straight_lines(500, 80, 500, 180);//body
	straight_lines(540, 100, 500, 130);//left hand
	straight_lines(500, 130, 460, 100);//right hand
	straight_lines(550, 30, 500, 80);//left leg
	straight_lines(500, 80, 450, 30);//right leg

	//boy
	glColor3ub(255, 255, 255);
	person(25, 240, 170, 30);//head
	straight_lines(240, 180, 240, 80);//body
	straight_lines(210, 100, 240, 130);//left hand
	straight_lines(240, 130, 270, 100);//right hand
	straight_lines(220, 30, 240, 80);//left leg
	straight_lines(240, 80, 260, 30);//right leg

	//umbrella
	glColor3ub(255, 255, 255);
	semicircle(25, 280, 170, 90);

	//umbrella stick
	glColor3ub(255, 255, 255);
	straight_lines(280, 200, 275, 100);

	glFlush();
	glutSwapBuffers();
}

void display17() {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	rectangle(0, 200, 700, 700); //size of the background
	display_rain();
	glColor3ub(0, 153, 76); //ground color on rainy day, we have grass
	rectangle(0, 0, 700, 200);
	glColor3ub(139, 69, 19);
	rectangle(300, 160, 50, 500);//tree bark
	glColor3ub(0, 128, 0);
	person(10, 330, 500, 180);//tree leaves

	//grass 1
	glColor3ub(0, 128, 0);
	triangles(20, 170, 20, 250, 50, 170);
	triangles(50, 170, 65, 250, 80, 170);
	triangles(80, 170, 110, 250, 110, 170);

	//grass 2
	triangles(470, 120, 470, 200, 500, 120);
	triangles(500, 120, 515, 200, 530, 120);
	triangles(530, 120, 560, 200, 560, 120);

	// girl ask for umbrella
	glColor3ub(255, 105, 180);
	person(25, 500, 170, 30);//head
	straight_lines(500, 80, 500, 180);//body
	straight_lines(540, 100, 500, 130);//left hand
	straight_lines(500, 130, 460, 120);//right hand
	straight_lines(550, 30, 500, 80);//left leg
	straight_lines(500, 80, 450, 30);//right leg

	//boy
	glColor3ub(255, 255, 255);
	person(25, 240, 170, 30);//head
	straight_lines(240, 180, 240, 80);//body
	straight_lines(210, 100, 240, 130);//left hand
	straight_lines(240, 130, 270, 100);//right hand
	straight_lines(220, 30, 240, 80);//left leg
	straight_lines(240, 80, 260, 30);//right leg

	//umbrella
	glColor3ub(255, 255, 255);
	semicircle(25, 280, 170, 90);

	//umbrella stick
	glColor3ub(255, 255, 255);
	straight_lines(280, 200, 275, 100);

	glFlush();
	glutSwapBuffers();
}

void display18() {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	rectangle(0, 200, 700, 700); //size of the background
	display_rain();
	glColor3ub(0, 153, 76); //ground color on rainy day, we have grass
	rectangle(0, 0, 700, 200);
	glColor3ub(139, 69, 19);
	rectangle(300, 160, 50, 500);//tree bark
	glColor3ub(0, 128, 0);
	person(10, 330, 500, 180);//tree leaves

	//grass 1
	glColor3ub(0, 128, 0);
	triangles(20, 170, 20, 250, 50, 170);
	triangles(50, 170, 65, 250, 80, 170);
	triangles(80, 170, 110, 250, 110, 170);

	//grass 2
	triangles(470, 120, 470, 200, 500, 120);
	triangles(500, 120, 515, 200, 530, 120);
	triangles(530, 120, 560, 200, 560, 120);

	// girl 
	glColor3ub(255, 105, 180);
	person(25, 500, 170, 30);//head
	straight_lines(500, 80, 500, 180);//body
	straight_lines(540, 100, 500, 130);//left hand
	straight_lines(500, 130, 460, 100);//right hand
	straight_lines(550, 30, 500, 80);//left leg
	straight_lines(500, 80, 450, 30);//right leg

	//boy saw girl and lift up umbrella
	glColor3ub(255, 255, 255);
	person(25, 240, 170, 30);//head
	straight_lines(240, 180, 240, 80);//body
	straight_lines(210, 100, 240, 130);//left hand
	straight_lines(240, 130, 270, 120);//right hand
	straight_lines(220, 30, 240, 80);//left leg
	straight_lines(240, 80, 260, 30);//right leg

	//umbrella
	glColor3ub(255, 255, 255);
	semicircle(25, 280, 190, 90);

	//umbrella stick
	glColor3ub(255, 255, 255);
	straight_lines(280, 200, 275, 120);

	glFlush();
	glutSwapBuffers();
}

//scene 10 (blase)
void display19() {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	rectangle(0, 200, 700, 700); //size of the background
	display_rain();
	glColor3ub(0, 153, 76); //ground color on rainy day, we have grass
	rectangle(0, 0, 700, 200);
	glColor3ub(139, 69, 19);
	rectangle(300, 160, 50, 500);//tree bark
	glColor3ub(0, 128, 0);
	person(10, 330, 500, 180);//tree leaves

	//grass 1
	glColor3ub(0, 128, 0);
	triangles(20, 170, 20, 250, 50, 170);
	triangles(50, 170, 65, 250, 80, 170);
	triangles(80, 170, 110, 250, 110, 170);

	//grass 2
	triangles(470, 120, 470, 200, 500, 120);
	triangles(500, 120, 515, 200, 530, 120);
	triangles(530, 120, 560, 200, 560, 120);

	// girl run to the boy
	glColor3ub(255, 105, 180);
	person(25, 350, 170, 30);//head
	straight_lines(350, 80, 350, 180);//body
	straight_lines(320, 100, 350, 130);//left hand
	straight_lines(350, 130, 330, 100);//right hand
	straight_lines(375, 30, 350, 80);//left leg
	straight_lines(350, 80, 325, 30);//right leg

	//boy
	glColor3ub(255, 255, 255);
	person(25, 240, 170, 30);//head
	straight_lines(240, 180, 240, 80);//body
	straight_lines(210, 100, 240, 130);//left hand
	straight_lines(240, 130, 270, 120);//right hand
	straight_lines(220, 30, 240, 80);//left leg
	straight_lines(240, 80, 260, 30);//right leg

	//umbrella
	glColor3ub(255, 255, 255);
	semicircle(25, 280, 190, 90);

	//umbrella stick
	glColor3ub(255, 255, 255);
	straight_lines(280, 200, 275, 120);

	glFlush();
	glutSwapBuffers();
}

void display20() {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	rectangle(0, 200, 700, 700); //size of the background
	display_rain();
	glColor3ub(0, 153, 76); //ground color on rainy day, we have grass
	rectangle(0, 0, 700, 200);
	glColor3ub(139, 69, 19);
	rectangle(300, 160, 50, 500);//tree bark
	glColor3ub(0, 128, 0);
	person(10, 330, 500, 180);//tree leaves

	//grass 1
	glColor3ub(0, 128, 0);
	triangles(20, 170, 20, 250, 50, 170);
	triangles(50, 170, 65, 250, 80, 170);
	triangles(80, 170, 110, 250, 110, 170);

	//grass 2
	triangles(470, 120, 470, 200, 500, 120);
	triangles(500, 120, 515, 200, 530, 120);
	triangles(530, 120, 560, 200, 560, 120);

	// girl 
	glColor3ub(255, 105, 180);
	person(25, 320, 170, 30);//head
	straight_lines(320, 80, 320, 180);//body
	straight_lines(300, 100, 320, 130);//left hand
	straight_lines(320, 130, 350, 100);//right hand
	straight_lines(345, 30, 320, 80);//left leg
	straight_lines(320, 80, 295, 30);//right leg

	//boy
	glColor3ub(255, 255, 255);
	person(25, 240, 170, 30);//head
	straight_lines(240, 180, 240, 80);//body
	straight_lines(210, 100, 240, 130);//left hand
	straight_lines(240, 130, 270, 100);//right hand
	straight_lines(220, 30, 240, 80);//left leg
	straight_lines(240, 80, 260, 30);//right leg

	//umbrella
	glColor3ub(255, 255, 255);
	semicircle(25, 280, 170, 90);

	//umbrella stick
	glColor3ub(255, 255, 255);
	straight_lines(280, 200, 275, 100);

	glFlush();
	glutSwapBuffers();
}

void display21() {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	rectangle(0, 200, 700, 700); //size of the background
	display_rain();
	glColor3ub(0, 153, 76); //ground color on rainy day, we have grass
	rectangle(0, 0, 700, 200);
	glColor3ub(139, 69, 19);
	rectangle(300, 160, 50, 500);//tree bark
	glColor3ub(0, 128, 0);
	person(10, 330, 500, 180);//tree leaves

	//grass 1
	glColor3ub(0, 128, 0);
	triangles(20, 170, 20, 250, 50, 170);
	triangles(50, 170, 65, 250, 80, 170);
	triangles(80, 170, 110, 250, 110, 170);

	//grass 2
	triangles(470, 120, 470, 200, 500, 120);
	triangles(500, 120, 515, 200, 530, 120);
	triangles(530, 120, 560, 200, 560, 120);

	//boy
	glColor3ub(255, 255, 255);//boy colour pink
	person(30, 280, 200, 40);//head
	glLineWidth(10);
	straight_lines(280, 200, 280, 80);//body
	straight_lines(280, 160, 230, 120);//left hand
	straight_lines(320, 120, 280, 160);//right hand
	straight_lines(280, 85, 240, 40);//left foot
	straight_lines(320, 40, 280, 80);//right foot

	//umbrella
	glColor3ub(255, 255, 255);
	semicircle(175, 290, 300, 100);

	//umbrella stick
	glColor3ub(255, 255, 255);
	straight_lines(285, 320, 285, 200);

	//girl
	glColor3ub(255, 105, 180);//girl colour pink
	person(25, 430, 200, 40);//head
	straight_lines(430, 200, 430, 80);//body
	straight_lines(450, 100, 430, 150);// hand
	straight_lines(400, 100, 430, 150);// hand up
	straight_lines(430, 90, 460, 40);//left foot
	straight_lines(400, 40, 430, 100);//right foot

	glFlush();
	glutSwapBuffers();
}

void display22() {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	rectangle(0, 200, 700, 700); //size of the background
	display_rain();
	glColor3ub(0, 153, 76); //ground color on rainy day, we have grass
	rectangle(0, 0, 700, 200);
	glColor3ub(139, 69, 19);
	rectangle(300, 160, 50, 500);//tree bark
	glColor3ub(0, 128, 0);
	person(10, 330, 500, 180);//tree leaves

	//grass 1
	glColor3ub(0, 128, 0);
	triangles(20, 170, 20, 250, 50, 170);
	triangles(50, 170, 65, 250, 80, 170);
	triangles(80, 170, 110, 250, 110, 170);

	//grass 2
	triangles(470, 120, 470, 200, 500, 120);
	triangles(500, 120, 515, 200, 530, 120);
	triangles(530, 120, 560, 200, 560, 120);

	//boy
	glColor3ub(255, 255, 255);//boy colour pink
	person(30, 290, 200, 40);//head
	glLineWidth(10);
	straight_lines(290, 200, 290, 80);//body
	straight_lines(290, 160, 230, 120);//left hand
	straight_lines(320, 120, 290, 160);//right hand
	straight_lines(290, 85, 240, 40);//left foot
	straight_lines(320, 40, 290, 80);//right foot

	//girl
	glColor3ub(255, 105, 180);//girl colour pink
	person(25, 400, 200, 40);//head
	straight_lines(400, 200, 400, 80);//body
	straight_lines(420, 100, 400, 150);// hand
	straight_lines(370, 100, 400, 150);// hand up
	straight_lines(400, 100, 450, 40);//left foot
	straight_lines(370, 40, 400, 100);//right foot

	//umbrella
	glColor3ub(255, 255, 255);
	semicircle(175 - walk, 290 + walk, 300 - walk, 100);
	//umbrella stick
	glColor3ub(255, 255, 255);
	straight_lines(285 + walk, 320 - walk, 285 + walk, 200 - walk);
	glFlush();
	walk -= 1;
	glFlush();
	glutSwapBuffers();
}

void display23() {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	rectangle(0, 200, 700, 700); //size of the background
	display_rain();
	glColor3ub(0, 153, 76); //ground color on rainy day, we have grass
	rectangle(0, 0, 700, 200);
	glColor3ub(139, 69, 19);
	rectangle(300, 160, 50, 500);//tree bark
	glColor3ub(0, 128, 0);
	person(10, 330, 500, 180);//tree leaves

	//grass 1
	glColor3ub(0, 128, 0);
	triangles(20, 170, 20, 250, 50, 170);
	triangles(50, 170, 65, 250, 80, 170);
	triangles(80, 170, 110, 250, 110, 170);

	//grass 2
	triangles(470, 120, 470, 200, 500, 120);
	triangles(500, 120, 515, 200, 530, 120);
	triangles(530, 120, 560, 200, 560, 120);

	//boy
	glColor3ub(255, 255, 255);//boy colour pink
	person(30, 290, 200, 40);//head
	glLineWidth(10);
	straight_lines(290, 200, 290, 80);//body
	straight_lines(290, 160, 230, 120);//left hand
	straight_lines(360, 120, 290, 150);//right hand
	straight_lines(290, 85, 240, 40);//left foot
	straight_lines(320, 40, 290, 80);//right foot


	//girl
	glColor3ub(255, 105, 180);//girl colour pink
	person(25, 400, 200, 40);//head
	straight_lines(400, 200, 400, 80);//body
	straight_lines(420, 100, 400, 150);// hand
	straight_lines(370, 100, 400, 150);// hand up
	straight_lines(400, 100, 450, 40);//left foot
	straight_lines(370, 40, 400, 100);//right foot

	glFlush();
	glutSwapBuffers();

}

void display24() {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	rectangle(0, 200, 700, 700); //size of the background
	display_rain();
	glColor3ub(0, 153, 76); //ground color on rainy day, we have grass
	rectangle(0, 0, 700, 200);
	glColor3ub(139, 69, 19);
	rectangle(300, 160, 50, 500);//tree bark
	glColor3ub(0, 128, 0);
	person(10, 330, 500, 180);//tree leaves

	//grass 1
	glColor3ub(0, 128, 0);
	triangles(20, 170, 20, 250, 50, 170);
	triangles(50, 170, 65, 250, 80, 170);
	triangles(80, 170, 110, 250, 110, 170);

	//grass 2
	triangles(470, 120, 470, 200, 500, 120);
	triangles(500, 120, 515, 200, 530, 120);
	triangles(530, 120, 560, 200, 560, 120);

	//boy
	glColor3ub(255, 255, 255);//boy colour pink
	person(30, 290, 200, 40);//head
	glLineWidth(10);
	straight_lines(290, 200, 290, 80);//body
	straight_lines(290, 160, 230, 120);//left hand
	straight_lines(360, 120, 290, 150);//right hand
	straight_lines(290, 85, 240, 40);//left foot
	straight_lines(320, 40, 290, 80);//right foot

	//girl
	glColor3ub(255, 105, 180);//girl colour pink
	person(25, 400, 200, 40);//head
	straight_lines(400, 200, 400, 80);//body
	straight_lines(420, 100, 400, 150);// hand
	straight_lines(360, 120, 400, 150);// hand up
	straight_lines(400, 100, 450, 40);//left foot
	straight_lines(370, 40, 400, 100);//right foot

	glFlush();
	glutSwapBuffers();
}

void display25() {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glColor3ub(135, 206, 250); //color of the sky
	rectangle(0, 200, 700, 700); //size of the background
	glColor3ub(0, 153, 76); //ground color on rainy day, we have grass
	rectangle(0, 0, 700, 200);
	glColor3ub(139, 69, 19);
	rectangle(300, 160, 50, 500);//tree bark
	glColor3ub(0, 128, 0);
	person(10, 330, 500, 180);//tree leaves

	//grass 1
	glColor3ub(0, 128, 0);
	triangles(20, 170, 20, 250, 50, 170);
	triangles(50, 170, 65, 250, 80, 170);
	triangles(80, 170, 110, 250, 110, 170);

	//grass 2
	triangles(470, 120, 470, 200, 500, 120);
	triangles(500, 120, 515, 200, 530, 120);
	triangles(530, 120, 560, 200, 560, 120);

	//boy
	glColor3ub(255, 255, 255);//boy colour pink
	person(30, 290, 200, 40);//head
	glLineWidth(10);
	straight_lines(290, 200, 290, 80);//body
	straight_lines(290, 160, 230, 120);//left hand
	straight_lines(360, 120, 290, 150);//right hand
	straight_lines(290, 85, 240, 40);//left foot
	straight_lines(320, 40, 290, 80);//right foot

	//girl
	glColor3ub(255, 105, 180);//girl colour pink
	person(25, 400, 200, 40);//head
	straight_lines(400, 200, 400, 80);//body
	straight_lines(420, 100, 400, 150);// hand
	straight_lines(360, 120, 400, 150);// hand up
	straight_lines(400, 100, 450, 40);//left foot
	straight_lines(370, 40, 400, 100);//right foot

	loveShape(20, 200, 400, 5);
	loveShape(20, 360, 400, 5);
	loveShape(20, 525, 400, 5);
	glFlush();
	glutSwapBuffers();
}

void idle() {
	DWORD start = GetTickCount64();
	while (GetTickCount64() - start < 1000 / FPS);
	x += dx;
	y += dy;
	if (x < 0 || x > SCREEN_WIDTH) dx *= -1;
	if (y < 0 || y > SCREEN_HEIGHT) dy *= -1;
	glutPostRedisplay();
}

void initGL() {
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0, SCREEN_WIDTH, 0, SCREEN_HEIGHT);
	glPointSize(10.0);
	glLineWidth(10.0);
}

int main(int argc, char** argv) {
	glutInitDisplayMode(GLUT_DOUBLE);
	glutInit(&argc, argv);
	glutInitWindowPosition(100, 30);
	glutInitWindowSize(SCREEN_WIDTH, SCREEN_HEIGHT);
	glutCreateWindow("Childhood Love");
	glutDisplayFunc(display);
	glutIdleFunc(idle);
	glutTimerFunc(1000, MyTimerFunc, 0);

	srand(1);
	initRain();
	glEnable(GL_BLEND); //Enable blending.
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA); //Set blending function.
	init(); // call init function defined above
	glutIdleFunc(r_idle); //  define what function to call when the program is idle
	glutMainLoop();
	initGL();

	glutMainLoop();

}


void MyTimerFunc(int value)
{
	if (value == 0) // passed in in main
	{
		glutDisplayFunc(display);
		glutIdleFunc(display);
		// Change to a new display function in 2 seconds
		glutTimerFunc(1000, MyTimerFunc, 1);
	}

	else if (value == 1)
	{
		glutDisplayFunc(display2);
		glutIdleFunc(display2);
		glutTimerFunc(1000, MyTimerFunc, 2);
	}
	else if (value == 2) {
		glutDisplayFunc(display3);
		glutIdleFunc(display3);
		glutTimerFunc(3000, MyTimerFunc, 3);
	}
	else if (value == 3) {
		glutDisplayFunc(display4);
		glutIdleFunc(display4);
		glutTimerFunc(3000, MyTimerFunc, 4);
	}
	else if (value == 4) {
		glutDisplayFunc(display5);
		glutIdleFunc(display5);
		glutTimerFunc(5000, MyTimerFunc, 5);
	}
	else if (value == 5) {
		glutDisplayFunc(display6);
		glutIdleFunc(display6);
		glutTimerFunc(3000, MyTimerFunc, 6);
	}
	else if (value == 6) {
		glutDisplayFunc(display7);
		glutIdleFunc(display7);
		glutTimerFunc(3000, MyTimerFunc, 7);
	}
	else if (value == 7) {
		glutDisplayFunc(display8);
		glutIdleFunc(display8);
		glutTimerFunc(1000, MyTimerFunc, 8);
	}
	else if (value == 8) {
		glutDisplayFunc(display9);
		glutIdleFunc(display9);
		glutTimerFunc(1000, MyTimerFunc, 9);
	}
	else if (value == 9) {
		glutDisplayFunc(display10);
		glutIdleFunc(display10);
		glutTimerFunc(4000, MyTimerFunc, 10);
	}
	else if (value == 10) {
		glutDisplayFunc(display11);
		glutIdleFunc(display11);
		glutTimerFunc(3000, MyTimerFunc, 11);
	}
	else if (value == 11) {
		glutDisplayFunc(display12);
		glutIdleFunc(display12);
		glutTimerFunc(3000, MyTimerFunc, 12);
	}
	else if (value == 12) {
		glutDisplayFunc(display13);
		glutIdleFunc(display13);
		glutTimerFunc(5000, MyTimerFunc, 13);
	}

	else if (value == 13) {
		glutDisplayFunc(display14);
		glutIdleFunc(display14);
		glutTimerFunc(9000, MyTimerFunc, 14);
	}

	else if (value == 14) {
		glutDisplayFunc(display15);
		glutIdleFunc(display15);
		glutTimerFunc(3000, MyTimerFunc, 15);
	}
	else if (value == 15) {
		glutDisplayFunc(display16);
		glutIdleFunc(display16);
		glutTimerFunc(1000, MyTimerFunc, 16);
	}

	else if (value == 16) {
		glutDisplayFunc(display17);
		glutIdleFunc(display17);
		glutTimerFunc(1000, MyTimerFunc, 17);
	}

	else if (value == 17) {
		glutDisplayFunc(display18);
		glutIdleFunc(display18);
		glutTimerFunc(1000, MyTimerFunc, 18);
	}

	else if (value == 18) {
		glutDisplayFunc(display19);
		glutIdleFunc(display19);
		glutTimerFunc(1000, MyTimerFunc, 19);
	}

	else if (value == 19) {
		glutDisplayFunc(display20);
		glutIdleFunc(display20);
		glutTimerFunc(1000, MyTimerFunc, 20);
	}
	else if (value == 20) // passed in in main
	{
		glutDisplayFunc(display21);
		glutIdleFunc(display21);
		// Change to a new display function in 2 seconds
		glutTimerFunc(1000, MyTimerFunc, 21);
	}

	else if (value == 21)
	{
		glutDisplayFunc(display22);
		glutIdleFunc(display22);
		glutTimerFunc(3000, MyTimerFunc, 22);
	}
	else if (value == 22)
	{
		glutDisplayFunc(display23);
		glutIdleFunc(display23);
		glutTimerFunc(1000, MyTimerFunc, 23);
	}
	else if (value == 23)
	{
		glutDisplayFunc(display24);
		glutIdleFunc(display24);
		glutTimerFunc(1000, MyTimerFunc, 24);
	}
	else if (value == 24)
	{
		glutDisplayFunc(display25);
		glutIdleFunc(display25);
		glutTimerFunc(1000, MyTimerFunc, 25);
	}
}