#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/time.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <dirent.h>
#include <utime.h>
#include <string.h>
#include <time.h>
#include <signal.h>
#include <dirent.h>
#include <sys/utsname.h>
#include <utmp.h>

int my_date(int cnt,char *var[]);
int my_clear(int cnt,char *var[]);
int my_wc(int cnt , char *var[]);
int my_kill(int cnt,char *var[]);
int my_ls(int cnt,char *var[]);
int  my_cp(int cnt,char *var[]);
void my_mv(int cnt,char *var[]);
void my_pwd(int cnt,char *var[]);
void my_cd(int cnt,char *var[]);
void my_mkdir(int cnt,char *var[]);
void my_rmdir(int cnt,char *var[]);
void my_ln(int cnt,char *var[]);
void my_touch(int cnt,char *var[]);
void my_cat(int cnt,char *var[]);
void my_uname(int cnt,char *var[]);
void my_who(int cnt,char *var[]);
void my_rename(int cnt,char *var[]);
void my_head(int cnt,char *var[]);
void my_env(int cnt,char *var[]);
void my_tail(int cnt, char *var[]);
void my_rm(int cnt, char *var[]);


int main()
{	
	char *token; 		 //to store strtok returned value	
        char command[100];      //to store the read command
	char *token_ptr[100];
	char buf[100];  //to store each part in a command      	
	int i=-1,j;
	write(1, "\33[H\33[2J", 7); //for clearing the screen
	printf("\t\t!_!_!_!_!_!_!_!_!_!_!_!_WELCOME TO MY SHELL _!_!_!_!_!_!_!_!_!_!_\n\n");
        while(1)
	{
		
		printf("\n%s ",getcwd(buf,100));  //command prompt (PS1 variable)
		gets(command); 		//read command

		/*strtok() parses the input and divides into tokens based on the delimiter value that is set. */
		token_ptr[++i] = strtok(command," ");
	       if(token_ptr[0] != NULL)         //if token starts here
	       {   
			if(!strcmp(token_ptr[0], "exit"))    //check if token is exit
			{	
				printf("\n");
				exit(1);
			} 			    //if exit ends here

			else if(!strcmp(token_ptr[0],"date"))    //check if command is date
			{
				while(token_ptr[++i] = strtok(NULL," "))	//subsequent calls to strtok with NULL and not command
				{	
					//strcpy(token_ptr[++i],token);  //all subsequent parameteres are stored in token_ptr array 
				}
				my_date(i,token_ptr);
						     	
			}	

			else if(!strcmp(token_ptr[0],"clear"))    //check if command is clear
			{
				while(token_ptr[++i] = strtok(NULL," "))	//subsequent calls to strtok with NULL and not command
				{	
					//strcpy(token_ptr[++i],token);  //all subsequent parameteres are stored in token_ptr array 
				}
				my_clear(i,token_ptr);
						     	
			}

			else if(!strcmp(token_ptr[0],"wc"))    //check if command is wc(word count)
			{
				while(token_ptr[++i] = strtok(NULL," "))	//subsequent calls to strtok with NULL and not command
				{	
					//strcpy(token_ptr[++i],token);  //all subsequent parameteres are stored in token_ptr array 
				}
				my_wc(++i,token_ptr);
						     	
			}
				
			else if(!strcmp(token_ptr[0],"kill"))    //check if command is kill
			{
				while(token_ptr[++i] = strtok(NULL," "))	//subsequent calls to strtok with NULL and not command
				{	
					//strcpy(token_ptr[++i],token);  //all subsequent parameteres are stored in token_ptr array 
				}
				my_kill(i,token_ptr);
						     	
			}

			else if(!strcmp(token_ptr[0],"ls"))    //check if command is ls
			{
				while(token_ptr[++i] = strtok(NULL," "))	//subsequent calls to strtok with NULL and not command
				{	
					//strcpy(token_ptr[++i],token);  //all subsequent parameteres are stored in token_ptr array 
				}
				my_ls(i,token_ptr);
						     	
			}
		
			else if(!strcmp(token_ptr[0],"cp"))    //check if token is mycp
			{
				while(token_ptr[++i] = strtok(NULL," "))	//subsequent calls to strtok with NULL and not command
				{	
					//strcpy(token_ptr[++i],token);  //all subsequent parameteres are stored in token_ptr array 
				}
				my_cp(i,token_ptr);
						     	
			}		//if mycp ends here

			else if(!strcmp(token_ptr[0],"mv"))    //check if token is mv
			{
				while(token_ptr[++i] = strtok(NULL," "))	//subsequent calls to strtok with NULL and not command
				{	
					 //all subsequent parameteres are stored in token_ptr array 
				}
				my_mv(i,token_ptr);
						     	
			}		//if mymv ends here

			else if(!strcmp(token_ptr[0],"pwd"))    //check if token is pwd
			{
				while(token_ptr[++i] = strtok(NULL," "))	//subsequent calls to strtok with NULL and not command
				{	
					 //all subsequent parameteres are stored in token_ptr array 
				}
				my_pwd(i,token_ptr);
						     	
			}

			else if(!strcmp(token_ptr[0],"cd"))    //check if token is cd
			{
				while(token_ptr[++i] = strtok(NULL," "))	//subsequent calls to strtok with NULL and not command
				{	
					 //all subsequent parameteres are stored in token_ptr array 
				}
				my_cd(i,token_ptr);
						     	
			}
			
			else if(!strcmp(token_ptr[0],"ln"))    //check if token is myls
			{
				while(token_ptr[++i] = strtok(NULL," "))	//subsequent calls to strtok with NULL and not command
				{	
					//all subsequent parameteres are stored in token_ptr array 
				}
				my_ln(i,token_ptr);
						     	
			}		//if myln ends here
			
			

			else if(!strcmp(token_ptr[0],"cat"))    //check if token is cat
			{
				while(token_ptr[++i] = strtok(NULL," "))	//subsequent calls to strtok with NULL and not command
				{	
					 //all subsequent parameteres are stored in token_ptr array 
				}
				my_cat(i,token_ptr);
						     	
			}		//if cat ends here
			
			else if(!strcmp(token_ptr[0],"mkdir"))    //check if token is mkdir
			{
				while(token_ptr[++i] = strtok(NULL," "))	//subsequent calls to strtok with NULL and not command
				{	
					 //all subsequent parameteres are stored in token_ptr array 
				}
				my_mkdir(i,token_ptr);
						     	
			}		//if mkdir ends here

			else if(!strcmp(token_ptr[0],"rmdir"))    //check if token is rmdir
			{
				while(token_ptr[++i] = strtok(NULL," "))	//subsequent calls to strtok with NULL and not command
				{	
					 //all subsequent parameteres are stored in token_ptr array 
				}
				my_rmdir(i,token_ptr);
						     	
			}		//if rmdir ends here
			
			else if(!strcmp(token_ptr[0],"rm"))    //check if token is rm
			{
				while(token_ptr[++i] = strtok(NULL," "))	//subsequent calls to strtok with NULL and not command
				{	
					 //all subsequent parameteres are stored in token_ptr array 
				}
				my_rm(i,token_ptr);
						     	
			}		//if rm ends here

			
			else if(!strcmp(token_ptr[0],"touch"))    //check if token is touch
			{
				while(token_ptr[++i] = strtok(NULL," "))	//subsequent calls to strtok with NULL and not command
				{	
					 //all subsequent parameteres are stored in token_ptr array 
				}
				my_touch(i,token_ptr);
						     	
			}		//if mytouch ends here*/

			else if(!strcmp(token_ptr[0],"uname"))    //check if token is uname
			{
				while(token_ptr[++i] = strtok(NULL," "))	//subsequent calls to strtok with NULL and not command
				{	
					 //all subsequent parameteres are stored in token_ptr array 
				}
				my_uname(i,token_ptr);
						     	
			}		//if  ends here

			else if(!strcmp(token_ptr[0],"head"))    //check if token is head
			{
				while(token_ptr[++i] = strtok(NULL," "))	//subsequent calls to strtok with NULL and not command
				{	
					 //all subsequent parameteres are stored in token_ptr array 
				}
				my_head(i,token_ptr);
						     	
			}		//if  ends here

			else if(!strcmp(token_ptr[0],"tail"))    //check if token is tail
			{
				while(token_ptr[++i] = strtok(NULL," "))	//subsequent calls to strtok with NULL and not command
				{	
					 //all subsequent parameteres are stored in token_ptr array 
				}
				my_tail(i,token_ptr);
						     	
			}		//if  ends here
	
			else if(!strcmp(token_ptr[0],"who"))    //check if token is who
			{
				while(token_ptr[++i] = strtok(NULL," "))	//subsequent calls to strtok with NULL and not command
				{	
					 //all subsequent parameteres are stored in token_ptr array 
				}
				my_who(i,token_ptr);
						     	
			}		//if  ends here


			else if(!strcmp(token_ptr[0],"rename"))    //check if token is who
			{
				while(token_ptr[++i] = strtok(NULL," "))	//subsequent calls to strtok with NULL and not command
				{	
					 //all subsequent parameteres are stored in token_ptr array 
				}
				my_rename(i,token_ptr);
						     	
			}		//if  ends here


			else if(!strcmp(token_ptr[0],"env"))    //check if token is who
			{
				while(token_ptr[++i] = strtok(NULL," "))	//subsequent calls to strtok with NULL and not command
				{	
					 //all subsequent parameteres are stored in token_ptr array 
				}
				my_env(i,token_ptr);
						     	
			}

			
	
			else			//finally invalid command
			{
				printf("Command not found \n");			
			}			//invalid command ends here
		
	      } 
	     
		i=-1;   //clear the token_ptr array
		
	}	
		
	return 0;
}

