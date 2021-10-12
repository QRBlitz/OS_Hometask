#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/resource.h>

#define MB (1024*1024)

int main()
{
	int *data = NULL;
	size_t size = 0;
	struct rusage usage;
	for(int i=0; i<10; i++)
	{
		size += 10*MB;
		data = realloc(data, size);
		if(data == NULL)
		{
			printf("Error occured!\n");
			exit(1);
		}
		memset(data, 0, size);
		
		getrusage(RUSAGE_SELF, &usage);
		printf("| %ld | %ld | %ld | %ld | %ld |\n",
			usage.ru_utime.tv_usec,
			usage.ru_stime.tv_usec,
			usage.ru_minflt,
			usage.ru_majflt,
			usage.ru_nvcsw + usage.ru_nivcsw
		);
		
		sleep(1);
	}
	free(data);
	
	return 0;
}
