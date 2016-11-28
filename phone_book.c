#include<stdio.h>
#include<string.h>
#include<stdlib.h>

FILE *fp;
struct person{
	int id;
	char name[50];//namae
	long int phone;
	char address[256];
};

void Regi(){                    //登録モード
	fp = fopen("data.txt","a");
	char ser[50],dummy;
	int c=0,i,resu=0,t,n,fid=0,l[50],idata[50],top[50],top2[50],pp;
	long int y[50],e[50];
	printf("How many people??\n");
	scanf(" %d",&pp);
	struct person data[pp+1];	
	for(i=0;i<pp;i++){
		top[i]=-1;
		printf("No.%d\n",i+1);
	
		printf("ID --> ");
		scanf("%d",&data[i].id);
		printf("name --> ");
		scanf(" %50[^\n]",data[i].name);
		printf("phone number --> ");
		scanf(" %1d%ld",&top[i],&data[i].phone);
		printf("address --> ");
		scanf("%s",data[i].address);
	}
	printf("\nRegistered--------------------------------------------\n");
	for(i=0;i<pp;i++){
		if(top[i]!=-1){
			printf("ID: %d//name: %s//phone-number: %d%ld//address: %s\n",data[i].id ,data[i].name ,top[i],data[i].phone,data[i].address);
			fprintf(fp,"ID: %d//name: %s//phone-number: %d%ld//address: %s\n",data[i].id,data[i].name,top[i] ,data[i].phone,data[i].address);
			
		}
		else{
			printf("ID: %d//name: %s//phone-number: %ld//address: %s\n",data[i].id,data[i].name ,data[i].phone,data[i].address);
			fprintf(fp,"ID: %d//name: %s//phone-number: %ld//address: %s\n",data[i].id,data[i].name ,data[i].phone,data[i].address);
		}
	}
	printf("------------------------------------------------------\n");
	fclose(fp);
}


