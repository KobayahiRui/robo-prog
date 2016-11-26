#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<time.h>
double total=0;
int flg = 1,start=-1;
char mode,k,dummy,d,r;

void help(){
	printf("------help-------\n");
	printf("+:addition , -:subtraction\n");
	printf("*:multiplication , /:division\n");
	printf("\n[mode select operation]\n");
	printf("a : calculator mode\n");
	printf("f : function calculator mode\n");
	printf("p : power mode(累乗)\n");
	printf("h : help\n");
	printf("q : end\n");

	printf("\n[Calculator operation]\n");
	printf("[入力方法]\n");
	printf("5+3の場合　→　5[enter]+3[enter]\n");
	printf("(二回目以降)+8 →　+8[enter]\n");
	printf("\nf : function calculator mode\n");
	printf("p : power mode\n");
	printf("q : end\n");
	printf("R : result\n");
	printf("d : delete\n");
	printf("D : delete&mode select");
	printf("h : help\n");

	printf("\n[Function calculator operation]\n");
	printf("[入力方法]\n");
	printf("sin30+10の場合　→　s30[enter] +10[enter]\n");
	printf("(二回目以降)+cos60の場合　→　+c60[enter]\n");
	printf("\na ; calculator mode\n");
	printf("p : power mode\n");
	printf("q : end\n");
	printf("R : result\n");
	printf("d : delete\n");
	printf("s : sin\n");
	printf("c : cos\n");
	printf("t : tan\n");
	printf("S : asin #-1 to 1\n");
	printf("C : acos #-1 to 1\n");
	printf("T : atan\n");
	printf("r : square root\n");
	printf("l : natural logarithm\n");
	printf("L : lobarithm\n");
	printf("h : help\n");

	printf("\n[Power mode operation]\n");
	printf("[入力方法]\n");
	printf("5^2+2^2　→　5[enter]2[enter]+2[enter]2[enter]\n");
	printf("(二回目以降)+3^2 →  +3[enter]2[enter]\n");
	printf("\na:calculator mode\n");
	printf("f : function calculator mode\n");
	printf("p : power mode\n");
	printf("q : end\n");
	printf("R : result\n");
	printf("d : delete\n");
	printf("D : delete&mode select");
	printf("h : help\n");
}
void power(){
	double i=0,t,j=0,s=-1,a=0,u;
	char l;
	while(1){
		if(start==-1){
			k=' ';
			scanf(" %[^ahDqfRd+-*/1-9]",&dummy);
			scanf(" %1[^1-9]",&k);
		if(k=='q'){
			printf("end\n");
			exit(1);
		}else if(k=='f'){
		    	flg =0;
        	    	break;
		}else if(k=='a'){
			flg =1;
			mode='a';
			break;
		}else if(k=='R'){
			printf("result=> %g\n",total);
			if(start==-1){
				scanf("%lf",&a);
				total +=a;
			}
		}else if(k=='d'){
			printf("Delete\n");
			total=0;
			a=0;
			start =-1;
			continue;
		}else if(k=='D'){
			printf("Delete\n restart\n");
			total=0;
			a=0;
			start=-1;
			break;
		}else if(k=='h'){
			help();
			continue;
		}
		scanf("%lf",&a);
		printf("^");
		scanf("%lf",&u);
		a= pow(a,u);
		printf("=%g\n",a);
		total +=a;
		start*=0;
		}
		if(start!=-1){
			switch(k){
 				case '+':
		   			printf("\n%g + %g\n",total,a);
					total += a;
					printf("	= %g\n",total);
			   		break;
				case '-':
			   		printf("\n%g - %g\n",total,a);
			   		total -= a;
		   			printf("	= %g\n",total);
		   			break;
 				case '/':
		  		 	printf("\n%g / %g\n",total,a);
			   		if(a==0){
		    			printf("Erro\n");
		    	 		break;
		   			}
 		   			total /= a;
		   			printf("	= %g\n",total);
		   			break;
 				case'*':
		   			printf("\n%g * %g\n",total,a);
		   			total *= a;
		   			printf("	= %lf\n",total);
		   			break;
				default:
		   			break;
	    		}
		}
	scanf(" %[^ahDqfRd+-*/]",&dummy);
	scanf(" %c",&k);
	if(k=='q'){
		printf("end\n");
		exit(1);
	}else if(k=='f'){
	    	flg =0;
            	break;
	}else if(k=='a'){
		mode='a';
		flg =1;
		break;
	}else if(k=='R'){
		printf("result=> %g\n",total);
		if(start==-1){
			scanf("%lf",&a);
			total +=a;
		}
	}else if(k=='d'){
		printf("Delete\n");
		total=0;
		a=0;
		start =-1;
		continue;
	}else if(k=='D'){
		printf("Delete\n restart\n");
		total=0;
		a=0;
		start=-1;
		break;
	}else if(k=='h'){
		help();
		continue;
	}
	if(k!='R'&& k!='d'){
		scanf("%lf",&a);
		printf("^");
		scanf("%lf",&u);
		a = pow(a,u);
	}
	}
}


