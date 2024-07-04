#include <glut.h>
#include <math.h>

float hookLength = 0.0; 
float hookSpeed = 0.5; 

GLsizei Width = 800.0;
GLsizei Height = 600.0;

float radius = 100.0;

float fish1X = 5.0f;
float fish1Y = 0.3f;

float fish2X = 0.7f;
float fish2Y = 0.6f;

float fish3X = 0.5f;
float fish3Y = 0.8f;

float fish4X = 1.4f;
float fish4Y = 0.6f;

float fish5X = 2.7f;
float fish5Y = 0.6f;

float fish6X = 2.4f;
float fish6Y = 0.7f;

float fish7X = 0.7f;
float fish7Y = 0.7f;

float fish8X = 2.5f;
float fish8Y = 0.8f;

float ship_x = 5, ship_y = 2;
GLfloat waterlevel = 150.0f;
GLfloat sandlevel = -150.0f;

void sea()
{
	glPushMatrix();
	glColor3f(0.1, 0.5, 1.0);
	glBegin(GL_POLYGON);
	glVertex2f(-200, -550);
	glVertex2f(0, waterlevel);
	glVertex2f(16, waterlevel - 13);
	glVertex2f(23, waterlevel - 6);
	glVertex2f(39, waterlevel - 12);
	glVertex2f(51, waterlevel - 11);
	glVertex2f(73, waterlevel - 3);
	glVertex2f(83, waterlevel - 11);
	glVertex2f(95, waterlevel - 8);
	glVertex2f(112, waterlevel - 5);
	glVertex2f(129, waterlevel - 6);
	glVertex2f(141, waterlevel - 8);
	glVertex2f(147, waterlevel - 8);
	glVertex2f(157, waterlevel - 4);
	glVertex2f(172, waterlevel - 2);
	glVertex2f(192, waterlevel - 4);
	glVertex2f(214, waterlevel - 10);
	glVertex2f(254, waterlevel - 13);
	glVertex2f(284, waterlevel - 9);
	glVertex2f(344, waterlevel - 7);
	glVertex2f(360, waterlevel - 12);
	glVertex2f(392, waterlevel - 11);
	glVertex2f(410, waterlevel - 6);
	glVertex2f(451, waterlevel - 11);
	glVertex2f(485, waterlevel - 5);
	glVertex2f(504, waterlevel - 13);
	glVertex2f(552, waterlevel - 13);
	glVertex2f(593, waterlevel - 9);
	glVertex2f(630, waterlevel);
	glVertex2f(684, waterlevel - 10);
	glVertex2f(720, waterlevel - 8);
	glVertex2f(753, waterlevel - 9);
	glVertex2f(800, waterlevel - 10);
	glVertex2f(852, waterlevel - 10);
	glVertex2f(880, waterlevel - 23);
	glVertex2f(901, waterlevel - 8);
	glVertex2f(920, waterlevel - 12);
	glVertex2f(954, waterlevel - 6);
	glVertex2f(980, waterlevel - 13);
	glVertex2f(1004, waterlevel - 7);
	glVertex2f(1000, 0);
	glVertex2f(1602, waterlevel - 14);
	glVertex2f(3000, waterlevel - 200);
	glEnd();

	glPopMatrix();
}

void sand() 
{
	glPushMatrix();
	glColor3f(0.69f, 0.58f, 0.46f);
	glBegin(GL_POLYGON);
	glVertex2f(-200, -550);
	glVertex2f(0, sandlevel);
	glVertex2f(16, sandlevel - 13);
	glVertex2f(23, sandlevel - 6);
	glVertex2f(39, sandlevel - 12);
	glVertex2f(51, sandlevel - 11);
	glVertex2f(73, sandlevel - 3);
	glVertex2f(83, sandlevel - 11);
	glVertex2f(95, sandlevel - 8);
	glVertex2f(112, sandlevel - 5);
	glVertex2f(129, sandlevel - 6);
	glVertex2f(141, sandlevel - 8);
	glVertex2f(147, sandlevel - 8);
	glVertex2f(157, sandlevel - 4);
	glVertex2f(172, sandlevel - 2);
	glVertex2f(192, sandlevel - 4);
	glVertex2f(214, sandlevel - 10);
	glVertex2f(254, sandlevel - 13);
	glVertex2f(284, sandlevel - 9);
	glVertex2f(344, sandlevel - 7);
	glVertex2f(360, sandlevel - 12);
	glVertex2f(392, sandlevel - 11);
	glVertex2f(410, sandlevel - 6);
	glVertex2f(451, sandlevel - 11);
	glVertex2f(485, sandlevel - 5);
	glVertex2f(504, sandlevel - 13);
	glVertex2f(552, sandlevel - 13);
	glVertex2f(593, sandlevel - 9);
	glVertex2f(630, sandlevel);
	glVertex2f(684, sandlevel - 10);
	glVertex2f(720, sandlevel - 8);
	glVertex2f(753, sandlevel - 9);
	glVertex2f(800, sandlevel - 10);
	glVertex2f(852, sandlevel - 10);
	glVertex2f(880, sandlevel - 23);
	glVertex2f(901, sandlevel - 8);
	glVertex2f(920, sandlevel - 12);
	glVertex2f(954, sandlevel - 6);
	glVertex2f(980, sandlevel - 13);
	glVertex2f(1004, sandlevel - 7);
	glVertex2f(1000, sandlevel);
	glVertex2f(1602, sandlevel - 14);
	glVertex2f(3000, sandlevel - 200);
	glEnd();

	glPopMatrix();
}