void Ser(){			//検索モード
	char ser[50],name[50][50],add[50][50];
	int c=0,t,n,fid=0,l[50],top2[50],pp;
	long int e[50];

	fp = fopen("data.txt","r");
	printf("serch\n");
	scanf(" %50[^\n]",ser);
	while((fscanf(fp,"%*s %d//%*s %[^\n//]//%*s %1d%ld//%*s %s",&l[c],name[c],&top2[c],&e[c],add[c]))!=EOF){
		c++;
	}
	for(t=0;t<=c;t++){
		printf("%s\n",name[t]);
		if(!strcmp(name[t],ser)){
			printf("found!!\n");
			fid=1;
			break;
		}
	}
	if(fid){
		printf("------------------------------------------------------\n");
		printf("ID: %d\n",l[t]);
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
	char name[50][50],add[50][50];
	int c=0,t,n,fid=0,l[50],top2[50],pp,ids;
	long int e[50];

	fp = fopen("data.txt","r");
	printf("serch\n");
	scanf("%*[^0-9]");
	scanf(" %d",&ids);
	while((fscanf(fp,"%*s %d//%*s %[^\n//]//%*s %1d%ld//%*s %s",&l[c],name[c],&top2[c],&e[c],add[c]))!=EOF){
		c++;
	}
	for(t=0;t<=c;t++){
		printf("%d\n",l[t]);
		if(l[t]==ids){
			printf("find!!\n");
			fid=1;
			break;
		}
	}
	if(fid){
		printf("------------------------------------------------------\n");
		printf("ID: %d\n",l[t]);
		printf("name: %s\n",name[t]);
		printf("phone-number: %d%ld\n",top2[t],e[t]);
		printf("address: %s\n",add[t]);
		printf("------------------------------------------------------\n");
	}else{
		printf("not find...\n");
	}	
	fclose(fp);
}


void cl(){		//ファイルデータ削除
	fp = fopen("data.txt","w");
	fclose(fp);
}

void iddel(){
	char name[50][50],add[50][50];
	int c=0,t,n,fid=0,l[50],top2[50],pp,ids,i;
	long int e[50];
	fp = fopen("data.txt","r");
	printf("serch\n");
	scanf(" %*[^0-9]");
	scanf(" %d",&ids);
	printf("#%d\n",ids);
	while((fscanf(fp,"%*s %d//%*s %[^\n//]//%*s %1d%ld//%*s %s",&l[c],name[c],&top2[c],&e[c],add[c]))!=EOF){
		c++;
	}
	for(t=0;t<c;t++){
		if(l[t]==ids){
			printf("find!!\n");
			fid=1;
			break;
		}
	}
	if(fid){
		printf("------------------------------------------------------\n");
		printf("ID: %d\n",l[t]);
		printf("name: %s\n",name[t]);
		printf("phone-number: %d%ld\n",top2[t],e[t]);
		printf("address: %s\n",add[t]);
		printf("------------------------------------------------------\n");	
		printf("delete....\n");
	}else{
		printf("not find...\n");
	}
	fclose(fp);
	if(fid){
		fp =fopen("data.txt","w");	
		for(i=0;i<c;i++){
			if(i==t){
				continue;
			}
			if(top2[i]!=-1){
				fprintf(fp,"ID: %d//name: %s//phone-number: %d%ld//address: %s\n",l[i],name[i],top2[i],e[t],add[t]);
			}else{
				fprintf(fp,"ID: %d//name: %s//phone-number: %ld//address: %s\n",l[i],name[i],e[t],add[t]);
			}	
		}	
		fclose(fp);
	}
}

void namedel(){			
	char ser[50],name[50][50],add[50][50];
	int c=0,t,n,fid=0,l[50],top2[50],pp,i;
	long int e[50];
	fp = fopen("data.txt","r");
	printf("serch\n");
	scanf(" %50[^\n]",ser);
	while((fscanf(fp,"%*s %d//%*s %[^\n//]//%*s %1d%ld//%*s %s",&l[c],name[c],&top2[c],&e[c],add[c]))!=EOF){
		c++;
	}
	for(t=0;t<=c;t++){
		printf("%s\n",name[t]);
		if(!strcmp(name[t],ser)){
			printf("found!!\n");
			fid=1;
			break;
		}
	}
	fclose(fp);
	if(fid){
		printf("------------------------------------------------------\n");
		printf("ID: %d\n",l[t]);
		printf("name: %s\n",name[t]);
		printf("phone-number: %d%ld\n",top2[t],e[t]);
		printf("address: %s\n",add[t]); 
		printf("------------------------------------------------------\n");
	}else{
		printf("not found...\n");
	}
	if(fid){
		fp =fopen("data.txt","w");	
		for(i=0;i<c;i++){
			if(i==t){
				continue;
			}
			if(top2[i]!=-1){
				fprintf(fp,"ID: %d//name: %s//phone-number: %d%ld//address: %s\n",l[i],name[i],top2[i],e[t],add[t]);
			}else{
				fprintf(fp,"ID: %d//name: %s//phone-number: %ld//address: %s\n",l[i],name[i],e[t],add[t]);
			}	
		}	
		fclose(fp);
	}
}

void list(){		//ファイル内データリスト	
	char name[50][50],add[50][50];
	int c=0,t,l[50],top2[50];
	long int e[50];
	fp = fopen("data.txt","r");
	while((fscanf(fp,"%*s %d//%*s %[^\n//]//%*s %1d%ld//%*s %s",&l[c],name[c],&top2[c],&e[c],add[c]))!=EOF){
		c++;
	}
	printf("ok\n");
	for(t=0;t<=c-1;t++){
		printf("------------------------------------------------------\n");
		printf("ID: %d\n",l[t]);
		printf("name: %s\n",name[t]);
		printf("phone-number: %d%ld\n",top2[t],e[t]);
		printf("address: %s\n",add[t]);
		printf("------------------------------------------------------\n");
	}
}

int main(){
	while(1){
		char mode;
		printf("mode select Registration:r Search:s IDserch:i IDdelete:d list:l clear:c end:q\n");
		scanf(" %[Ddlrscqi]",&mode);
		switch(mode){
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
			case 'q':
				printf("finish\n");
				exit(0);
		}
	}
}	