void cal(){
	double i=0,t,j=0,s=-1,a=0;
	char l;
	while(1){
		if(start==-1){
			k=' ';
			scanf(" %[^phDqfRd+-*/1-9]",&dummy);
			scanf(" %1[^1-9]",&k);
		if(k=='q'){
			printf("end\n");
			exit(1);
		}else if(k=='f'){
		    	flg =0;
        	    	break;
		}else if(k=='p'){
			flg=1;
			mode='p';
			break;
		}else if(k=='R'){
			printf("result=> %g\n",total);
			if(start==-1){
				scanf("%lf",&a);
				total +=a;
			}
		}else if(k=='d'){
			printf("Delete\n");
			total=0;
			a=0;
			start =-1;
			continue;
		}else if(k=='D'){
			printf("Delete\n restart\n");
			total=0;
			a=0;
			start=-1;
			break;
		}else if(k=='h'){
			help();
			continue;
		}
		scanf("%lf",&a);
		total +=a;
		start*=0;
		}
		if(start!=-1){
			switch(k){
 				case '+':
		   			printf("\n%g + %g\n",total,a);
					total += a;
					printf("	= %g\n",total);
			   		break;
				case '-':
			   		printf("\n%g - %g\n",total,a);
			   		total -= a;
		   			printf("	= %g\n",total);
		   			break;
 				case '/':
		  		 	printf("\n%g / %g\n",total,a);
			   		if(a==0){
		    			printf("Erro\n");
		    	 		break;
		   			}
 		   			total /= a;
		   			printf("	= %g\n",total);
		   			break;
 				case'*':
		   			printf("\n%g * %g\n",total,a);
		   			total *= a;
		   			printf("	= %g\n",total);
		   			break;
				default:
		   			break;
	    		}
		}
	scanf(" %[^phDqfRd+-*/]",&dummy);
	scanf(" %c",&k);
	if(k=='q'){
		printf("end\n");
		exit(1);
	else if(k=='f'){
	    	flg =0;
            	break;
	}else if(k=='p'){
		flg=1;
		mode='p';
		break;
	}else if(k=='R'){
		printf("result=> %g\n",total);
		if(start==-1){
			scanf("%lf",&a);
			total +=a;
		}
	}else if(k=='d'){
		printf("Delete\n");
		total=0;
		a=0;
		start =-1;
		continue;
	}else if(k=='D'){
		printf("Delete\n restart\n");
		total=0;
		a=0;
		start=-1;
		break;
	}else if(k=='h'){
		help();
		continue;
	}
	start*=0;
	if(k!='R'&& k!='d'){
		scanf("%lf",&a);
	}
	}
}


void func(){
	double d,rad,a=0,s=-1,p,ar;
	char kaijo,t,h,e,arc;
	while(1){
		char dammy=0;
		if(s==-1 && start!=-1){
			scanf("%[^pdDaqhR+-/*1]",&dummy);
			scanf(" %c",&k);
			if(k=='q'){
				printf("end\n");
				exit(1);
			}else if(k=='a'){
				flg=1;
				mode='a';
				break;
			}else if(k=='p'){
				flg=1;
				mode='p';
				break;
			}else if(k=='R'){
				s=-1;
				printf("result=> %g\n",total);
				continue;
			}else if(k=='h'){
				s=-1;
				help();
				continue;
			}else if(k=='d'){
				printf("Delete\n");
				total=0;
				a=0;
				start =-1;
				continue;
			}else if(k=='D'){
				printf("Delete\n restart\n");
				total=0;
				a=0;
				start=-1;
				break;
			}
		}	
		e='n';
		t='n';
		arc='n';
		ar=1;
		scanf(" %[^a-zA-z-+1-9]",&dammy);
		scanf(" %1[-+]",&e);//+-を調べる、ない場合nとなる
		if(e=='-') {
			p=-1;
		}else{
			p=1;
		}
		scanf(" %1[a-zA-Z]",&t);//文字のみ入る
		if(t=='q'){
			k='q';
			printf("end\n");
			exit(1);
		}else if(t=='a'){
			mode='a';
			flg=1;
			break;
		}else if(t=='p'){
			flg=1;
			mode='p';
			break;
		}else if(k=='p'){
			mode='p';
			flg=1;
			break;
		}else if(t=='R'){
			s=-1;
			printf("resulte=> %g\n",total);
			continue;
		}else if(t=='h'){
			s=-1;
			help();
			continue;
		}else if(t=='d'){
			printf("Delete\n");
			total=0;
			a=0;
			start =-1;
			continue;
		}else if(t=='D'){
			printf("Delete\n restart\n");
			total=0;
			a=0;
			start=-1;
			break;
		}
		scanf("%lf",&d);
		rad = d*M_PI/180;
		if(t=='s'){
			a=sin(rad);
		}else if(t=='c'){
			a=cos(rad);
		}else if(t=='t'){
			if((int)d%90==0 && (int)d/90%2==1){
				printf("Erorr\n");
				s=-1;
				continue;
			}
			a=tan(rad);
		}else if(t=='l'){
			if(d<=0){
				printf("Error\n");
				s=-1;
				continue;
			}
			a=log(d);
		}else if(t=='L'){
			if(d<=0){
				printf("Error\n");
				s=-1;
				continue;
			}
			a=log10(d);
		}else if(t=='S'){
			if(d<-1 || 1<d){
				printf("Error\n");
				s=-1;
				continue;
			}
			a=asin(d);
		}else if(t=='C'){
			if(d<-1 || 1<d){
				printf("Error\n");
				s=-1;
				continue;
			}
			a=acos(d);
		}else if(t=='T'){
			a=atan(d);
		}else if(t=='n'){
			a=d;
		}else if(t=='r'){
			if(d<0){
				printf("Error\n");
				s=-1;
				continue;
			}
			a=sqrt(d);
		}else{
			printf("Error\n");
			s=-1;
			continue;
		}
		a*=p;
		if(start==-1){
			total +=a;
		}
		switch(k){
			case '+':
				printf("\n%f + %f\n",total,a);
				total += a;
				printf("	= %g\n",total);
				break;
			case '-':
				printf("\n%g - %g\n",total,a);
				total -= a;
				printf("	= %g\n",total);
				break;
			case '/':
				if(a==0){
					printf("Error\n");
					break;
				}
				printf("\n%g / %g\n",total,a);
				total /=a;
				printf("	= %g\n",total);
				break;
			case'*':
				printf("\n%g * %g\n",total,a);
				total *=a;
				printf("	= %g\n",total);
				break;
			default:
				break;
		}
		start *=0;
		s *=0;
		scanf("%[^pdDaqhR+-/*]",&dummy);
		scanf(" %c",&k);
		if(k=='q'){
			printf("end\n");
			exit(1);
		}else if(k=='a'){
			mode='a';
			flg =1;
			break;
		}else if(k=='p'){
			mode='p';
			flg=1;
			break;
		}else if(k=='R'){
			s=-1;
			printf("result=> %g\n",total);
			continue;
		}else if(k=='h'){
			s=-1;
			help();
			continue;
		}else if(k=='d'){
			printf("Delete\n");
			total=0;
			a=0;
			start =-1;
			continue;
		}else if(k=='D'){
			printf("Delete\n restart\n");
			total=0;
			a=0;
			start=-1;
			break;
		}
	}
}


int main(){
	int condi;
	srand(time(NULL));
	condi = rand()%100;
	if(condi<40){
	printf("調子が悪いです。。\n");
	exit(1);
	}
	while(1){
	printf("mode selecti(操作方法はh-helpを入力)\n");
	scanf("%[^pafqh]",&dummy);//ダミーの変数、フィルター
	scanf(" %c",&mode);
	if(mode=='f'){
		flg=0;//fの場合　フラグを倒す
		break;
	}else if(mode=='a' || mode=='q' || mode=='p'){
		break;
	}else{
		help();
		continue;
	}
	}
	if(mode!='q'){
		while(1){
			if(flg){
				if(mode=='p'){   //flgのなかのmodeがpならpowermode aならcalculatormode
					printf("power mode\n");
					power();
				}else{
    					printf("calculator mode\n");
    					cal();
				}

			
			}else{
    				printf("function calculator mode\n");
    				func();
   			} 
			if(k=='D'){
				k='n';
				flg =1;
				while(1){
				printf("mode select\n");
				scanf("%[^pafqh]",&dummy);
				scanf(" %c",&mode);
				if(mode=='f'){
					flg=0;
					break;
				}else if(mode=='a'||mode=='q' ||mode=='p'){
					break;
				}else{
					help();
					continue;
				}
				}	
			}
			if(k=='q'||mode=='q'){
				printf("end\n");
			break;
			}
		}
	}else printf("end\n");
}