void DrawFish1()
{
	glTranslatef(-200, -300, 0.0); 
	glScalef(250.0f, 250.0f, 0.0f);
	glTranslatef(fish1X, fish1Y, 0.0);
	glPushMatrix();
	glColor3f(0.000, 0.749, 1.000);

	glBegin(GL_POLYGON);
	glVertex3f(0.428, 0.127, 0.0);
	glVertex3f(0.517, 0.057, 0.0);
	glVertex3f(0.499, 0.108, 0.0);
	glVertex3f(0.488, 0.162, 0.0);
	glVertex3f(0.486, 0.148, 0.0);
	glVertex3f(0.497, 0.233, 0.0);
	glVertex3f(0.514, 0.282, 0.0);
	glVertex3f(0.528, 0.318, 0.0);
	glVertex3f(0.429, 0.245, 0.0);
	glEnd();

	glColor3f(0.000, 0.749, 1.000);
	glBegin(GL_POLYGON);
	glVertex3f(0.160, 0.304, 0.0);
	glVertex3f(0.177, 0.326, 0.0);
	glVertex3f(0.193, 0.334, 0.0);
	glVertex3f(0.221, 0.346, 0.0);
	glVertex3f(0.224, 0.348, 0.0);
	glVertex3f(0.244, 0.348, 0.0);
	glVertex3f(0.265, 0.345, 0.0);
	glVertex3f(0.303, 0.333, 0.0);
	glVertex3f(0.276, 0.304, 0.0);
	glEnd();


	glColor3f(0.3, 0.3, 1.000);
	glBegin(GL_POLYGON);
	glVertex3f(0.429, 0.243, 0.0);
	glVertex3f(0.306, 0.276, 0.0);
	glVertex3f(0.292, 0.301, 0.0);
	glVertex3f(0.226, 0.316, 0.0);
	glVertex3f(0.200, 0.319, 0.0);
	glVertex3f(0.164, 0.309, 0.0);
	glVertex3f(0.117, 0.288, 0.0);
	glVertex3f(0.077, 0.256, 0.0);
	glVertex3f(0.052, 0.222, 0.0);
	glVertex3f(0.038, 0.187, 0.0);
	glVertex3f(0.041, 0.144, 0.0);
	glVertex3f(0.061, 0.119, 0.0);
	glVertex3f(0.108, 0.083, 0.0);
	glVertex3f(0.168, 0.060, 0.0);
	glVertex3f(0.204, 0.053, 0.0);
	glVertex3f(0.231, 0.054, 0.0);
	glVertex3f(0.288, 0.067, 0.0);
	glVertex3f(0.340, 0.087, 0.0);
	glVertex3f(0.403, 0.115, 0.0);
	glVertex3f(0.428, 0.127, 0.0);
	glEnd();

	glPushMatrix();
	glTranslatef(.1, 0.22, 0.0);
	glBegin(GL_POLYGON);
	glColor3f(1.0, 1.0, 1.0);

	for (int i = 0; i < 200; i++)
	{
		float pi = 3.1416;
		float A = (i * 2 * pi) / 50;
		float r = 0.016;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x, y);
	}
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.0, 0.0, 0.0);
	for (int i = 0; i < 200; i++)
	{
		float pi = 3.1416;
		float A = (i * 2 * pi) / 50;
		float r = 0.005;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x, y);
	}
	glEnd();
	glPopMatrix();

	glColor3f(0.0, 0.0, 0.0);
	glLineWidth(2.0);
	glBegin(GL_LINES);
	glVertex3f(0.048, 0.135, 0.0);
	glVertex3f(0.077, 0.137, 0.0);

	glVertex3f(0.077, 0.137, 0.0);
	glVertex3f(0.091, 0.141, 0.0);
	glEnd();

	glColor3f(0.000, 0.749, 1.000);
	glBegin(GL_POLYGON);
	glVertex3f(0.165, 0.118, 0.0);
	glVertex3f(0.169, 0.098, 0.0);
	glVertex3f(0.182, 0.086, 0.0);
	glVertex3f(0.213, 0.076, 0.0);
	glVertex3f(0.253, 0.075, 0.0);
	glVertex3f(0.281, 0.082, 0.0);
	glVertex3f(0.286, 0.094, 0.0);
	glVertex3f(0.281, 0.102, 0.0);
	glVertex3f(0.267, 0.113, 0.0);
	glEnd();
	glPopMatrix();
}

