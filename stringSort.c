// qsort() in Array of Pointer to String 
 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 
int cmp(const void *, const void *);
 
int main (int argc, char const *argv[]) {
/*
    char *s[] = {
                   "Gaurav",
                   "Vaibhav",
					"XavierialioW",
					"XavierialioP",	                   
                   "Garima",
                   "Amit"
                };
*/
	int i = 0;
	char **s = (char**)malloc(3 * sizeof(char*));
	s[0] = (char*)malloc(10 * sizeof(char));
	s[1] = (char*)malloc(10 * sizeof(char));
	s[2] = (char*)malloc(10 * sizeof(char));
	while( i < 3 ){
		scanf("%s",s[i]);
		i = i + 1;
	}
	
    printf("SIZE du TABLEAU: \t%d\n",sizeof(*s));             
    qsort( (char*)s, 3, sizeof(s[0]), cmp);
     
    i = 0;
    while(i<3)
    {
        printf("%s\n",s[i]);
        i++;      
    }
              
	return 0;       
}
 
int cmp(const void *x, const void *y)
{
    return(strcmp(*((char**)x),*((char**)y)));       
}