int my_date(int cnt,char *var[])
{
	time_t current_time;
   	char* c_time_string;
 
    	/* Obtain current time as seconds elapsed since the Epoch. */
    	current_time = time(NULL);
 
    	if (current_time == ((time_t)-1))
    	{
        	(void) fprintf(stderr, "Failure to compute the current time.");
        	return EXIT_FAILURE;
    	}
 
    	/* Convert to local time format. */
    	c_time_string = ctime(&current_time);
 
    	if (c_time_string == NULL)
   	{
        	(void) fprintf(stderr, "Failure to convert the current time.");
        	return EXIT_FAILURE;
    	}
 
    	/* Print to stdout. */
    	(void) printf("Current time is %s", c_time_string);
    	return EXIT_SUCCESS;
}
	
/*clear command*/

int my_clear(int cnt,char *var[]) 
{
	write(1, "\33[H\33[2J", 7); //  \33[H sends the cursor to home location and \33[2J clears the text on screen.
	return 0;
}

/* WC command*/

int my_wc(int cnt , char *var[])
{
	int character_count = 0;
        int space_count = 0;
        int word_count = 0;
        int line_count = 0;
        char ch;

        FILE *fp;

        if(cnt < 2)
        {
   		printf("Please specify the filename as argument\n");
                return ;
        }

        if(fp != 0)
        {
                printf("No such file or directory\n");
                return ;
        }
        fp = fopen(var[1],"r");

        while((ch=fgetc(fp))!=EOF)
        {
        	character_count++;
                if(ch == ' ')
                {
                	space_count++;
                        word_count++;
                }
                if(ch == '\n')
                {
			line_count++;
                }
        }
        printf("character_count = %d\n",character_count);
        printf("space_count = %d\n",space_count);
        printf("word_count = %d\n",word_count+1);
        printf("line_count = %d\n",line_count);
	
	return 0;
}

