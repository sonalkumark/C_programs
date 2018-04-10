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
  printf("p is %s",p);
  q=strtok(NULL,"->");
  printf("q is %s",q);
  s=strtok(q,"|");
  printf("s is %s\n",s);
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
              printf("temp2 is %s\n",temp2);
            break;
        }
    }
    strcat(temp2,&r[j][x]);
  }
  
  printf("\n");
  printf("temp is %s\n",temp);
  for(j=0;j<=ri;j++)
  {
    printf("%s\n",r[j]);
  }
  printf("temp2 is %s\n",temp2);
  
  s=strtok(temp2,"|");
  printf("s is %s\n",s);
  
  while(s!=NULL)
  {
    sprintf(temp3[++temp3i],"%s",s);
    s=strtok(NULL,"|");

  }
  for(j=0;j<=temp3i;j++)
  {
    sprintf(g,"%s*%s|",p,&temp3[j]);
    strcat(h,g);
  }
  printf("\n");
  sprintf(newprod[++newprodi],"%s->%s",p,h);
    sprintf(newprod[++newprodi],"%s*->%s",p,temp);
    
    printf("Result is \n");
  for(j=0;j<=newprodi;j++)
  {
    printf("%s\n",newprod[j]);
  }
  
  return 0;
}