void DrawFish2()
{
	glTranslatef(1500, -200, 0.0);
	glScalef(300.0f, 300.0f, 300.0f);
	glRotatef(180.0, 0.0, 1.0, 0.0);
	glTranslatef(fish2X, fish2Y, 0.0);
	glRotatef(180.0, 0.0, 1.0, 0.0);
	glPushMatrix();
	glColor3f(0.980, 0.502, 0.447);

	glBegin(GL_POLYGON);
	glVertex3f(0.428, 0.127, 0.0);
	glVertex3f(0.517, 0.057, 0.0);
	glVertex3f(0.499, 0.108, 0.0);
	glVertex3f(0.488, 0.162, 0.0);
	glVertex3f(0.486, 0.148, 0.0);
	glVertex3f(0.497, 0.233, 0.0);
	glVertex3f(0.514, 0.282, 0.0);
	glVertex3f(0.528, 0.318, 0.0);
	glVertex3f(0.429, 0.245, 0.0);
	glEnd();

	glColor3f(0.980, 0.502, 0.447);
	glBegin(GL_POLYGON);
	glVertex3f(0.160, 0.304, 0.0);
	glVertex3f(0.177, 0.326, 0.0);
	glVertex3f(0.193, 0.334, 0.0);
	glVertex3f(0.221, 0.346, 0.0);
	glVertex3f(0.224, 0.348, 0.0);
	glVertex3f(0.244, 0.348, 0.0);
	glVertex3f(0.265, 0.345, 0.0);
	glVertex3f(0.303, 0.333, 0.0);
	glVertex3f(0.276, 0.304, 0.0);
	glEnd();


	glColor3f(1.000, 0.000, 0.000);
	glBegin(GL_POLYGON);
	glVertex3f(0.429, 0.243, 0.0);
	glVertex3f(0.306, 0.276, 0.0);
	glVertex3f(0.292, 0.301, 0.0);
	glVertex3f(0.226, 0.316, 0.0);
	glVertex3f(0.200, 0.319, 0.0);
	glVertex3f(0.164, 0.309, 0.0);
	glVertex3f(0.117, 0.288, 0.0);
	glVertex3f(0.077, 0.256, 0.0);
	glVertex3f(0.052, 0.222, 0.0);
	glVertex3f(0.038, 0.187, 0.0);
	glVertex3f(0.041, 0.144, 0.0);
	glVertex3f(0.061, 0.119, 0.0);
	glVertex3f(0.108, 0.083, 0.0);
	glVertex3f(0.168, 0.060, 0.0);
	glVertex3f(0.204, 0.053, 0.0);
	glVertex3f(0.231, 0.054, 0.0);
	glVertex3f(0.288, 0.067, 0.0);
	glVertex3f(0.340, 0.087, 0.0);
	glVertex3f(0.403, 0.115, 0.0);
	glVertex3f(0.428, 0.127, 0.0);
	glEnd();

	glPushMatrix();
	glTranslatef(.1, 0.22, 0.0);
	glBegin(GL_POLYGON);
	glColor3f(1.0, 1.0, 1.0);

	for (int i = 0; i < 200; i++)
	{
		float pi = 3.1416;
		float A = (i * 2 * pi) / 50;
		float r = 0.005;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x, y);
	}
	glEnd();
	glPopMatrix();

	glColor3f(0.0, 0.0, 0.0);
	glLineWidth(2.0);
	glBegin(GL_LINES);
	glVertex3f(0.048, 0.135, 0.0);
	glVertex3f(0.077, 0.137, 0.0);

	glVertex3f(0.077, 0.137, 0.0);
	glVertex3f(0.091, 0.141, 0.0);
	glEnd();

	glColor3f(0.980, 0.502, 0.447);
	glBegin(GL_POLYGON);
	glVertex3f(0.165, 0.118, 0.0);
	glVertex3f(0.169, 0.098, 0.0);
	glVertex3f(0.182, 0.086, 0.0);
	glVertex3f(0.213, 0.076, 0.0);
	glVertex3f(0.253, 0.075, 0.0);
	glVertex3f(0.281, 0.082, 0.0);
	glVertex3f(0.286, 0.094, 0.0);
	glVertex3f(0.281, 0.102, 0.0);
	glVertex3f(0.267, 0.113, 0.0);
	glEnd();
	glPopMatrix();
}

void DrawFish3()
{
	glTranslatef(750, -300, 0.0); 
	glScalef(250.0f, 250.0f, 0.0f);
	glRotatef(0.0, 0.0, 1.0, 0.0);
	glTranslatef(fish3X, fish3Y, 0.0);
	glPushMatrix();

	glColor3f(1.0, 1.0, 0.0);
	glBegin(GL_POLYGON);
	glVertex2f(0.7, -0.05);
	glVertex2f(0.75, -0.1);
	glVertex2f(0.85, -0.05);
	glVertex2f(0.75, 0.0);
	glEnd();

	glBegin(GL_TRIANGLES);
	glVertex2f(0.83, -0.05);
	glColor3f(1.8, 0.5, 0.0);
	glVertex2f(0.9, -0.09);
	glVertex2f(0.9, -0.01);
	glEnd();

	glBegin(GL_TRIANGLES);
	glColor3f(1.0, 1.0, 0.0);
	glVertex2f(0.79, -0.125);
	glVertex2f(0.77, -0.07);
	glVertex2f(0.75, -0.095);
	glEnd();

	glBegin(GL_TRIANGLES);
	glVertex2f(0.795, 0.035);
	glVertex2f(0.77, -0.02);
	glVertex2f(0.75, -0.007);
	glEnd();

	glColor3f(0.0, 0.0, 0.0);
	glPointSize(4.0);
	glBegin(GL_POINTS);
	glVertex2f(0.73, -0.035);
	glEnd();
	glPopMatrix();
}

void DrawFish4()
{
	glTranslatef(-500, 100, 0.0); 
	glScalef(250.0f, 250.0f, 0.0f);
	glTranslatef(fish4X, fish4Y, 0.0);
	glRotatef(180.0, 0.0, 1.0, 0.0);
	glPushMatrix();

	glColor3f(0.467, 0.533, 0.600);
	glBegin(GL_POLYGON);
	glVertex2f(0.7, -0.05);
	glVertex2f(0.75, -0.1);
	glVertex2f(0.85, -0.05);
	glVertex2f(0.75, 0.0);
	glEnd();

	glColor3f(0.863, 0.863, 0.863);
	glBegin(GL_TRIANGLES);
	glVertex2f(0.83, -0.05);
	glColor3f(0.412, 0.412, 0.412);
	glVertex2f(0.9, -0.09);
	glVertex2f(0.9, -0.01);
	glEnd();

	glColor3f(0.863, 0.863, 0.863);
	glBegin(GL_TRIANGLES);
	glVertex2f(0.79, -0.125);
	glVertex2f(0.77, -0.07);
	glVertex2f(0.75, -0.095);
	glEnd();

	glColor3f(0.863, 0.863, 0.863);
	glBegin(GL_TRIANGLES);
	glVertex2f(0.795, 0.035);
	glVertex2f(0.77, -0.02);
	glVertex2f(0.75, -0.007);
	glEnd();

	glPointSize(4.0);
	glBegin(GL_POINTS);
	glVertex2f(0.73, -0.035);
	glEnd();
	glPopMatrix();
}

