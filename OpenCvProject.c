
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <conio.h>
#include<locale.h>


#include <windows.h>
//#include <GL/freeglut.h>

#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glaux.h>
#include <GL/glut.h>

//Degisken tanimlamalarini yapiyoruz
double dx,dy;
double ax,ay,xa,ya;
double bx,by,xb,yb;
double cx,cy,xc,yc;
double a,b,c,x,y;
int i,j,k;
double derece,radyan,v,z;
int flag = 0;
double cisim_1[3][3];  
double cisim_2[3][3];  


// Girilen degelere gore olu?turulan ucgenin döndürme fonksiyonu 
void dogruyaGoreYansitmaIslemi(){
	   
	   
	   /* koordinat duzlemi*/
	   
	   glClearColor(0.0, 0.0, 0.0, 0.0);
     glMatrixMode(GL_PROJECTION);
     glLoadIdentity();
     
     glClear(GL_COLOR_BUFFER_BIT);
     glColor3f(1.0, 1.0, 1.0);
     glOrtho(-1.0, 1.0, -1.0, 1.0, -1.0, 1.0);
   
     glBegin(GL_POLYGON);
        glVertex2f(-0.005, -0.98);
        glVertex2f(0.005, -0.98);
        glVertex2f(0.005, 0.98);
        glVertex2f(-0.005, 0.98);
     glEnd();
     glFlush();

     glBegin(GL_POLYGON);
        glVertex2f(-0.98, -0.005);
        glVertex2f(-0.98, 0.005);
        glVertex2f(0.98, 0.005);
        glVertex2f(0.98, -0.005);
     glEnd();
     glFlush();
   
     glBegin(GL_POLYGON);
        glVertex2f(-1.0, 0.0);
        glVertex2f(-0.95, 0.02);
        glVertex2f(-0.97, 0.0);
        glVertex2f(-0.95, -0.02);
     glEnd();
     glFlush();

     glBegin(GL_POLYGON);
        glVertex2f(1.0, 0.0);
        glVertex2f(0.95, 0.02);
        glVertex2f(0.97, 0.0);
        glVertex2f(0.95, -0.02);
     glEnd();
     glFlush();

     glBegin(GL_POLYGON);
        glVertex2f(0.0, -1.0);
        glVertex2f(0.02, -0.95);
        glVertex2f(0.0, -0.97);
        glVertex2f(-0.02, -0.95);
     glEnd();
     glFlush();

     glBegin(GL_POLYGON);
        glVertex2f(0.0, 1.0);
        glVertex2f(0.02, 0.95);
        glVertex2f(0.0, 0.97);
        glVertex2f(-0.02, 0.95);
     glEnd();
     glFlush();
	   
	   
	   /* koordinat düzlemi */
	
	//Girilen degerlere gore olusturulan üçgenin kordinatlari ile matris olusturuyoruz 
	double  cisim_1[3][3] = { {ax, ay, 1}, {bx, by, 1}, {cx, cy, 1} };
	printf("cisim1\n");
	for(i=0;i<3;i++){
		for(j=0;j<3;j++){
			printf(" %f", cisim_1[i][j]);
  		}
  	printf("\n");
	}
	
	printf("****************************************************\n");

	const double PI = 3.14159265;
	y = c/a;
	x = c/b;
	derece = b/a;
	radyan = derece * (180/PI);
	
	double oteleme1_2[3][3];    
	double dondurme1_2[3][3];   
	double yansitma[3][3];     
	double dondurme2_1[3][3];  
	double oteleme2_1[3][3];   
	
	// Oteleme islemi icin bir matris tanimliyoruz 
	double oteleme[3][3] = { {1, 0, 0}, {0, 1, 0}, {x, 0, 1} };  
	printf("otelme\n");
	for(i=0;i<3;i++){
		for(j=0;j<3;j++){
			printf(" %f",oteleme[i][j]);
  		}
  	printf("\n");
	}
	printf("*********************************************************\n");
	
     // olusturulan ucgeni dogru fonksiyonuna gore oteliyoruz 
     //ve bu oteleme sonucunu oteleme adli matrise atiyoruz
	for(i=0;i<3;i++){
		for(j=0;j<3;j++){
			flag = 0;
			for(k=0;k<3;k++)
				flag+=cisim_1[i][k]*oteleme[k][j];		
		    oteleme1_2[i][j]=flag;
  }
}		
	printf("oteleme1_2\n");
	for(i=0;i<3;i++){
		for(j=0;j<3;j++){
			printf(" %f", oteleme1_2[i][j]);
  		}
  	printf("\n");
	}
	printf("*********************************************************\n");
     //Dondurme islemi icin bir matris tanimliyoruz
	double dondurme[3][3] = { {cos(radyan), -sin(radyan), 0}, {sin(radyan), cos(radyan), 0}, {0, 0, 1} }; 
	printf("radyan: %f",radyan);
	printf("sin(dereece): %f",sin(radyan));
	printf("cos(derece): %f",cos(radyan));
	printf("dondurme\n");
	for(i=0;i<3;i++){
		for(j=0;j<3;j++){
			printf(" %f",dondurme[i][j]);
  		}
  	printf("\n");
	}
	printf("***********************************************************\n");
     //olusturulan ucgeni dogru fonksiyonuna gore döndürüyoruz
     //ve bu döndürme islemini dondurme matrisine atiyoruz
	for(i=0;i<3;i++){
		for(j=0;j<3;j++){
			flag = 0;
			for(k=0;k<3;k++)
				flag+=oteleme1_2[i][k]*dondurme[k][j];		
		    dondurme1_2[i][j]=flag;
  }
}
	printf("döndürme1_2\n");
	for(i=0;i<3;i++){
		for(j=0;j<3;j++){
			printf(" %f",dondurme1_2[i][j]);
  		}
  	printf("\n");
	}
	printf("***********************************************************\n");
	//yansitma islemi icin matris tanimliyoruz
	double yansitmaIslemi[3][3] = { {1, 0, 0}, {0, -1, 0}, {0, 0, 1} };  
	printf("yansitme islemi\n");
	for(i=0;i<3;i++){
		for(j=0;j<3;j++){
			printf(" %f",yansitmaIslemi[i][j]);
  		}
  	printf("\n");
	}
	printf("***********************************************************\n");
	//Olusturulan üçgeni verilen dogru fonksiyonuna göre yansitiyoruz
	//ve bu islem sonucunda olusan matrisi yansitma matrisinin icine atiyoruz
	
	for(i=0;i<3;i++){
		for(j=0;j<3;j++){
			flag = 0;
			for(k=0;k<3;k++)
				flag+=dondurme1_2[i][k]*yansitmaIslemi[k][j];		
		    yansitma[i][j]=flag;
  }
}
	printf("yansitma \n");
	for(i=0;i<3;i++){
		for(j=0;j<3;j++){
			printf(" %f", yansitma[i][j]);
  		}
  	printf("\n");
	}
	printf("*****************************************************************\n");
	double dondurmeIslemi[3][3] = { {cos(radyan), sin(radyan), 0}, {-sin(radyan), cos(radyan), 0}, {0, 0, 1} }; 
	printf("Dondurme islemi \n");
	for(i=0;i<3;i++){
		for(j=0;j<3;j++){
			printf(" %f",dondurmeIslemi[i][j]);
  		}
  	printf("\n");
	}
	printf("*****************************************************************\n");
	//Olusturulan üçgeni verilen dogru fonksiyona göre döndürüyoruz
	//ve olusan matrisi dondurmeIslemi matrisi icine atiyoruz
	for(i=0;i<3;i++){
		for(j=0;j<3;j++){
			flag = 0;
			for(k=0;k<3;k++)
				flag+=yansitma[i][k]*dondurmeIslemi[k][j];		
		    oteleme2_1[i][j]=flag;
  }
}
	printf("dondurme2_1\n");
	for(i=0;i<3;i++){
		for(j=0;j<3;j++){
			printf(" %f",dondurme2_1[i][j]);
  		}
  	printf("\n");
	}
	printf("***************************************************************\n");
	double otelemeIslemi[3][3] = { {1, 0, 0}, {0, 1, 0}, {-x, 0, 1} };  
	printf("oteleme Islemi\n");
	for(i=0;i<3;i++){
		for(j=0;j<3;j++){
			printf(" %f",otelemeIslemi[i][j]);
  		}
  	printf("\n");
	}
	printf("***************************************************************\n");
	
	//Olusturulan üçgeni verilen dogru fonksiyonuna göre öteliyoruz 
	//olusan matrisi oteleme2_1 matrisine atyyoruz
	for(i=0;i<3;i++){
		for(j=0;j<3;j++){
			flag = 0;
			for(k=0;k<3;k++)
				flag+=dondurme2_1[i][k]*otelemeIslemi[k][j];		
		    oteleme2_1[i][j]=flag;
  }
}
	printf("oteleme2_1\n");
	for(i=0;i<3;i++){
		for(j=0;j<3;j++){
			printf(" %f",oteleme2_1[i][j]);
  		}
  	printf("\n");
	}

	printf("******************************************************************\n");
	for(i=0;i<3;i++){
		for(j=0;j<3;j++){
			cisim_2[i][j] = oteleme2_1[i][j];
  }
}
	printf("cisim2\n");
	for(i=0;i<3;i++){
		for(j=0;j<3;j++){
			printf(" %f",cisim_2[i][j]);
  		}
  	printf("\n");
	}
	printf("*************************************************************************\n");
	
	return cisim_2[3][3];
	
	dy = (100*b+c)/a;
	dx = (a*(-100)-c)/b;
	xa = cisim_2 [0][0];
	ya = cisim_2[0][1];
	
	xb = cisim_2 [1][0];
	yb = cisim_2 [1][1];
	
	xc = cisim_2 [2][0];
	yc = cisim_2 [2][1];
	
	return xa,ya,xb,yb,xc,yc,dy,dx;	 
	
}

