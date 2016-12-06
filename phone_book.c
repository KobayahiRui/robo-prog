#include<stdio.h>
#include<string.h>
#include<stdlib.h>

FILE *fp,*fp2;
struct person{
	char id[15];//ID
	char name[50];//名前
	long int phone;//電話番号
	char address[256];//アドレス
};

void help(){
	printf("mode command list-------------------------------------\n");
	printf("Registration\t: r\nSearch\t\t: s\nIDserch\t\t: i\nIDdelete\t: d\nnamedelete\t: D\n");
	printf("list\t\t: l\nclear\t\t: c\npasswordchange\t: p\nend\t\t: q\ntrash can list\t: t\ntrash can clear\t: C\nreborn\t\t: R\n");
	printf("-----------------------------------------------------\n");
}


void Regi(){                    //登録モード
	fp = fopen("data.txt","a");
	char ser[50],dummy;
	int i,top[50],pp;
	long int y[50],e[50];

	printf("How many people??\n");
	scanf(" %d",&pp);
	struct person data[pp];	
	for(i=0;i<pp;i++){
		printf("No.%d\n",i+1);
		printf("ID --> ");
		scanf("%s",data[i].id);
		printf("name --> ");
		scanf(" %50[^\n]",data[i].name);
		printf("phone number --> ");
		scanf(" %1d%ld",&top[i],&data[i].phone);
		printf("address --> ");
		scanf("%s",data[i].address);
	}
	printf("\nRegistered--------------------------------------------\n");
	for(i=0;i<pp;i++){
			printf("ID: %s//name: %s//phone-number: %d%ld//address: %s\n",data[i].id ,data[i].name ,top[i],data[i].phone,data[i].address);
			fprintf(fp,"ID: %s//name: %s//phone-number: %d%ld//address: %s\n",data[i].id,data[i].name,top[i] ,data[i].phone,data[i].address);
			
	}
	printf("------------------------------------------------------\n");
	fclose(fp);
}


void Ser(){			//検索モード
	char ser[50],name[50][50],add[50][50],l[50][15];
	int c=0,t,n,fid=0,top2[50],pp;
	long int e[50];

	fp = fopen("data.txt","r");
	printf("serch\n");
	scanf(" %50[^\n]",ser);
	while((fscanf(fp,"%*s %[^\n/]//%*s %[^\n/]//%*s %1d%ld//%*s %s",l[c],name[c],&top2[c],&e[c],add[c]))!=EOF){
		c++;
	}
	for(t=0;t<=c;t++){
		if(!strcmp(name[t],ser)){
			printf("found!!\n");
			fid=1;
			break;
		}
	}
	if(fid){
		printf("------------------------------------------------------\n");
		printf("ID: %s\n",l[t]);
		printf("name: %s\n",name[t]);
		printf("phone-number: %d%ld\n",top2[t],e[t]);
		printf("address: %s\n",add[t]); 
		printf("------------------------------------------------------\n");
	}else{
		printf("not found...\n");
	}
	fclose(fp);
}


void IDser(){			//ID検索モード
	char name[50][50],add[50][50],ids[15],l[50][15];
	int c=0,t,n,fid=0,top2[50],pp;
	long int e[50];

	fp = fopen("data.txt","r");
	printf("serch\n");
	scanf(" %s",ids);
	while((fscanf(fp,"%*s %[^\n/]//%*s %[^\n/]//%*s %1d%ld//%*s %s",l[c],name[c],&top2[c],&e[c],add[c]))!=EOF){
		c++;
	}
	for(t=0;t<=c;t++){
		if(!strcmp(l[t],ids)){
			printf("found!!\n");
			fid=1;
			break;
		}
	}
	if(fid){
		printf("------------------------------------------------------\n");
		printf("ID: %s\n",l[t]);
		printf("name: %s\n",name[t]);
		printf("phone-number: %d%ld\n",top2[t],e[t]);
		printf("address: %s\n",add[t]);
		printf("------------------------------------------------------\n");
	}else{
		printf("not found...\n");
	}	
	fclose(fp);
}


void cl(){		//ファイル内データをすべて削除
	char ser[50],name[50][50],add[50][50],l[50][15];
	int c=0,t,n,fid=0,top2[50],pp,i;
	long int e[50];
	fp= fopen("data.txt","r");
	while((fscanf(fp,"%*s %[^\n/]//%*s %[^\n/]//%*s %1d%ld//%*s %s",l[c],name[c],&top2[c],&e[c],add[c]))!=EOF){
		c++;
	}
	fclose(fp);
	fp= fopen("trash.txt","a");
	for(i=0;i<c;i++){
		fprintf(fp,"ID: %s//name: %s//phone-number: %d%ld//address: %s\n",l[i],name[i],top2[i],e[i],add[i]);
	}	
	fclose(fp);
	fp=fopen("data.txt","w");
	fclose(fp);
}