void DrawFish5()
{
	glTranslatef(-900, 50, 0.0);
	glScalef(350.0f, 350.0f, 0.0f);
	glTranslatef(fish5X, fish5Y, 0.0);
	glRotatef(180.0, 0.0, 1.0, 0.0);
	glPushMatrix();

	glColor3f(1.0, 1.0, 0.0);
	glBegin(GL_POLYGON);
	glVertex2f(0.7, -0.05);
	glVertex2f(0.75, -0.1);
	glVertex2f(0.85, -0.05);
	glVertex2f(0.75, 0.0);
	glEnd();

	glColor3f(1.0, 1.0, 0.0);
	glBegin(GL_TRIANGLES);
	glVertex2f(0.83, -0.05);
	glColor3f(0.412, 0.412, 0.412);
	glVertex2f(0.9, -0.09);
	glVertex2f(0.9, -0.01);
	glEnd();

	glColor3f(1.0, 0.0, 0.0);
	glBegin(GL_TRIANGLES);
	glVertex2f(0.79, -0.125);
	glVertex2f(0.77, -0.07);
	glVertex2f(0.75, -0.095);
	glEnd();

	glColor3f(1.0, 0.0, 0.0);
	glBegin(GL_TRIANGLES);
	glVertex2f(0.795, 0.035);
	glVertex2f(0.77, -0.02);
	glVertex2f(0.75, -0.007);
	glEnd();

	glPointSize(4.0);
	glBegin(GL_POINTS);
	glVertex2f(0.73, -0.035);
	glEnd();
	glPopMatrix();
}

void DrawFish6()
{
	glTranslatef(-700, 50, 0.0);
	glScalef(350.0f, 350.0f, 0.0f);
	glTranslatef(fish6X, fish6Y, 0.0);
	glRotatef(180.0, 0.0, 1.0, 0.0);
	glPushMatrix();

	glColor3f(1.0, 0.0, 1.0);
	glBegin(GL_POLYGON);

	glVertex2f(0.7, -0.05);
	glVertex2f(0.75, -0.1);
	glVertex2f(0.85, -0.05);
	glVertex2f(0.75, 0.0);
	glEnd();

	glColor3f(1.0, 0.0, 1.0);
	glBegin(GL_TRIANGLES);
	glVertex2f(0.83, -0.05);
	glColor3f(0.412, 0.412, 0.412);
	glVertex2f(0.9, -0.09);
	glVertex2f(0.9, -0.01);
	glEnd();

	glColor3f(1.0, 0.0, 0.0);
	glBegin(GL_TRIANGLES);
	glVertex2f(0.79, -0.125);
	glVertex2f(0.77, -0.07);
	glVertex2f(0.75, -0.095);
	glEnd();

	glColor3f(1.0, 0.0, 0.0);
	glBegin(GL_TRIANGLES);
	glVertex2f(0.795, 0.035);
	glVertex2f(0.77, -0.02);
	glVertex2f(0.75, -0.007);
	glEnd();

	glPointSize(4.0);
	glBegin(GL_POINTS);
	glVertex2f(0.73, -0.035);
	glEnd();
	glPopMatrix();
}

void DrawFish7()
{
	glTranslatef(-500, 50, 0.0); 
	glScalef(250.0f, 250.0f, 0.0f);
	glTranslatef(fish7X, fish7Y, 0.0);
	glRotatef(180.0, 0.0, 1.0, 0.0);
	glPushMatrix();

	glColor3f(0.0, 1.0, 1.0);
	glBegin(GL_POLYGON);
	glVertex2f(0.7, -0.05);
	glVertex2f(0.75, -0.1);
	glVertex2f(0.85, -0.05);
	glVertex2f(0.75, 0.0);
	glEnd();

	glColor3f(0.0, 1.0, 1.0);
	glBegin(GL_TRIANGLES);
	glVertex2f(0.83, -0.05);
	glColor3f(0.412, 0.412, 0.412);
	glVertex2f(0.9, -0.09);
	glVertex2f(0.9, -0.01);
	glEnd();

	glColor3f(1.0, 0.0, 0.0);
	glBegin(GL_TRIANGLES);
	glVertex2f(0.79, -0.125);
	glVertex2f(0.77, -0.07);
	glVertex2f(0.75, -0.095);
	glEnd();

	glColor3f(1.0, 0.0, 0.0);
	glBegin(GL_TRIANGLES);
	glVertex2f(0.795, 0.035);
	glVertex2f(0.77, -0.02);
	glVertex2f(0.75, -0.007);
	glEnd();

	glPointSize(4.0);
	glBegin(GL_POINTS);
	glVertex2f(0.73, -0.035);
	glEnd();
	glPopMatrix();
}

