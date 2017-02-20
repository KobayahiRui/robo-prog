#include <GL/glut.h>
#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#define Win 600
static double g=-9.806;//$B=ENO(B
static double t=1;//$B<B9T%9%T!<%I(B
static double T=1;//$B%U%l!<%`%9%T!<%I(B
static double e=0.7;//$BH?H/78?t(B
static double n=0.1;
double ww=0,w=-10;

//$B1_$N:n@.$KBP$9$k9=B$BN(B
struct serdate {
	double r;//$BH>7B(B
	double x1,y1; //$BCf?4:BI8(B
	double vl1,vr1; //$BB.$5(B($B=D!K(B,($B2#!K(B
	double m;
};

//$B;M3Q7A$N:n@.(B
struct boxdate {
	double x2,y2;//$B;M3Q7A$N:82<$N3Q$N:BI8(B
	double l1,r1; //$B;M3Q7A$NJU$ND9$5(B($B=D(B),($B2#(B)
};

//$B@~$N:n@.(B
struct linedate {
	double x3,y3;//$B;OE@(B
	double x3_2,y3_2;//$B=*E@(B
};

//$BB-$N:n@.(B
struct futdata {
	double x4,y4;//$B2sE><4(B
	double l2,r2;//$BB-$ND9$5!"B-$NB@$5(B
	double h1,k1;//$BB-<s$^$G$N9b$5!"B-$N9C$ND9$5(B
};

//-----------------------------------------------$BIA2h4X?t(B
//$B1_$NIA2h(B
void ser(double R,double xo ,double yo){
	double x,y;
	glBegin(GL_POLYGON);
	for(x=-R+xo;x<R+xo;x+=0.0001){
		y=sqrt(R*R-((x-xo)*(x-xo)))+yo;
	 	glVertex2d(x,y);
	}
	for(x=R+xo;x>-R+xo;x-=0.0001){
		y=-(sqrt(R*R-(x-xo)*(x-xo)))+yo;
		glVertex2d(x,y);}
	glEnd();
}

//$B@~$NIA2h(B
void line(double xx1,double yy1,double xx2,double yy2){
	glBegin(GL_LINE_LOOP);
	glColor3f(0.0,1,0);
	//glLineWidth(1);
	glVertex2d(xx1,yy1);
	glVertex2d(xx2,yy2);
	glEnd();
}

//$B;M3Q7A$NIA2h(B
void box(double xx1,double yy1,double ll1,double rr1){
//x1,y1$B$O;M3Q$N:8C<$N:BI8!!(Bl1:$B=D$ND9$5!!(Br1:$B2#$ND9$5(B
	//glPushMatrix();
	glColor3f(0.0,0.0,1);
	glRectf(xx1,yy1,xx1+rr1,yy1+ll1);
	//glPopMatrix();
}

//$BB-$NIA2h(B
void fut(double xx1,double yy1,double ll1,double rr1,double hh1,double kk1){
// $BB-$N2sE><4$N:BI8!"B-$ND9$5!"B-$NB@$5!"B-<s$^$G$N9b$5!"B-$N9C$ND9$5(B
double xf,yf,rf;
box(xx1-(rr1/2),yy1-ll1,ll1,rr1);
box(xx1-(rr1/2)-kk1,yy1-ll1,hh1,kk1);
ser(rr1/2,xx1,yy1);
}
//--------------------------------------------------------------------$B7W;;7O(B

//$B2sE>8e$N:BI87W;;(B(x$B:BI8(B)
double  matrix_x(double xx1,double yy1,double xx2,double yy2,double rol){
//$B2sE>$N<4:BI8!"2sE>8e$N:BI8$,CN$j$?$$:BI8(B,$B2sE>$7$?3QEY(B(degree)
double rol2=rol*M_PI/180; //rad$B$KJQ49(B
double xx2_2;//$B2sE>8e$N(Bx$B:BI8(B
xx2_2=(xx2-xx1)*cos(rol2)+(yy2-yy1)*-sin(rol2)+xx1;
return xx2_2;
}

