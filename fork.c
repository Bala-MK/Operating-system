#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>
void sequence(int n){
	printf("Sequence:\n");
	while(n>0){
		printf("%d\n",n);
        n=n/2;
	}
}
int main(){
	int n=0;
	printf("Enter a Positive Integer:");
	scanf("%d",&n);
	while(n<=0){
		printf("Positive number required.\nEnter Again:");
		scanf("%d",&n);
	}
	pid_t p;
	p=fork();
	if(p==0){
		printf("Child Process is Executing:\n");
		printf("Process id=%d\nMy Parent Process id=%d\n",getpid(),getppid());
		sequence(n);

	}
	else{
		wait(NULL);
		printf("Parent Process is Executing:\n");
		printf("Process id=%d\nMy Parent Process id=%d\n",getpid(),getppid());
	}
}