/*KILL command*/

int my_kill(int cnt,char *var[])
{	
	pid_t pid;
	system("ps");
	printf("Enter the pid of process to kill:");
	scanf("%d",&pid);
	
    /*if (cnt < 2)
    {
        printf("usage: ./kill PID");
        return -1;
    }*/

    kill(pid, SIGKILL);
    printf("Process has killed Successfully\n");

    return 0;

}

/*ls command*/

int my_ls(int cnt,char *var[])
{
	DIR *directory;
	struct dirent *file;
	int i;
	char *parameter;

	if(cnt<2)
	{
		printf("\n USAGE:ls [dirname]\n ");
		return;
	}

	 if(strcmp(var[1],"-l")==0)	// if -l option is specified
	 {
          	DIR  *dp;
          	struct dirent *p;
          	struct stat buf;
          	dp=opendir(var[2]);	       //Opening a directory
          	if(dp==NULL)
          	{
                  	printf("Directory opening problem");
                  	return;
          	}
	 	 printf("Permissions link  uid    gid   size    inode    filename     Modification Time\n");
         	 while((p = readdir(dp))!=NULL)
          	{
                  	if(stat(p->d_name,&buf)==-1)         //0 on success ,-1 on fail       
		 	{
                          printf("\nStat error\n");
                          return 0;
                  	}
                  if(S_ISREG(buf.st_mode))
                          printf("_");
                  if(S_ISDIR(buf.st_mode))
                          printf("d");
                  if(S_ISCHR(buf.st_mode))
                          printf("c");
                  if(S_ISBLK(buf.st_mode))
                          printf("b");
                  if(S_ISFIFO(buf.st_mode))
                          printf("p");
                  if(S_ISLNK(buf.st_mode))
                          printf("l");
                  if(S_ISSOCK(buf.st_mode))
                          printf("s");
                  if(S_IRUSR & buf.st_mode)
                        printf("r");
                 else
                          printf("-");
                  if(S_IWUSR & buf.st_mode)
                          printf("w");
                 else
                          printf("-");
                 if(S_IXUSR & buf.st_mode)
                          printf("x");
                 else
                         printf("-");
                  if(S_IRGRP & buf.st_mode)
                          printf("x");
                  else
                          printf("-");
                  if(S_IWGRP & buf.st_mode)
                          printf("w");
                  else
                          printf("-");
                  if(S_IXGRP & buf.st_mode)
                          printf("x");
                  else
                          printf("-");
                  if(S_IROTH & buf.st_mode)
                          printf("r");
                  else
                         printf("-");
                  if(S_IWOTH & buf.st_mode)
                         printf("w");
                  else
                          printf("-");
                  if(S_IXOTH & buf.st_mode)
                          printf("x");
                  else
                          printf("-");
                  printf("   %d",buf.st_nlink);
                  printf("    %ld",(long)buf.st_uid);
                  printf("  %ld",(long)buf.st_gid);
                  printf("  %5d",(int)buf.st_size);
		  printf("  %ld",(long)buf.st_ino);
		  printf("  %10s",p->d_name);
		  time_t ti= buf.st_mtime;
		  char* t =ctime(&ti);
                  printf("  %s",t);
		
          }
      }
   else{
	   for(i=1;i<=cnt-1;i++)
		if(!access(var[i],F_OK))
		{
			directory=opendir(var[i]);

			if(directory!=NULL)
			{
				while((file=readdir(directory))!=NULL)
					printf("%s\t",file->d_name);
				printf("\n");
			}
			else
				perror("opendir");
		}
		else
				perror("access");
	}
	
return 0;
}