struct BezierEgrisi{  
	double x;
	double y;
};
struct BezierEgrisi n_1;  
struct BezierEgrisi n_2;  
struct BezierEgrisi n_3;   

struct BezierEgrisi kontrolNoktasi(float u){  
	float gecicix,geciciy;   
	struct BezierEgrisi gecici;     
	gecicix=(n_1.x*u)+(n_2.x*2*u*(1-u))+(n_3.x*(pow(u,2)));
	geciciy=(n_1.y*u)+(n_2.y*2*u*(1-u))+(n_3.y*(pow(u,2)));
	gecici.x=gecicix;
	gecici.y=geciciy;
	
	return (gecici);
	
}

void display(void){
	glClear(GL_COLOR_BUFFER_BIT);
	
	glColor3f(0.0,0.1,1.0);
	glBegin(GL_POLYGON);
		glVertex2f(ax,ay);
		glVertex2f(bx,by);
		glVertex2f(cx,cy);
	glEnd();
	
	
	glColor3f(0.0,0.1,1.0);
	float j=0;
	glBegin(GL_LINES);
		glVertex2i(100,dy);
		glVertex2i(dx,-100);
	glColor3f(0.0,1.0,1.0);
	
	struct BezierEgrisi Kontrol;   
	for(j=0;j<=1.05;j+=0.05){
	Kontrol=kontrolNoktasi(j);
		glVertex3f(Kontrol.x,Kontrol.y,1);
	}
	glEnd();
	
	//yansyma islemi sonucunda ki ucgen
	glColor3f(0.0,0.1,1.0);
	glBegin(GL_POLYGON);
		glVertex2f(xa,ya);
		glVertex2f(xb,yb);
		glVertex2f(xc,yc);
	glEnd();
	
	glFlush();
}
	

