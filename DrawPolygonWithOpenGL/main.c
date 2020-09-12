#include <windows.h>
#include <gl/glut.h>

int x1, y1, x2, y2;

typedef struct{

    int a;
    int b;


}polygon;

void myInit() {
	glClear(GL_COLOR_BUFFER_BIT);
	glClearColor(0.0, 0.0, 0.0, 1.0);
	glMatrixMode(GL_PROJECTION);
	gluOrtho2D(0, 500, 0, 500);
}

void draw_pixel(int x, int y) {
	glBegin(GL_POINTS);
	glVertex2i(x, y);
	glEnd();
}

void draw_line(int x1, int x2, int y1, int y2) {
	int dx, dy, i, e;
	int incx, incy, inc1, inc2;
	int x,y;

	dx = x2-x1;
	dy = y2-y1;
//abs(x2-x1)

	if (dx < 0)dx = -dx;
    if (dy < 0) dy = -dy;
    incx = 1;
    if (x2 < x1) incx = -1;
    incy = 1;
	if (y2 < y1) incy = -1;
	x = x1; y = y1;
	if (dx > dy) {
		draw_pixel(x, y);
		e = 2 * dy-dx;
		inc1 = 2*(dy-dx);
		inc2 = 2*dy;
		for (i=0; i<dx; i++) {
			if (e >= 0) {
				y += incy;
				e += inc1;
			}
			else
				e += inc2;
			x += incx;
			draw_pixel(x, y);
		}

	} else {
		draw_pixel(x, y);
		e = 2*dx-dy;
		inc1 = 2*(dx-dy);
		inc2 = 2*dx;
		for (i=0; i<dy; i++) {
			if (e >= 0) {
				x += incx;
				e += inc1;
			}
			else
				e += inc2;
			y += incy;
			draw_pixel(x, y);
		}
	}
}



void myDisplay() {
	draw_line(x1, x2, y1, y2);
	glFlush();
}


void polygonn(){

    int m,n;
    int count;

    printf("enter the number of ...");
    scanf("%d ", &count);

    polygon p[count];
    for(m=0;m<count;m++){

        scanf("%d",&p[m].a);
        scanf("%d",&p[m].b);
    }

    for(n=0;n<count-1;n++){

        draw_line(p[n].a,p[n].b,p[n+1].a,p[n+1].b);
    }

     draw_line(p[n].a,p[n].b,p[0].a,p[0].b);

}



void main(int argc, char **argv) {





	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
	glutInitWindowSize(500, 500);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("Bresenham's Line Drawing");
	myInit();
	polygonn();
	glutDisplayFunc(myDisplay);
	glutMainLoop();
}
