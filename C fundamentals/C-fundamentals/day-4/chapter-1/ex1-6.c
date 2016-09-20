#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#ifndef LOG_LEVEL
#error LOG_LEVEL is not defined
#endif


#if LOG_LEVEL >= 1
#define LogError(M,...) (fprintf(stderr, "ERROR %s:%d " M "\n", __FILE__, __LINE__, ##__VA_ARGS__))
#else
#define LogError(M,...)
#endif

#if LOG_LEVEL >= 2
#define LogTrace(M,...) (fprintf(stderr, "TRACE %s:%d " M "\n", __FILE__, __LINE__, ##__VA_ARGS__))
#else
#define LogTrace(M,...) 
#endif

#if LOG_LEVEL >= 3
#define LogDebug(M,...) (fprintf(stderr, "DEBUG %s:%d " M "\n", __FILE__, __LINE__, ##__VA_ARGS__))
#else
#define LogDebug(M,...)
#endif

int main(int argc, char* argv[]){
	LogDebug("Errorrrrrr");
	return 0;
}