/*cp command*/

int my_cp(int cnt,char *var[])
{
	int fd1,fd2;
	char *buffer;
	int count;
	if(cnt!=3)
	{
		printf("USAGE:cp [file_name1] [file_name2]\n");
		exit(1);
	}

	if(!access(var[1],F_OK))
	{
		fd1=open(var[1],O_RDONLY);
		if(fd1>0)
		{	
			fd2=open(var[2],O_CREAT|O_WRONLY);	
			if(fd2>0)
			{
				while((count=read(fd1,&buffer,sizeof(buffer)))>0)
					write(fd2,&buffer,sizeof(count));
					printf("File copied successfully\n");

				close(fd2);
				close(fd1);
			}
			else
				printf("\n Error opening file %s \n",var[2]);
		}
		else
			printf("\n Error opening file %s\n",var[1]);
	}
	else
		printf("\n Error : %s does not exist \n",var[1]);
		
	return 0;
}

/*mv command*/

void my_mv(int cnt,char *var[])
{
	int fd1,fd2,count;
	char buf[512]; 
	if(cnt!=3)
	{
		printf("USAGE:mv [file_name1][file_name2]\n"); 
		exit(1);
	}
	else
	{
		fd1=open(var[1],O_RDONLY); 
		if(fd1==-1)
		{
			printf("source file does not exist\n"); 
			exit(1);
		}
		fd2=open(var[2],O_CREAT|O_WRONLY,0777); 
		if(fd2==-1) 
			fd2=creat(var[2],0777); 
		while((count=read(fd1,buf,512))>0)
		{
			write(fd2,buf,count);
		}	
		close(fd1);
		close(fd2);
	}
	int c=unlink(var[1]); 
	if(c==0)
		printf("unlinked successfully\n"); 
	else
		printf("link error\n");
}


void my_pwd(int cnt,char *var[]) 
{
	char *buf;
	buf=(char *)malloc(100*sizeof(char));
	getcwd(buf,100);
	printf("\n %s \n",buf);
}

/*cd command*/

void my_cd(int cnt,char *var[]) 
{
	if (cnt == 1) // no args
	{
		const char* home = getenv("HOME");
		chdir(home ? home : "."); // in case HOME is not defined :-)
	}
	else // arg given (could it be a path?)
	{
		chdir(var[1]);
	}
} 
/*mkdir command*/