void DrawFish8()
{
	glTranslatef(-500, 40, 0.0); 
	glScalef(250.0f, 250.0f, 0.0f);
	glTranslatef(fish8X, fish8Y, 0.0);
	glRotatef(180.0, 0.0, 1.0, 0.0);
	glPushMatrix();

	glColor3f(0.0, 1.0, 0.0);
	glBegin(GL_POLYGON);
	glVertex2f(0.7, -0.05);
	glVertex2f(0.75, -0.1);
	glVertex2f(0.85, -0.05);
	glVertex2f(0.75, 0.0);
	glEnd();

	glColor3f(0.0, 1.0, 0.0);
	glBegin(GL_TRIANGLES);
	glVertex2f(0.83, -0.05);
	glColor3f(0.412, 0.412, 0.412);
	glVertex2f(0.9, -0.09);
	glVertex2f(0.9, -0.01);
	glEnd();

	glColor3f(1.0, 0.0, 0.0);
	glBegin(GL_TRIANGLES);
	glVertex2f(0.79, -0.125);
	glVertex2f(0.77, -0.07);
	glVertex2f(0.75, -0.095);
	glEnd();

	glColor3f(1.0, 0.0, 0.0);
	glBegin(GL_TRIANGLES);
	glVertex2f(0.795, 0.035);
	glVertex2f(0.77, -0.02);
	glVertex2f(0.75, -0.007);
	glEnd();

	glPointSize(4.0);
	glBegin(GL_POINTS);
	glVertex2f(0.73, -0.035);
	glEnd();
	glPopMatrix();
}

void sun() {
	int n=13500, x=50, y=470, r=100;
	glColor3f(1.0, 1.0, 0.0);
	double inc = 2 * 3.1416 / (double)n;
	glBegin(GL_POLYGON);
	for (double theta = 0.0; theta <= 2 * 3.1416; theta += inc) {
		glVertex2f(r * cos(theta) + x, r * sin(theta) + y);
	}
	glEnd();
}

void ship()
{
	glScalef(18, 18, 0);
	glColor3f(0.5, 0.5, 0.5);

	glColor3f(0.5f, 0.35f, 0.05f);
	glBegin(GL_POLYGON);
	glVertex2f(ship_x + 1, ship_y + 5.5);
	glVertex2f(ship_x + 4, ship_y + 1);
	glVertex2f(ship_x + 19, ship_y + 1);
	glVertex2f(ship_x + 21.5, ship_y + 5.5);
	glEnd();

	glColor3f(1.0, 0.4, 0.0);
	glBegin(GL_LINE_LOOP);
	glVertex2f(ship_x + 1.5, ship_y + 5.5);
	glVertex2f(ship_x + 1.5, ship_y + 6.5);
	glVertex2f(ship_x + 2, ship_y + 6.2);
	glVertex2f(ship_x + 3, ship_y + 6.2);
	glVertex2f(ship_x + 3.5, ship_y + 6.5);
	glVertex2f(ship_x + 3.5, ship_y + 5.5);
	glEnd();

	glBegin(GL_LINE_LOOP);
	glVertex2f(ship_x + 3.5, ship_y + 5.5);
	glVertex2f(ship_x + 3.5, ship_y + 6.5);
	glVertex2f(ship_x + 4, ship_y + 6.2);
	glVertex2f(ship_x + 5, ship_y + 6.2);
	glVertex2f(ship_x + 5.5, ship_y + 6.5);
	glVertex2f(ship_x + 5.5, ship_y + 5.5);
	glEnd();

	glBegin(GL_LINE_LOOP);
	glVertex2f(ship_x + 5.5, ship_y + 5.5);
	glVertex2f(ship_x + 5.5, ship_y + 6.5);
	glVertex2f(ship_x + 6, ship_y + 6.2);
	glVertex2f(ship_x + 7, ship_y + 6.2);
	glVertex2f(ship_x + 7.5, ship_y + 6.5);
	glVertex2f(ship_x + 7.5, ship_y + 5.5);
	glEnd();

	glBegin(GL_LINE_LOOP);
	glVertex2f(ship_x + 7.5, ship_y + 5.5);
	glVertex2f(ship_x + 7.5, ship_y + 6.5);
	glVertex2f(ship_x + 8, ship_y + 6.2);
	glVertex2f(ship_x + 9, ship_y + 6.2);
	glVertex2f(ship_x + 9.5, ship_y + 6.5);
	glVertex2f(ship_x + 9.5, ship_y + 5.5);
	glEnd();

	glBegin(GL_LINE_LOOP);
	glVertex2f(ship_x + 9.5, ship_y + 5.5);
	glVertex2f(ship_x + 9.5, ship_y + 6.5);
	glVertex2f(ship_x + 10, ship_y + 6.2);
	glVertex2f(ship_x + 11, ship_y + 6.2);
	glVertex2f(ship_x + 11.5, ship_y + 6.5);
	glVertex2f(ship_x + 11.5, ship_y + 5.5);
	glEnd();

	glBegin(GL_LINE_LOOP);
	glVertex2f(ship_x + 11.5, ship_y + 5.5);
	glVertex2f(ship_x + 11.5, ship_y + 6.5);
	glVertex2f(ship_x + 12, ship_y + 6.2);
	glVertex2f(ship_x + 13, ship_y + 6.2);
	glVertex2f(ship_x + 13.5, ship_y + 6.5);
	glVertex2f(ship_x + 13.5, ship_y + 5.5);
	glEnd();

	glBegin(GL_LINE_LOOP);
	glVertex2f(ship_x + 13.5, ship_y + 5.5);
	glVertex2f(ship_x + 13.5, ship_y + 6.5);
	glVertex2f(ship_x + 14, ship_y + 6.2);
	glVertex2f(ship_x + 15, ship_y + 6.2);
	glVertex2f(ship_x + 15.5, ship_y + 6.5);
	glVertex2f(ship_x + 15.5, ship_y + 5.5);
	glEnd();

	glBegin(GL_LINE_LOOP);
	glVertex2f(ship_x + 15.5, ship_y + 5.5);
	glVertex2f(ship_x + 15.5, ship_y + 6.5);
	glVertex2f(ship_x + 16, ship_y + 6.2);
	glVertex2f(ship_x + 17, ship_y + 6.2);
	glVertex2f(ship_x + 17.5, ship_y + 6.5);
	glVertex2f(ship_x + 17.5, ship_y + 5.5);
	glEnd();

	glBegin(GL_LINE_LOOP);
	glVertex2f(ship_x + 17.5, ship_y + 5.5);
	glVertex2f(ship_x + 17.5, ship_y + 6.5);
	glVertex2f(ship_x + 18, ship_y + 6.2);
	glVertex2f(ship_x + 19, ship_y + 6.2);
	glVertex2f(ship_x + 19.5, ship_y + 6.5);
	glVertex2f(ship_x + 19.5, ship_y + 5.5);
	glEnd();

	glBegin(GL_LINE_LOOP);
	glVertex2f(ship_x + 19.5, ship_y + 5.5);
	glVertex2f(ship_x + 19.5, ship_y + 6.5);
	glVertex2f(ship_x + 20, ship_y + 6.2);
	glVertex2f(ship_x + 20.5, ship_y + 6.2);
	glVertex2f(ship_x + 21, ship_y + 6.5);
	glVertex2f(ship_x + 21, ship_y + 5.5);
	glEnd();

	glColor3f(1.0, 1.0, 1.0);
	glBegin(GL_LINE_LOOP);
	glVertex2f(ship_x + 4.5, ship_y + 3.5);
	glVertex2f(ship_x + 4.5, ship_y + 4.5);
	glVertex2f(ship_x + 5.5, ship_y + 4.5);
	glVertex2f(ship_x + 5.5, ship_y + 3.5);
	glEnd();

	glBegin(GL_LINE_LOOP);
	glVertex2f(ship_x + 7, ship_y + 3.5);
	glVertex2f(ship_x + 7, ship_y + 4.5);
	glVertex2f(ship_x + 8, ship_y + 4.5);
	glVertex2f(ship_x + 8, ship_y + 3.5);
	glEnd();

	glBegin(GL_LINE_LOOP);
	glVertex2f(ship_x + 9.5, ship_y + 3.5);
	glVertex2f(ship_x + 9.5, ship_y + 4.5);
	glVertex2f(ship_x + 10.5, ship_y + 4.5);
	glVertex2f(ship_x + 10.5, ship_y + 3.5);
	glEnd();

	glBegin(GL_LINE_LOOP);
	glVertex2f(ship_x + 12, ship_y + 3.5);
	glVertex2f(ship_x + 12, ship_y + 4.5);
	glVertex2f(ship_x + 13, ship_y + 4.5);
	glVertex2f(ship_x + 13, ship_y + 3.5);
	glEnd();


	glBegin(GL_LINE_LOOP);
	glVertex2f(ship_x + 14.5, ship_y + 3.5);
	glVertex2f(ship_x + 14.5, ship_y + 4.5);
	glVertex2f(ship_x + 15.5, ship_y + 4.5);
	glVertex2f(ship_x + 15.5, ship_y + 3.5);
	glEnd();

	glBegin(GL_LINE_LOOP);
	glVertex2f(ship_x + 17, ship_y + 3.5);
	glVertex2f(ship_x + 17, ship_y + 4.5);
	glVertex2f(ship_x + 18, ship_y + 4.5);
	glVertex2f(ship_x + 18, ship_y + 3.5);
	glEnd();

	glFlush();
}