void iddel(){		//ID検索して削除
	char name[50][50],add[50][50],l[50][15],ids[15];
	int c=0,t,n,fid=0,top2[50],pp,i;
	long int e[50];

	fp = fopen("data.txt","r");
	printf("serch\n");
	scanf(" %s",ids);
	while((fscanf(fp,"%*s %[^\n/]//%*s %[^\n/]//%*s %1d%ld//%*s %s",l[c],name[c],&top2[c],&e[c],add[c]))!=EOF){
		c++;
	}
	for(t=0;t<c;t++){
		if(!strcmp(l[t],ids)){
			printf("found!!\n");
			fid=1;
			break;
		}
	}
	if(fid){
		fp2 = fopen("trash.txt","a");
		printf("------------------------------------------------------\n");
		printf("ID: %s\n",l[t]);
		printf("name: %s\n",name[t]);
		printf("phone-number: %d%ld\n",top2[t],e[t]);
		printf("address: %s\n",add[t]);
		printf("------------------------------------------------------\n");	
		printf("delete....\n");
		fprintf(fp2,"ID: %s//name: %s//phone-number: %d%ld//address: %s\n",l[t],name[t],top2[t],e[t],add[t]);
		fclose(fp2);
	}else{
		printf("not found...\n");
	}
	fclose(fp);
	if(fid){
		fp =fopen("data.txt","w");	
		for(i=0;i<c;i++){
			if(i==t){
				continue;
			}
				fprintf(fp,"ID: %s//name: %s//phone-number: %d%ld//address: %s\n",l[i],name[i],top2[i],e[i],add[i]);
			}	
		fclose(fp);
	}
}

void namedel(){		//名前検索をして削除	
	char ser[50],name[50][50],add[50][50],l[50][15];
	int c=0,t,n,fid=0,top2[50],pp,i;
	long int e[50];
	fp = fopen("data.txt","r");
	fp2 = fopen("trash.txt","a");
	printf("serch\n");
	scanf(" %50[^\n]",ser);
	while((fscanf(fp,"%*s %[^\n/]//%*s %[^\n/]//%*s %1d%ld//%*s %s",l[c],name[c],&top2[c],&e[c],add[c]))!=EOF){
		c++;
	}
	for(t=0;t<=c;t++){
		if(!strcmp(name[t],ser)){
			printf("found!!\n");
			fid=1;
			break;
		}
	}
	fclose(fp);
	if(fid){
		fp2 = fopen("trash.txt","a");
		printf("------------------------------------------------------\n");
		printf("ID: %s\n",l[t]);
		printf("name: %s\n",name[t]);
		printf("phone-number: %d%ld\n",top2[t],e[t]);
		printf("address: %s\n",add[t]); 
		printf("------------------------------------------------------\n");
		fprintf(fp2,"ID: %s//name: %s//phone-number: %d%ld//address: %s\n",l[t],name[t],top2[t],e[t],add[t]);
		fclose(fp2);
	}else{
		printf("not found...\n");
	}
	if(fid){
		fp =fopen("data.txt","w");	
		for(i=0;i<c;i++){
			if(i==t){
				continue;
			}
				fprintf(fp,"ID: %s//name: %s//phone-number: %d%ld//address: %s\n",l[i],name[i],top2[i],e[i],add[i]);
		fclose(fp);
		}
	}
}	

void list(){		//ファイル内データリスト	
	char name[50][50],add[50][50],l[50][15];
	int c=0,t,top2[50];
	long int e[50];
	fp = fopen("data.txt","r");
	while((fscanf(fp,"%*s %[^\n/]//%*s %[^\n/]//%*s %1d%ld//%*s %s",l[c],name[c],&top2[c],&e[c],add[c]))!=EOF){
		c++;
	}
	for(t=0;t<c;t++){
		printf("------------------------------------------------------\n");
		printf("ID: %s\n",l[t]);
		printf("name: %s\n",name[t]);
		printf("phone-number: %d%ld\n",top2[t],e[t]);
		printf("address: %s\n",add[t]);
		printf("------------------------------------------------------\n");
	}
	fclose(fp);
}

void pass(){	//パスワード設定
	char pas[50],cp[50];

	fp=fopen("pass.txt","r");
	fscanf(fp,"%*s %s",pas);
	printf("Change password\n");
	printf("(current)Please enter your password: ");
	scanf("%s",cp);
	fclose(fp);

	if(!strcmp(pas,cp)){
		fp=fopen("pass.txt","w");
		printf("Please enter your new password: ");
		scanf("%s",pas);
		fprintf(fp,"password: %s",pas);
		fclose(fp);
	}else{
		printf("not password\n");
	}
}

