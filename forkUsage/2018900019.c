//Muhiddin HAVAN
//2018900019

#include <sys/types.h>
#include <errno.h>
#include <sys/wait.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>


int main() 
{ 
    int c1, c2, c3, c4gs; 
    int id_value,id,read_value;
    FILE *fp;

    c1 = fork(); 
    if (c1 == 0) { 
	sleep(0);
        printf("1st child process id --> pid = %d and parent id --> ppid = %d\n", getpid(), getppid()); 
	fp = fopen("opsys.txt", "w+");	
	fclose(fp);
	printf("file was created...\n");
    } 
  
    else { 
        c2 = fork(); 
        if (c2 == 0) {
	    sleep(1); 
            printf("2nd child process id --> pid = %d and parent id --> ppid = %d\n", getpid(), getppid()); 		 
	    c4gs = fork();
		if (c4gs == 0){
		
		printf("\n4th child process id --> pid = %d and parent id --> ppid = %d\n", getpid(), getppid()); 
		printf("Write the key:");
	    	scanf("%d", &id_value);	
		fp = fopen("opsys.txt", "w+");
		fprintf(fp,"%d",id_value);
		fclose(fp);
		}
	    
        } 
        else { 
            c3 = fork();
            if (c3 == 0) { 
		sleep(8);

                printf("\n3rd child process id --> pid = %d and parent id --> ppid = %d\n", getpid(), getppid()); 
		fp = fopen("opsys.txt", "r+");
		fscanf(fp, "%d", &read_value);
		fclose(fp);
		id = getppid();
		if (id == read_value){
		printf("matched\n");
		}
		else{
		printf("not matched\n");		
		}
		
            } 
	else { 
            sleep(15);
            printf("parent --> pid = %d\n", getpid()); 
            } 
        } 
    } 
  
    return 0; 
} 