void circle(int n, int x, int y, int r) {
	glColor3f(0.937, 0.878, 0.694);
	glScalef(0.85, 0.85, 0.0);
	glTranslatef(173.5f, 206.5f, 0.0);
	double inc = 2 * 3.1416 / (double)n;
	glBegin(GL_POLYGON);
	for (double theta = 0.0; theta <= 2 * 3.1416; theta += inc) {
		glVertex2f(r * cos(theta) + x + (ship_x * 21.2111), r * sin(theta) + y);
	}
	glEnd();
}

void man() {

	glTranslatef(23.0, 170.0, 0.0);
	glColor3f(1.0f, 1.0f, 1.0f);
	glScalef(10.0, 10.0, 0.0);

	// basen bölgesi
	glBegin(GL_POLYGON);
	glColor3f(1.0, 0.0, 0.0);
	glVertex2f(32.5f + (ship_x * 1.8), 8.0f);
	glVertex2f(32.0f + (ship_x * 1.8), 8.5f);
	glVertex2f(34.0f + (ship_x * 1.8), 8.5f);
	glVertex2f(33.5f + (ship_x * 1.8), 8.0f);
	glEnd();

	// gövde
	glBegin(GL_POLYGON);
	glColor3f(0.937, 0.878, 0.694);
	glVertex2f(32.0f + (ship_x * 1.8), 8.5f);
	glVertex2f(31.5f + (ship_x * 1.8), 9.0f);
	glVertex2f(31.0f + (ship_x * 1.8), 12.0f);
	glVertex2f(31.5f + (ship_x * 1.8), 12.5f);
	glVertex2f(34.5f + (ship_x * 1.8), 12.5f);
	glVertex2f(35.0f + (ship_x * 1.8), 12.0f);
	glVertex2f(34.5f + (ship_x * 1.8), 9.0f);
	glVertex2f(34.0f + (ship_x * 1.8), 8.5f);
	glEnd();

	//sol omuz
	glBegin(GL_TRIANGLES);
	glVertex2f(31.5f + (ship_x * 1.8), 12.5f);
	glVertex2f(31.0f + (ship_x * 1.8), 12.0f);
	glVertex2f(30.5f + (ship_x * 1.8), 12.5f);
	glEnd();

	//sað omuz
	glBegin(GL_TRIANGLES);
	glVertex2f(34.5f + (ship_x * 1.8), 12.5f);
	glVertex2f(35.0f + (ship_x * 1.8), 12.0f);
	glVertex2f(35.5f + (ship_x * 1.8), 12.5f);
	glEnd();

	//sol kol
	glBegin(GL_POLYGON);
	glColor3f(0.937, 0.878, 0.694);
	glVertex2f(31.0f + (ship_x * 1.8), 12.0f);
	glVertex2f(30.5f + (ship_x * 1.8), 12.5f);
	glVertex2f(29.0f + (ship_x * 1.8), 9.5f);
	glVertex2f(29.5f + (ship_x * 1.8), 9.0f);
	glEnd();

	//sað kol
	glBegin(GL_POLYGON);
	glColor3f(0.937, 0.878, 0.694);
	glVertex2f(35.0f + (ship_x * 1.8), 12.0f);
	glVertex2f(35.5f + (ship_x * 1.8), 12.5f);
	glVertex2f(37.0f + (ship_x * 1.8), 9.5f);
	glVertex2f(36.5f + (ship_x * 1.8), 9.5f);
	glEnd();

	// Sol bacak 
	glBegin(GL_POLYGON);
	glColor3f(0.937, 0.878, 0.694);
	glVertex2f(32.5f + (ship_x * 1.8), 8.0f);
	glVertex2f(32.0f + (ship_x * 1.8), 8.5f);
	glVertex2f(30.5f + (ship_x * 1.8), 3.5f);
	glVertex2f(31.0f + (ship_x * 1.8), 3.5f);
	glEnd();

	// Sað bacak 
	glBegin(GL_POLYGON);
	glColor3f(0.937, 0.878, 0.694);
	glVertex2f(33.5f + (ship_x * 1.8), 8.0f);
	glVertex2f(34.0f + (ship_x * 1.8), 8.5f);
	glVertex2f(35.5f + (ship_x * 1.8), 3.5f);
	glVertex2f(35.0f + (ship_x * 1.8), 3.5f);
	glEnd();

	//sað göz
	glPointSize(4.0);
	glColor3f(0.0, 0.0, 0.0);
	glBegin(GL_POINTS);
	glVertex2f(31.7f + (ship_x * 1.8), 15.5f);
	glEnd();

	//sol göz
	glPointSize(4.0);
	glColor3f(0.0, 0.0, 0.0);
	glBegin(GL_POINTS);
	glVertex2f(34.4f + (ship_x * 1.8), 15.5f);
	glEnd();
}

