#include<fcntl.h>
#include<stdlib.h>
#include<stdio.h>
#include<unistd.h>
int main(int c,char *v[]){
	 if(c!=3){
                printf("Not enough Parameters\nExiting\n");
                exit(1);
        }
	int p[2];
	char r[100];
	int v1=open(v[1],O_RDONLY);
	int v2=open(v[2],O_WRONLY);
	pipe(p);
	pid_t a;
	a=fork();
	if(a==0){
		close(p[1]);
		int s=read(p[0],r,sizeof(r));
		write(v2,r,s);
	}
	else{
		close(p[0]);
		int v=read(v1,r,sizeof(r));
		write(p[1],r,v);
	}
}