//$B2sE>8e$N:BI87W;;(B(y$B:BI8(B)
double matrix_y(double xx1,double yy1,double xx2,double yy2,double rol){
double rol2=rol*M_PI/180;
double yy2_2;
yy2_2=(xx2-xx1)*sin(rol2)+(yy2-yy1)*cos(rol2)+yy1;
return yy2_2;
}

double data[3];//$BB-@h$N%\!<%k$NEv$?$jH=Dj(B
void  futball(double xx1,double yy1,double ll1,double rr1,double hh1,double kk1){
 
 data[0]=xx1-(rr1/2)-(kk1/2);
 data[1]=yy1-ll1+(hh1/2);
 data[2]=sqrt(((kk1/2)*(kk1/2))+((hh1/2)*(hh1/2)));
}

double pita(double xx1,double yy1,double xx2,double yy2){
	double L;
	L=sqrt((xx1-xx2)*(xx1-xx2)+(yy1-yy2)*(yy1-yy2));
	return L;
}
//----------------------------------------------------------------$BJ*BN$N%G!<%?(B
struct serdate ball1={22,400,400,0,-20,1};//$B%\!<%k$N%G!<%?(B

struct linedate frame[4]={		//$B30OH$N%G!<%?(B
	{0,0,Win,0},
	{Win,0,Win,Win},
	{Win,Win,0,Win},
	{0,Win,0,0},
};

struct futdata fut1={110,300,200,20,20,20};//$BB-$N%G!<%?(B
//$BB-$N;M3Q7A:82<$N:BI8(B(fut1.x1-(fut1.r1/2),fut1.y1-fut1.l1)
//$BB-$N9C$NItJ,$N!7!!!!(B(fut1.x1-(fut1.r1/2)-fut1.k1,fut1.y1-fut1.l1)
//---------------------------------------------------------------

int fc=1;//f$B%-!<$NH=Dj(B

void display(void){
double xx1,yy1,xx2,yy2,xx3,yy3,l;
double futlow1[2]={fut1.x4,fut1.y4-fut1.l2};
double futlow2[2]={fut1.x4-(fut1.r2/2)-(fut1.k1/2),fut1.y4-fut1.l2};
int i;
	glClear(GL_COLOR_BUFFER_BIT);
//-----------------------------------$B30OH$N:n@.(B
for(i=0;i<4;i++){
	line(frame[i].x3,frame[i].y3,frame[i].x3_2,frame[i].y3_2);

}
//-----------------------------------$BB-$N2sE>(B
	glPushMatrix();
	glTranslatef(fut1.x4,fut1.y4,0);
	glRotatef(ww,0,0,1);
	glTranslatef(-fut1.x4,-fut1.y4,0);
	fut(fut1.x4,fut1.y4,fut1.l2,fut1.r2,fut1.h1,fut1.k1);
	futball(fut1.x4,fut1.y4,fut1.l2,fut1.r2,fut1.h1,fut1.k1);
	glPopMatrix();
//-----------------------------------$B%\!<%k$NIA2h(B
	glColor3f(1.0f,1.0f,0.0f);
	ser(ball1.r,ball1.x1,ball1.y1);
	glFlush();
	glutSwapBuffers();
//---------------------------------------------------$B7W;;(B
	xx1=matrix_x(fut1.x4,fut1.y4,data[0],data[1],ww);
	yy1=matrix_y(fut1.x4,fut1.y4,data[0],data[1],ww);
	l=sqrt((xx1-ball1.x1)*(xx1-ball1.x1)+(yy1-ball1.y1)*(yy1-ball1.y1)); 

//------------------------------------------$B%\!<%k$N0\F0(B
	ball1.vl1+=g*t;
	ball1.y1+=ball1.vl1*t;
//------------------------------------------$BB-$H%\!<%k$NEv$?$jH=Dj(B
	if(l<(ball1.r+data[2])&&fc==1){
		ball1.vr1+=fabs(cos(ww))*fut1.l2*w*0.1;
		ball1.vl1+=fabs(sin(ww))*fut1.l2*w*0.1;
		if(w==0&&ball1.x1<=xx1){
		ball1.vr1=-fabs(cos(ww))*fut1.l2*0.1;
		ball1.vl1=-fabs(sin(ww))*fut1.l2*0.1;
		}else if(w==0&&ball1.x1>xx1){
		ball1.vr1+=fabs(cos(ww))*fut1.l2*0.1;
		ball1.vl1+=fabs(sin(ww))*fut1.l2*0.1;
		}
	}

//------------------------------$BK`;$(B
	if(ball1.y1-ball1.r<=0){
		if(ball1.vr1>0){
			ball1.vr1-=n*-g*t;
			if(ball1.vr1<=0){
				ball1.vr1=0;
			}
		}else if(ball1.vr1<0){
			ball1.vr1+=n*-g*t;
			if(ball1.vr1>=0){
				ball1.vr1=0;
			}
		}
	}
//----------------------------------$B>WFMH=Dj(B($B%\!<%k$HJI!K(B
	if(ball1.y1-ball1.r<0){
		ball1.y1=ball1.r;
		ball1.vl1*=-1*e;
	}else if(ball1.y1+ball1.r>Win){
		ball1.y1=Win-ball1.r;
		ball1.vl1*=-1*e;
	}
	ball1.x1+=ball1.vr1*t;
	if(ball1.x1-ball1.r<0){
		ball1.x1=ball1.r;
		ball1.vr1*=-1*e;
	}else if(ball1.x1+ball1.r>Win){
		ball1.x1=Win-ball1.r;
		ball1.vr1*=-1*e;
	}
//--------------------------------$B2sE>$N%j%;%C%H(B
	ww+=w;
	if(ww==-360){
		ww=0;}
}