void update(int value) {
	if (fish1X < -3)
	{
		fish1X = 5.0f;
	}
	fish1X -= 0.01f;
	fish1Y = sin(fish1X * 2) / 8 + 0.8;
	if (fish1X < 0)
	{
		fish1Y* (-1);
	}
	if (fish2X > 7)
	{
		fish2X = 0;
	}
	fish2X += 0.008;
	fish2Y = sin(fish2X) / 10;
	if (fish2X < 10)
	{
		fish2Y *= (-1);
	}
	if (fish3X < -10)
	{
		fish3X = 1;
	}
	fish3X -= 0.015;
	fish3Y = sin(fish3X + 1.0) / 7 + 1.0;
	if (fish4X > 9)
	{
		fish4X = -1;
	}
	fish4X += 0.018;
	fish4Y = sin(fish4X) / 7 - 0.3;
	if (fish5X > 7)
	{
		fish5X = -0.9;
	}
	fish5X += 0.010;
	fish5Y = sin(fish5X) / 4;
	if (fish6X > 7)
	{
		fish6X = -1;
	}
	fish6X += 0.011;
	fish6Y = sin(fish6X + 0.5) / 5;
	if (fish6X < 90)
	{
		fish6Y *= (-1);
	}

	if (fish7X > 8)
	{
		fish7X = -1;
	}
	fish7X += 0.018;
	fish7Y = sin(fish7X + 0.5)/6;

	if (fish7X < 10)
	{
		fish7Y *= (-1);
	}

	if (fish8X > 8)
	{
		fish8X = -1;
	}
	fish8X += 0.018;
	fish8Y = sin(fish8X + 0.5) / 6;

	if (fish8X < 10)
	{
		fish8Y *= (-1);
	}

	glutPostRedisplay();
	glutTimerFunc(25, update, 0);
}

void hook() {
	glLineWidth(4.0);
	glTranslatef(-745.0, 150.0, 0.0);
	glColor3f(0.5f, 0.5f, 0.5f);
	glScalef(40.0, 40.0, 0.0);
	glBegin(GL_LINES);
	glVertex2f(26.5f + (ship_x / 2.22), 3.0f);
	glVertex2f(31.5f + (ship_x / 2.22), 5.0f);
	glEnd();

	glColor3f(0.0f, 0.0f, 0.0f);
	glLineWidth(3.0);
	glBegin(GL_LINES);
	glVertex2f(31.5f + (ship_x / 2.22), 5.0f);
	glVertex2f(31.5f + (ship_x / 2.22), 4.5f + hookLength);
	glEnd();

	glColor3f(0.0f, 0.0f, 0.0f);
	glLineWidth(3.0);
	glBegin(GL_LINE_STRIP);
	glVertex2f(31.5f + (ship_x / 2.22), 4.5f + hookLength);
	glVertex2f(31.5953744407249f + (ship_x / 2.22), 4.3931998091281f + hookLength);
	glVertex2f(31.6901701872822f + (ship_x / 2.22), 4.2916329378167f + hookLength);
	glVertex2f(31.6901701872822 + (ship_x / 2.22), 4.088499195194f + hookLength);
	glVertex2f(31.5993960713431f + (ship_x / 2.22), 4.0391662215094f + hookLength);
	glVertex2f(31.5f + (ship_x / 2.22), 4.0f + hookLength);
	glEnd();

}