void my_mkdir(int cnt,char *var[])
{
	int fd;

	if(cnt!=2)
	{
		printf("\n Usage: mkdir directory_name \n");
		return;
	}

	if(mkdir(var[1],0775)==0)
		printf("Directory created\n");
	else
		printf("\n Cannot create %s",var[1]);

}

/*rmdir command*/

void my_rmdir(int cnt,char *var[])
{
	int fd;

	if(cnt!=2)
	{
		printf("\n Usage: rmdir directory_name \n ");
		return;
	}

	if(rmdir(var[1])==0)
		printf("Directory removed\n");
	else
		printf("Error: %s not removed \n",var[1]);

}


/*rm*/

void my_rm(int cnt,char *var[])
{
	int fd;

	if(cnt!=2)
	{
		printf("\n Usage: rm file_name \n ");
		return;
	}

	if(unlink(var[1])==0)
		printf("File removed\n");
	else
		printf("Error: %s not removed \n",var[1]);

}

/*ln command*/

void my_ln(int cnt,char *var[])
{
	if(cnt<3 || cnt>5)
	{
		printf("\n USAGE:ln [filename1] [filename2] | ln [-s] [filename1] [filename2]\n");
		exit(0);
	}

	if(strcmp(var[1],"-s")==0)
	{
		if(!symlink(var[2],var[3]))
			printf("\n Soft link created\n ");
		else
			printf("\n Error creating symbolic link\n");

	}
	else if(cnt==3)
	{
		if(!link(var[1],var[2]))
			printf("\n Hard link created \n");
		else
			printf("\n Hard link Failed \n");
	}

	else
		printf("\n Syntax Error\n");

}

/*touch command*/
void my_touch(int cnt,char *var[])
{
	struct utimbuf times;
	struct utimbuf {
                time_t  actime;
                time_t  modtime;
        };

	if(cnt!=2)
	{
		printf("USAGE:touch [filename|pathname]\n");
		exit(0);
	}
	if(!(access(var[1],F_OK)))
	{
		utime( var[1],&times);
	}
	else
	{
		creat(var[1],O_RDWR);
		utime( var[1],&times);
	}
	

 //int utime(const char *path, const struct utimbuf *times);

       /* path    Pointer to name of file to update.

        times   Pointer to a structure with the new access and
                modification times; if NULL, the current time is
                used.

        struct utimbuf {
                time_t  actime;
                time_t  modtime;
        }; */
}

/*cat command*/

void my_cat(int cnt,char *var[])
{	
	char buf[200];
	int fd1,fd2,x;
	char in[10];
	for(cnt=1;c[i] = (char *) strtok(NULL," ");cnt++);
	if(cnt== 2)
	{
		int size = 1;
		fd1 = open(var[1],O_RDONLY);
		while(size != 0)
		{
			size = read(fd1,buf,sizeof(buf));
			x = write(1,buf,size);
			if(x == -1)
				perror("write");
		}
	}
	else if(cnt == 4 && !strcmp(var[2],">>"))
	{
		fd1 = open(c[1],O_RDONLY);
		fd2 = open(c[3],O_WRONLY | O_CREAT | O_TRUNC,0644);
		if(fd1 == -1 || fd2 == -1)
		{
			perror("open");
			return;
		}
		while(size != 0)
		{
			size = read(fd1,buf,sizeof(buf));
			write(fd2,buf,size);
		}
		close(fd1);
		close(fd2);
	}
	else if(cnt==3 && !strcmp(var[1],">"))
	{
		fd2 = open(var[2],O_WRONLY | O_CREAT | O_TRUNC,0644);
		while(strcmp(gets(in),"EOF"))	
			write(fd2,in,sizeof(in));
	}		
}		


/*uname command*/
void my_uname(int cnt,char *var[])
{
	struct utsname my_unam;
	if(uname(&my_unam) == -1)
   		printf("uname call failed!");
	else
   		printf("System name: %s\nNodename:%s\nRelease:%s\nVersion:%s\nMachine:%s\n",my_unam.sysname, my_unam.nodename, my_unam.release,my_unam.version,my_unam.machine);

	
}

/*who */

