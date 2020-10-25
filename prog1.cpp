#include<GL/glut.h>
#include<stdio.h>
#include<math.h>
void display(int x, int y)
{
	glBegin(GL_POINTS);
	glVertex2i(x, y);
	glEnd();
}
int X1[100], Y1[100], X2[100], Y2[100], t;

void draw_line()
{
	glClear(GL_COLOR_BUFFER_BIT);

	int dx, dy, i, e;
	int incx, incy, inc1, inc2;
	int x, y;
	for (int k = 0; k < t; k++)
	{
		dx = X2[k] - X1[k];
		dy = Y2[k] - Y1[k];

		if (dx < 0)
			dx = -dx;

		if (dy < 0)
			dy = -dy;

		incx = 1;

		if (X2[k] < X1[k])
			incx = -1;

		incy = 1;

		if (Y2[k] < Y1[k])
			incy = -1;

		x = X1[k];
		y = Y1[k];

		if (dx > dy)
		{

			display(x, y);

			e = 2 * dy - dx;
			inc1 = 2 * (dy - dx);
			inc2 = 2 * dy;
			for (i = 0; i < dx; i++)
			{
				if (e >= 0)
				{
					y += incy;
					e += inc1;
				}
				else
					e += inc2;
				x += incx;

				display(x, y);

			}
		}

		else
		{

			display(x, y);
			e = 2 * dy - dx;
			inc1 = 2 * (dy - dx);
			inc2 = 2 * dx;
			for (i = 0; i < dy; i++)
			{
				if (e >= 0)
				{
					x += incx;
					e += inc1;
				}
				else
					e += inc2;
				y += incy;

				display(x, y);

			}
		}
	}
	glFlush();
}
void minit()
{
	glClearColor(1, 1, 1, 1);
	glColor3f(1.0, 0.0, 0.0);
	glPointSize(3.0);
	gluOrtho2D(0, 500, 0, 500);
}
void main(int argc, char* argv[])
{
	printf_s("Enter number of lines:\n");
	scanf_s("%d", &t);
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(300, 300);
	glutInitWindowPosition(5, 5);
	glutCreateWindow("CSE");
	printf_s("Enter vertices:\n");
	for(int i=0;i<t;i++)
	scanf_s("%d%d%d%d", &X1[i], &Y1[i], &X2[i], &Y2[i]);
	glutDisplayFunc(draw_line);
	minit();
	glutMainLoop();
}