void tra(){
	char name[50][50],add[50][50],l[50][15];
	int c=0,t,top2[50];
	long int e[50];
	fp = fopen("trash.txt","r");
	while((fscanf(fp,"%*s %[^\n/]//%*s %[^\n/]//%*s %1d%ld//%*s %s",l[c],name[c],&top2[c],&e[c],add[c]))!=EOF){
		c++;
	}
	for(t=0;t<c;t++){
		printf("------------------------------------------------------\n");
		printf("ID: %s\n",l[t]);
		printf("name: %s\n",name[t]);
		printf("phone-number: %d%ld\n",top2[t],e[t]);
		printf("address: %s\n",add[t]);
		printf("------------------------------------------------------\n");
	}
	fclose(fp);
}

void trac(){
	fp=fopen("trash.txt","w");
	fclose(fp);
}

void re(){
	char name[50][50],add[50][50],l[50][15],ser[50];
	int c=0,t,n,fid=0,top2[50],pp,i;
	long int e[50];

	fp = fopen("trash.txt","r");
	printf("serch\n");
	scanf(" %[^\n]",ser);
	while((fscanf(fp,"%*s %[^\n/]//%*s %[^\n/]//%*s %1d%ld//%*s %s",l[c],name[c],&top2[c],&e[c],add[c]))!=EOF){
		c++;
	}
	
	for(t=0;t<c;t++){
		if(!strcmp(l[t],ser)){
			printf("found!!\n");
			fid=1;
			break;
		}
	}
	if(!fid){
		for(t=0;t<c;t++){
			if(!strcmp(name[t],ser)){
				printf("found!!\n");
				fid=1;
				break;
			}
		}
	}

	if(fid){
		fp2 = fopen("data.txt","a");
		printf("------------------------------------------------------\n");
		printf("ID: %s\n",l[t]);
		printf("name: %s\n",name[t]);
		printf("phone-number: %d%ld\n",top2[t],e[t]);
		printf("address: %s\n",add[t]);
		printf("------------------------------------------------------\n");	
		printf("reborn....\n");
		fprintf(fp2,"ID: %s//name: %s//phone-number: %d%ld//address: %s\n",l[t],name[t],top2[t],e[t],add[t]);
		fclose(fp2);
	}else{
		printf("not found...\n");
	}
	fclose(fp);
	if(fid){
		fp =fopen("trash.txt","w");	
		for(i=0;i<c;i++){
			if(i==t){
				continue;
			}
				fprintf(fp,"ID: %s//name: %s//phone-number: %d%ld//address: %s\n",l[i],name[i],top2[i],e[i],add[i]);
			}	
		fclose(fp);
	}
}


int main(){
	char spass[50],copass[50],flg=0;
	fp=fopen("pass.txt","a");
	fclose(fp);
	fp=fopen("data.txt","a");
	fclose(fp);
	fp=fopen("trash.txt","a");
	fclose(fp);
	fp=fopen("pass.txt","r");
	if(fscanf(fp,"%*s %s",spass)==EOF){
		fclose(fp);
		fp=fopen("pass.txt","w");
		printf("Please enter new password: ");
		scanf("%s",spass);
		fprintf(fp,"password: %s",spass);
		fclose(fp);
		flg=1;
	}else{
		fscanf(fp,"%*s %s",spass);
		printf("Please enter your password: ");
		scanf("%s",copass);
		fclose(fp);
		if(!strcmp(copass,spass)){
			flg=1;
		}
	}

	if(flg){
		while(1){
			char mode;

			printf("mode select (h:help)\n");
			scanf(" %1[RtpDdlrscqiCh]",&mode);
			switch(mode){
				case 'h':
					help();
					break;
				case 'r':
					Regi();
					break;
				case 's':
					Ser();
					break;
				case 'i':
					IDser();
					break;
				case 'd':
					iddel();
					break;
				case 'D':
					namedel();
					break;
				case 'l':
					list();
					break;
				case 'c':
					cl();
					printf("clear\n");
					break;
				case 'C':
					trac();
					break;
				case 'p':
					pass();
					break;
				case 'q':
					printf("finish\n");
					exit(0);
				case 't':
					printf("trash can data\n");
					tra();
					break;
				case 'R':
					printf("reborn id serch\n");
					re();
					break;
			}
		}
	}else{
		printf("Password is incorrect\n");
	}
return 0;
}