void drawCloud(float x, float y, float radius)
{
	const int numCircles = 10;
	const float angleIncrement = 2.0f * 3.1416 / numCircles;
	const float minRadius = radius * 0.5f;
	const float maxRadius = radius * 1.5f;

	glColor3f(1.0f, 1.0f, 1.0f);

	for (int i = 0; i < numCircles; ++i)
	{
		const float angle = i * angleIncrement;
		const float xOffset = (minRadius + (maxRadius - minRadius) * (i / float(numCircles))) * cos(angle);
		const float yOffset = (minRadius + (maxRadius - minRadius) * (i / float(numCircles))) * sin(angle);
		const float cloudX = x + xOffset;
		const float cloudY = y + yOffset;

		glBegin(GL_TRIANGLE_FAN);
		glVertex2f(cloudX, cloudY);

		const int numSegments = 100;
		const float angleIncrementSegment = 2.0f * 3.1416 / numSegments;

		for (int j = 0; j <= numSegments; ++j)
		{
			const float segmentAngle = j * angleIncrementSegment;
			const float segmentX = cloudX + radius * cos(segmentAngle);
			const float segmentY = cloudY + radius * sin(segmentAngle);
			glVertex2f(segmentX, segmentY);
		}

		glEnd();
	}
}

void seaweed(float x, float y, float radius)
{
	const int numCircles = 10;
	const float angleIncrement = 2.0f * 3.1416 / numCircles;
	const float minRadius = radius * 0.5f;
	const float maxRadius = radius * 1.5f;

	glColor3f(0.0f, 0.7f, 0.0f); 

	for (int i = 0; i < numCircles; ++i)
	{
		const float angle = i * angleIncrement;
		const float xOffset = (minRadius + (maxRadius - minRadius) * (i / float(numCircles))) * cos(angle);
		const float yOffset = (minRadius + (maxRadius - minRadius) * (i / float(numCircles))) * sin(angle);
		const float cloudX = x + xOffset;
		const float cloudY = y + yOffset;

		glBegin(GL_TRIANGLE_FAN);
		glVertex2f(cloudX, cloudY); 

		const int numSegments = 100;
		const float angleIncrementSegment = 2.0f * 3.1416 / numSegments;

		for (int j = 0; j <= numSegments; ++j)
		{
			const float segmentAngle = j * angleIncrementSegment;
			const float segmentX = cloudX + radius * cos(segmentAngle);
			const float segmentY = cloudY + radius * sin(segmentAngle);
			glVertex2f(segmentX, segmentY);
		}

		glEnd();
	}
}

void display(void)
{
	glClear(GL_COLOR_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	glPushMatrix();
	circle(25, 240, 170, 30);
	glPopMatrix();

	glPushMatrix();
	man();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0, 70, 0.0);
	ship();
	glPopMatrix();

	glPushMatrix();
	sea();
	glPopMatrix();

	glPushMatrix();
	seaweed(900.0f, -155.0f, 17.0);
	seaweed(700.0f, -155.0f, 12.0);
	seaweed(500.0f, -155.0f, 17.0);
	seaweed(300.0f, -155.0f, 12.0);
	seaweed(100.0f, -155.0f, 20.0);
	glPopMatrix();

	glPushMatrix();
	sand();
	glPopMatrix();

	glPushMatrix();
	sun();
	glPopMatrix();

	glPushMatrix();
	DrawFish8();
	glPopMatrix();

	glPushMatrix();
	DrawFish2();
	glPopMatrix();

	glPushMatrix();
	DrawFish5();
	glPopMatrix();

	glPushMatrix();
	DrawFish6();
	glPopMatrix();

	glPushMatrix();
	DrawFish7();
	glPopMatrix();

	glPushMatrix();
	DrawFish4();
	glPopMatrix();

	glPushMatrix();
	DrawFish3();
	glPopMatrix();

	glPushMatrix();
	DrawFish1();
	glPopMatrix();

	glPushMatrix();
	hook();
	glPopMatrix();	

	glPushMatrix();
	drawCloud(900.0f, 455.0f, 30.0); // Bulutu çizmek için koordinatlarý ve yarýçap
	drawCloud(840.0f, 455.0f, 30.0);
	drawCloud(600.0f, 455.0f, 30.0); // Bulutu çizmek için koordinatlarý ve yarýçap
	drawCloud(540.0f, 455.0f, 30.0);
	glPopMatrix();

	glFlush();
	glutSwapBuffers();
}

void key(int key, int x, int y)
{
	switch (key)
	{
	case GLUT_KEY_LEFT:
		if (ship_x <= -3.0)
		{
			ship_x -= 0;
		}
		else
		{
			ship_x -= 2.0;
		}
		glutPostRedisplay();
		break;
	case GLUT_KEY_RIGHT:
		if (ship_x >= 35)
		{
			ship_x += 0;
		}
		else
		{
			ship_x += 2.0;
		}
		glutPostRedisplay();
		break;
	case GLUT_KEY_DOWN:
		if(hookLength>-12.5)
			hookLength -= hookSpeed;
		break;
	case GLUT_KEY_UP:
			if(hookLength<=-0.5)
			hookLength += hookSpeed;
		break;
		glutPostRedisplay();
	default:
		break;
	}
}

void init(void)
{
	glClearColor(0.1f, 0.9f, 0.9f, 0.1f);
	glColor3f(1.0, 0.0, 0.0);
	glPointSize(1.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0.0, 999.0, -200.0, 500.0);
}

int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);
	glutInitWindowSize(800, 600);
	glutInitWindowPosition(200, 100);
	glutCreateWindow("FÝSHÝNG");
	init();
	glutDisplayFunc(display);
	glutSpecialFunc(key);
	glutTimerFunc(25, update, 0);
	glutMainLoop();
	return 0;
}