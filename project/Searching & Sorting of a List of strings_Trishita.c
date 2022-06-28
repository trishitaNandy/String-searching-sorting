#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int search(char str[25][25], int n);
int alphabetical_sort(char str1[25][25],char temp1[25],int n1);
int alphabetical_sort_reverse(char str1[25][25],char temp1[25],int n1);
int sort_by_number_of_characters(char str1[25][25],char temp1[25],int n1);
int sort_by_number_of_characters_reverse(char str1[25][25],char temp1[25],int n1);

int main()
{
	int i,j,n,ch,ch1;
    char str[25][25],str3[25][25],temp[25], word[25];
    printf("\n How many names you want to enter?  ");
    scanf("%d",&n);
    printf("\n Enter strings:\n");
    for(i=0;i<=n;i++)
    {
        fgets(str[i],25,stdin);
        strcpy(str3[i],str[i]);
    }
        
    while(1)
	{  
	printf("\n");
	printf("\t* * * * * * * * * * * * * * * * * * * * * * * * * * * * * ");
    printf("\n\t* PRESS 1: Search					*");
	printf("\n\t* PRESS 2: Sort by Alphabetical order	             	*");
	printf("\n\t* PRESS 3: Sort by Reverse Alphabetical order		*");
	printf("\n\t* PRESS 4: Sort by increasing number of characters	*");
	printf("\n\t* PRESS 5: Sort by decreasing number of characters	*");
	printf("\n\t* PRESS 6: Exit						*\n");
	printf("\t* * * * * * * * * * * * * * * * * * * * * * * * * * * * *\n ");
	
	printf("\n\tEnter your choice:   ");
	scanf("%d",&ch);
	
	
		switch(ch)
		{
			case 1:		
    				search(str,n);
					break;
    		case 2:		
    				printf("\n Sort by Alphabatical order->");  
    				alphabetical_sort(str3,temp,n);
    				break;
    		case 3:		
    				printf("\n Sort by Reverse Alphabatical order->\n");
    				alphabetical_sort_reverse(str3,temp,n);
    				break;
    		case 4:	
					printf("\n Sort by increasing number of characters is->");
    				sort_by_number_of_characters(str3,temp,n);
    				break;	
    				
    		case 5: 
					printf("\n Sort by decreasing number of characters is->\n");
    				sort_by_number_of_characters_reverse(str3,temp,n);
    				break;		
    		case 6: 
					exit(0);
    		default:
					printf("\n Wrong choice!!\n");
		}
		
	}
}

int search(char str[25][25], int n)
{
	int i,j,k,found,count=0;
	char word[25],word1[25],word2[25],str1[25][25],str2[25][25];
		
	for(i=1;i<=n;i++)	
	{
		strcpy(str2[i],str[i]);
		strcpy(str1[i],strlwr(str[i]));
	}
		
	printf("\n Enter any word to search: ");
    scanf("%s",&word);
    printf("\n");
    strcpy(word2,word);
    strcpy(word1,strlwr(word));
	for(i=1; i<=n; i++)
    {
		for(j=0;j<strlen(str[i])-strlen(word);j++)
        {
        	found = 1;
        	for(k=0; k<strlen(word); k++)
        	{
            	if(str1[i][j + k] != word1[k])
            	{
					found=0;
                	break;
            	}
        	}
        	
        	if(found ==1)		
        	{
            	printf(" '%s' found in the line %d in the name:	%s\n", word2,i, str2[i]);
            	count++;
            	break;
        	}      
		}
	}
	if(count==0)		
	printf(" Not Found\n");
    return 0;
}
int alphabetical_sort(char str1[25][25],char temp1[25],int n1)
{
    int i,j;
    for(i=0;i<=n1;i++)
      for(j=i+1;j<=n1;j++)
      {
         if(strcmp(str1[i],str1[j])>0)
         {
            strcpy(temp1,str1[i]);
            strcpy(str1[i],str1[j]);
            strcpy(str1[j],temp1);
         }
      }
   for(i=0;i<=n1;i++)
      printf("%s",str1[i]);

}
int alphabetical_sort_reverse(char str1[25][25],char temp1[25],int n1)
{
	 int i,j;
    for(i=0;i<=n1;i++)
      for(j=i+1;j<=n1;j++)
      {
         if(strcmp(str1[j],str1[i])>0)
         {
            strcpy(temp1,str1[i]);
            strcpy(str1[i],str1[j]);
            strcpy(str1[j],temp1);
         }
      }
   for(i=0;i<=n1;i++)
      printf("%s",str1[i]);
}
int sort_by_number_of_characters(char str1[25][25],char temp1[25],int n1)
{
	int i,j;
	for(i=0;i<=n1;i++)
      for(j=i+1;j<=n1;j++)
		{
	  		if(strlen(str1[i])>strlen(str1[j]))
	  		{
	  			strcpy(temp1,str1[i]);
            	strcpy(str1[i],str1[j]);
            	strcpy(str1[j],temp1);
			}
	    }
	 for(i=0;i<=n1;i++)
      printf("%s",str1[i]);		
}
int sort_by_number_of_characters_reverse(char str1[25][25],char temp1[25],int n1)
{
	int i,j;
	for(i=0;i<=n1;i++)
      for(j=i+1;j<=n1;j++)
		{
	  		if(strlen(str1[i])<strlen(str1[j]))
	  		{
	  			strcpy(temp1,str1[i]);
            	strcpy(str1[i],str1[j]);
            	strcpy(str1[j],temp1);
			}
	    }
	 for(i=0;i<=n1;i++)
      printf("%s",str1[i]);		
}