int main(int argc, char *argv[]) {
	
	 glutInit(&argc, argv);
     glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH);
     glutInitWindowSize(500,500);
     glutInitWindowPosition(100,100);
     glutCreateWindow("Buket");
	
	setlocale(LC_ALL, "Turkish");

	printf("a noktasi için x degerini giriniz: ");  
	scanf("%lf",&ax);
	printf("a noktasi için y degerini giriniz: "); 
	scanf("%lf",&ay);
	
	printf("b noktasi için x degerini giriniz: ");
	scanf("%lf",&bx);
	printf("b noktasi için y degerini giriniz: ");
	scanf("%lf",&by);
	
	printf("c noktasi için x degerini giriniz: ");
	scanf("%lf",&cx);
	printf("c noktasi için y degerini giriniz: ");
	scanf("%lf",&cy);
	
	
	printf("Dogru fonksiyonu için gerekli degerleri giriniz \n");
	printf("ay=bx+c \n");
	printf("a:");
	scanf("%lf",&a);
	printf("b:");
	scanf("%lf",&b);
	printf("c:");
	scanf("%lf",&c);

	 glutDisplayFunc(display);
	 glutDisplayFunc(dogruyaGoreYansitmaIslemi);
	
	 
	  glutMainLoop();
	  return 0;

glutMainLoop();
	
}




