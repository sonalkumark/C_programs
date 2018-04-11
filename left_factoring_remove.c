#include <stdio.h>
#include<string.h>
//temp is common string
int main(void) {
  char input[25],*p,*q,*s,r[25][25],temp[25],temp2[25],temp3[25][25],newprod[25][25],h[25],g[25];
  int i=-1,ri=-1,j,x,flag=0,temp2i=-1,temp3i=-1,newprodi=-1;
  strcpy(temp,"");
  strcpy(h,"");
  printf("Enter production:");
  scanf("%s",input);
  p=strtok(input,"->");

  q=strtok(NULL,"->");

  s=strtok(q,"|");

  while(s!=NULL)
  {
    sprintf(r[++ri],"%s",s);
    s=strtok(NULL,"|");
  }
  for(j=1;j<=ri;j++)
  {
    for(x=0;;x++)
    {
	if(r[j-1][x]==r[j][x])
	{
	    flag=1;
	    sprintf(q,"%c",r[j][x]);
	    strcat(temp,q);
	}
	else
	{
	    strcat(temp2,&r[j-1][x]);
	    strcat(temp2,"|");
	    break;
	}
    }
    strcat(temp2,&r[j][x]);
  }
  if(flag==0)
    {    printf("No left factoring\n");

    }
    else{
	  printf("\n");
	  printf("temp is %s\n",temp);
	  for(j=0;j<=ri;j++)
	  {
	    printf("%s\n",r[j]);
	  }
	  printf("temp2 is %s\n",temp2);
	  printf("\n");

	    sprintf(newprod[++newprodi],"%s->%s%s*",p,temp,p);
	    sprintf(newprod[++newprodi],"%s*->%s",p,temp2);
	    printf("Result is \n");
	  for(j=0;j<=newprodi;j++)
	  {
	    printf("%s\n",newprod[j]);
	  }
    }
  return 0;
}
