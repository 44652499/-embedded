#include  <stdio.h>
/*#define PRINT1(a,b)  \
		{   \
            printf("print a\n"); \
            printf("print b\n"); \
		}

#define PRINT2(a,b)   \
		do{  \
			printf("print a\n"); \
			printf("print b\n"); \			
		} while (0);

#define PRINT(a)  \
		do{  \
            printf("%s:%d\n",#a,a);\
            printf("%d:%d\n",a,a); \
		}while(0)

#define TYPE1(type,name) type name_##type##_type
#define TYPE2(type,name) type name##_##type##_type
#define ERROR_LOG(module)  fprintf(stderr,"error: "#module"\n")
		int main(int argc, char const *argv[])
		{
			int a=20;
			int b=30;
			TYPE1(int,c);
			ERROR_LOG("add");
			name_int_type=a;
			TYPE2(int,d);
			d_int_type=a;

			PRINT(a);
			if(a>b)
			{
				PRINT1(a,b);
			}
			else
			{
				PRINT2(a,b);
			}
			return 0;
		}*/
/*
error: "add"
a:20
20:20
print a
print b

*/


#define f(a,b) a##b 
#define d(a) #a 
#define s(a) d(a) 

int main(int argc, char const *argv[])
{ 
    puts(d(f(a,b))); 
    puts(s(f(a,b)));
    return 0;
} 