void timer(int value){
	glutPostRedisplay();
	glutTimerFunc(T,timer,0);
}

	int flg1=1;
	double wdata;

void keyboard(unsigned char key, int x, int y){
		switch(key){
				case'w':			//$B>eJ}8~(B
					fut1.y4+=5;
					break;
				case'd':			//$B1&J}8~(B
					fut1.x4+=5;
					break;
				case's':			//$B2<J}8~(B
					fut1.y4-=5;
					break;
				case'a':			//$B:8J}8~(B
					fut1.x4-=5;
					break;
				case'f':			//$B:F@8!"Dd;_(B
					if(flg1==1){
						wdata=w;
						w=0;
						flg1=0;
						fc=0;
					}else if(flg1==0){ 
						w=wdata;
						flg1=1;
						fc=1;
					}
					break;
		}
}

void specialkeydown(int key, int x, int y){
	if(key==GLUT_KEY_UP){			//up$B%-!<!'H?;~7W2s$j$N2sE>B.EY%"%C%W(B($B;~7W2s$j$N8:B.(B)
		w-=5;
		printf("#%lf\r",w);
	}
	if(key==GLUT_KEY_DOWN){			//down$B%-!<!';~7W2s$j$N2sE>B.EY%"%C%W!JH?;~7W2s$j$N8:B.(B)
		w+=5;
		printf("#%lf\r",w);
	}
}


void init(void)
{
	glClearColor(0.0, 0.0, 0.0, 0.0);
}

void reshape(int w, int h)
{
	glViewport( 0, 0, w, h );
	glOrtho(0, Win, 0, Win, -1.0, 1.0);
}

int main(int argc, char *argv[]){
	clock_t start,end;
	int i;
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowSize (Win, Win);
	glutInitWindowPosition(100,100);
	glutCreateWindow(argv[0]);
	init();
	glutReshapeFunc(reshape);
	glutDisplayFunc(display);
	glutKeyboardFunc(keyboard);
	glutSpecialFunc(specialkeydown);
	glutTimerFunc(T,timer,0);
	glutMainLoop();
	return 0;
}