void my_who(int cnt,char *var[]) 
{
 	struct utmp *n;
 	char *a;
 	int i;
 	setutent();
 	n=getutent();
 	while(n!=NULL)
 	{
  		if(n->ut_type==7)
  		{
   			printf("%-9s",n->ut_user);
   			printf("%-12s",n->ut_line);
   			a=ctime(&n->ut_time);
   			printf(" ");
   			for(i=4;i<16;i++)
   			printf("%c",a[i]);
   			printf(" (");
   			printf("%s",n->ut_host);
   			printf(")\n");
  		}
  	 	n=getutent();
 	}
}


/*rename*/

void my_rename(int cnt,char *var[]) 
{
	char  buffer_old[101], buffer_new[101];

	printf("Current filename: ");
	scanf("%s",buffer_old);

	printf("New filename: ");
	scanf("%s",buffer_new);

	if(rename(buffer_old, buffer_new) == 0)
	{
		printf("%s has been rename %s.\n", buffer_old, buffer_new);
	}
	else
	{
		fprintf(stderr, "Error renaming %s.\n", buffer_old);
	}
}

/*head*/

void my_head(int cnt,char *var[])
{
	int numLines = 0;
	int linecount = 0;
	FILE *src = NULL;
	char ch[1024];
	
	if(cnt == 2)
	{
    		src = fopen( var[1], "r:");
    		numLines=10;

		if ( src == NULL)
		{
            	 	fputs ( "Can't open input file." , stdout);
            	 	exit (-1);
        	}
        	while (NULL != fgets(ch,1024, src))
		{
            	  	linecount++;
            	  	fputs(ch, stdout);
            	  	if (linecount == numLines)
		   	break; 
    		 } 
           	fclose( src );
	}

 }


/*tail*/


#define _FILE_OFFSET_BITS 64

#include <getopt.h>

#define BUFF_SIZE 4096

FILE *openFile(const char *filePath)
{
  FILE *file;
  file= fopen(filePath, "r");
  if(file == NULL)
  {
    fprintf(stderr,"Error opening file: %s\n",filePath);
    exit(0);
  }
  return(file);
}

void printLine(FILE *file, off_t startline)
{
  int fd;
  fd= fileno(file);
  int nread;
  char buffer[BUFF_SIZE];
  lseek(fd,(startline + 1),SEEK_SET);
  while((nread= read(fd,buffer,BUFF_SIZE)) > 0)
  {
    write(STDOUT_FILENO, buffer, nread);
  }
}

void walkFile(FILE *file, long nlines)
{
  off_t fposition;
  fseek(file,0,SEEK_END);
  fposition= ftell(file);
  off_t index= fposition;
  off_t end= fposition;
  long countlines= 0;
  char cbyte;

  for(index; index >= 0; index --)
  {
    cbyte= fgetc(file);
    if (cbyte == '\n' && (end - index) > 1)
    {
      countlines ++;
      if(countlines == nlines)
      {
    break;
      }
     }
    fposition--;
    fseek(file,fposition,SEEK_SET);
  }
  printLine(file, fposition);
  fclose(file);
}

void my_tail(int cnt, char *var[])
{
  FILE *file;
  file= openFile(var[2]);
  walkFile(file, atol(var[1]));
 
}
/*void my_tail(int cnt, char *var[])
{
  FILE *file;
  file= fopen(var[1], "r");
  if(file == NULL)
  {
    fprintf(stderr,"Error opening file: %s\n",var[1]);
    exit(1);
   }
  off_t fposition;
  fseek(file,0,SEEK_END);
  fposition= ftell(file);
  off_t index= fposition;
  off_t end= fposition;
  long countlines= 0;
  char cbyte;

  for(index; index >= 0; index --)
  {
    cbyte= fgetc(file);
    if (cbyte == '\n' && (end - index) > 1)
    {
      countlines ++;
      	if(countlines == 10)
      	{
   	 break;
        }
     }
    fposition--;
    fseek(file,fposition,SEEK_SET);
  }
  
int nread;
  char buffer[BUFF_SIZE];
  lseek(file,(fposition + 1),SEEK_SET);
  while((nread= read(file,buffer,BUFF_SIZE)) > 0)
  {
    write(stdout, buffer, nread);
  }
  fclose(file);
  
}*/

/*env*/


void my_env(int cnt,char *var[])
{   extern char **environ;
 	 int i = 0;
  	char *s = *environ;

  	for (; s; i++) 
	{
    		printf("%s\n", s);
    		s = *(environ+i);
  	}

}

