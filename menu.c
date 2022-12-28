//Mainmenu program
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include"header.h"
//Function to give design to the project
void design()
{
	for(int i = 0 ; i <30 ; i++)
		printf("*");
	printf("\n");
}
//Mainmenu of the project
int main_menu()
{
	system("clear");
	int ch , admin_pswd_flag = 0;
	char user[20];
	char password[20];
	char temp[15];
	admin_data admin_root ;
	while(1)
	{
		printf("1) Admin\n");
		printf("2) Coordinator\n");
		printf("3) Contestant\n");
		printf("0) Exit\n");
		//scanf("%d",&ch);
		ch = int_ans_choice(1,3);
		switch(ch)
		{
			case 1: 
				admin_root = read_admin_file(admin_root);
					printf("enter the usr name \n");
					while(1)
					{
						getchar();
						fgets(user , 20 , stdin);
						user[strlen(user)-1] = '\0';
						if(alpha_validator(user))
							break;
						else
							printf("use only characters\n");
					}
					printf("enter the password\n");
					while(1)
					{
						scanf("%s",password);
						if(strcmp(admin_root.user_name ,user ) == 0)
						{
							if(strcmp(admin_root.pswd ,password ) == 0)
							{
								admin();
								break;
							}
							else 
							{
								admin_pswd_flag++;
								printf("please enter correct password\n");
							}	
						}
						else 
						{
							admin_pswd_flag++;
							printf("please enter user name \n");
						}
						
						if(admin_pswd_flag == 3)
						{
							printf("Too many attempts please try again\n");
							break;
						}
					}
				break ;
			case 2:
				//printf("coordinator");
				Coordinator() ;
				break ;
			case 3: 
				Contestant();
				break ;
			case 0:
				exit(0);
				break;
			default: printf("invalid choice");
		}	
	}			
}
//Reading data of admin from file
admin_data read_admin_file(admin_data source)
{
	char *str = "admin_info.txt";
	FILE *fptr = NULL ;
	char *piece ;
	char buffer[QUESTION_BUFFER_SIZE];
	int index = 1;
	fptr = fopen(str,"r");
	if(fptr == NULL)
	{
		printf("%s file opening error\n",str);
	}	
	else 
	{
		while(!feof(fptr))
		{
			if(!(fgets(buffer,QUESTION_BUFFER_SIZE,fptr)))
			{
				//printf("string reading is fail\n");
				break ;
			}
			else 
			{
				piece = strtok(buffer,",");
				while(piece !=NULL)
				{
					//printf("str :%s\n",piece);
					if(index == 1)
					{
						strcpy(source.user_name ,piece );
						source.user_name[strlen(source.user_name)] = '\0';
						index = 2;	
					}
					else if(index == 2)
					{
						strcpy(source.pswd ,piece );
						source.pswd[strlen(source.pswd)-1] = '\0';
					}
					piece = strtok(NULL,",");
				}
			}	
			
		}
	}
	return source ;	
}	

/*int get_int_ans(int n , int m)
{
	char temp[10];
	int ch;
	while(1)
	{
		getchar();
		
		fgets(temp,10,stdin);
		temp[strlen(temp)] = '\0';
		
		if(intiger_validation(temp) == 0)
		{
			ch = atoi(temp);
			if(ch >= n && ch <= m)
			{
				ch = atoi(temp);
				return ch ;
			}
			else 
				printf("enter number with range of %d to %d \n",n , m);
			
		}
		else
			printf("enter valid input\n");
	}
}*/

