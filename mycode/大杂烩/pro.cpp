#include <iostream>
#include <stdlib.h>
#include <string.h>
using namespace std;
void char2Hex(unsigned char c ) 
{ 
		char ch = c/0x10 + '0'; 
		if( ch > '9' )
			ch += ('A'-'9'-1); 

	    char cl = c%0x10 + '0'; 
		if( cl > '9' ) 
			cl += ('A'-'9'-1); 
		
		cout << ch << cl << ' '; 
        
}

int main(int argc, char *argv[])
{	
        char str[] = "I love 中国";  
		for( size_t i=0; i<strlen(str); ++i )  
		    char2Hex( str[i] ); 
		cout << endl;
		return 0;
}
