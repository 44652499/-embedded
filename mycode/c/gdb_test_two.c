#include <stdio.h>
#include <pthread.h>
#include <string.h>
#include <stdlib.h>
#define N  5
typedef struct pthread_arg
{
	int *array;
	int len;
	union {
		int a;
		int b;
	}u;
}pthread_arg;

// int call_function (int n) {
// 	while (n) {
// 		printf("call_function running\n");
// 		n--;
// 	}
// 	printf("call_function will return\n");
// 	return n;
// }

// void macro_function () {
// 	printf("macro value:%d\n", N);
// }

// int watch_function (int n) {
// 	int count = 0;
// 	while ( n ) {
// 		n = n & ( n - 1 );
// 		count++;
// 	}
// 	return count;
// }

// void display_function () {
// 	int n = 5;
// 	while (n) {
// 		n--;
// 	}
// 	return;
// }

// int print_function (int n) {
// 	printf("****************************************\n");
// 	printf("函数实现：n这个数转换为二进制有多少位为1\n");
// 	printf("****************************************\n");
// 	int count = 0;
// 	while (n) {
// 		n = n & ( n - 1 );
// 		count++;
// 	}
// 	return count;
// }

int* array_function (int len) {
	int i = 0;
	int* array = (int*) malloc ( len * sizeof (int) );
	if ( array == NULL ) {
		printf("malloc array fail\n");
		exit(-1);
	}
	for ( i = 0 ; i < len ; i++ ) {
		array[i] = i + 1;
	}
	return array;
}

pthread_arg pthread_arg_function (int* array, int len) {
	pthread_arg p_arg;
	bzero( &p_arg, sizeof(p_arg) );
	p_arg.array = array;
	p_arg.len = len;
	return p_arg;
}

void* pthread_function (void* arg) {
	pthread_arg p_arg = *(pthread_arg*)arg;
	int i;
	int len = p_arg.len;
	for ( i = 0 ; i < len ; i++ ) {
		printf("%d ", p_arg.array[i]);
	}
	printf("\n");
}

int main(int argc, char const *argv[])
{
	int n;
	n = atoi (argv[1]);
	// int count = watch_function (n);
	// display_function ();

	// count = print_function (n);
	int* array = array_function (n);
	//macro_function ();
	pthread_arg p_arg = pthread_arg_function (array, n);
	pthread_t pthread;
	int ret = pthread_create ( &pthread, NULL, pthread_function, (void*)&p_arg );
	if ( ret == -1 ) {
		printf("pthread_create pthread1 fail\n");
		exit(-1);
	}
	pthread_join (pthread, NULL);
	return 0;
}
