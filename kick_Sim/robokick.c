#include <GL/glut.h>
#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#define Win 600
static double g=-9.806;//重力
static double t=1;//実行スピード
static double T=1;//フレームスピード
static double e=0.7;//反発係数
static double n=0.1;
double ww=0,w=-10;

//円の作成に対する構造体
struct serdate {
	double r;//半径
	double x1,y1; //中心座標
	double vl1,vr1; //速さ(縦）,(横）
	double m;
};

//四角形の作成
struct boxdate {
	double x2,y2;//四角形の左下の角の座標
	double l1,r1; //四角形の辺の長さ(縦),(横)
};

//線の作成
struct linedate {
	double x3,y3;//始点
	double x3_2,y3_2;//終点
};

//足の作成
struct futdata {
	double x4,y4;//回転軸
	double l2,r2;//足の長さ、足の太さ
	double h1,k1;//足首までの高さ、足の甲の長さ
};

//-----------------------------------------------描画関数
//円の描画
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

//線の描画
void line(double xx1,double yy1,double xx2,double yy2){
	glBegin(GL_LINE_LOOP);
	glColor3f(0.0,1,0);
	//glLineWidth(1);
	glVertex2d(xx1,yy1);
	glVertex2d(xx2,yy2);
	glEnd();
}

//四角形の描画
void box(double xx1,double yy1,double ll1,double rr1){
//x1,y1は四角の左端の座標　l1:縦の長さ　r1:横の長さ
	//glPushMatrix();
	glColor3f(0.0,0.0,1);
	glRectf(xx1,yy1,xx1+rr1,yy1+ll1);
	//glPopMatrix();
}

//足の描画
void fut(double xx1,double yy1,double ll1,double rr1,double hh1,double kk1){
// 足の回転軸の座標、足の長さ、足の太さ、足首までの高さ、足の甲の長さ
double xf,yf,rf;
box(xx1-(rr1/2),yy1-ll1,ll1,rr1);
box(xx1-(rr1/2)-kk1,yy1-ll1,hh1,kk1);
ser(rr1/2,xx1,yy1);
}
//--------------------------------------------------------------------計算系

//回転後の座標計算(x座標)
double  matrix_x(double xx1,double yy1,double xx2,double yy2,double rol){
//回転の軸座標、回転後の座標が知りたい座標,回転した角度(degree)
double rol2=rol*M_PI/180; //radに変換
double xx2_2;//回転後のx座標
xx2_2=(xx2-xx1)*cos(rol2)+(yy2-yy1)*-sin(rol2)+xx1;
return xx2_2;
}

//回転後の座標計算(y座標)
double matrix_y(double xx1,double yy1,double xx2,double yy2,double rol){
double rol2=rol*M_PI/180;
double yy2_2;
yy2_2=(xx2-xx1)*sin(rol2)+(yy2-yy1)*cos(rol2)+yy1;
return yy2_2;
}

double data[3];//足先のボールの当たり判定
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
//----------------------------------------------------------------物体のデータ
struct serdate ball1={22,400,400,0,-20,1};//ボールのデータ

struct linedate frame[4]={		//外枠のデータ
	{0,0,Win,0},
	{Win,0,Win,Win},
	{Win,Win,0,Win},
	{0,Win,0,0},
};

struct futdata fut1={110,300,200,20,20,20};//足のデータ
//足の四角形左下の座標(fut1.x1-(fut1.r1/2),fut1.y1-fut1.l1)
//足の甲の部分の〃　　(fut1.x1-(fut1.r1/2)-fut1.k1,fut1.y1-fut1.l1)
//---------------------------------------------------------------

int fc=1;//fキーの判定

void display(void){
double xx1,yy1,xx2,yy2,xx3,yy3,l;
double futlow1[2]={fut1.x4,fut1.y4-fut1.l2};
double futlow2[2]={fut1.x4-(fut1.r2/2)-(fut1.k1/2),fut1.y4-fut1.l2};
int i;
	glClear(GL_COLOR_BUFFER_BIT);
//-----------------------------------外枠の作成
for(i=0;i<4;i++){
	line(frame[i].x3,frame[i].y3,frame[i].x3_2,frame[i].y3_2);

}
//-----------------------------------足の回転
	glPushMatrix();
	glTranslatef(fut1.x4,fut1.y4,0);
	glRotatef(ww,0,0,1);
	glTranslatef(-fut1.x4,-fut1.y4,0);
	fut(fut1.x4,fut1.y4,fut1.l2,fut1.r2,fut1.h1,fut1.k1);
	futball(fut1.x4,fut1.y4,fut1.l2,fut1.r2,fut1.h1,fut1.k1);
	glPopMatrix();
//-----------------------------------ボールの描画
	glColor3f(1.0f,1.0f,0.0f);
	ser(ball1.r,ball1.x1,ball1.y1);
	glFlush();
	glutSwapBuffers();
//---------------------------------------------------計算
	xx1=matrix_x(fut1.x4,fut1.y4,data[0],data[1],ww);
	yy1=matrix_y(fut1.x4,fut1.y4,data[0],data[1],ww);
	l=sqrt((xx1-ball1.x1)*(xx1-ball1.x1)+(yy1-ball1.y1)*(yy1-ball1.y1)); 

//------------------------------------------ボールの移動
	ball1.vl1+=g*t;
	ball1.y1+=ball1.vl1*t;
//------------------------------------------足とボールの当たり判定
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

//------------------------------摩擦
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
//----------------------------------衝突判定(ボールと壁）
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
//--------------------------------回転のリセット
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
				case'w':			//上方向
					fut1.y4+=5;
					break;
				case'd':			//右方向
					fut1.x4+=5;
					break;
				case's':			//下方向
					fut1.y4-=5;
					break;
				case'a':			//左方向
					fut1.x4-=5;
					break;
				case'f':			//再生、停止
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
	if(key==GLUT_KEY_UP){			//upキー：反時計回りの回転速度アップ(時計回りの減速)
		w-=5;
		printf("#%lf\r",w);
	}
	if(key==GLUT_KEY_DOWN){			//downキー：時計回りの回転速度アップ（反時計回りの減速)
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
