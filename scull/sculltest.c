#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <error.h>
#include <fcntl.h>
#include <string.h>
#include <sys/types.h>

int main()
{
	int fp, len;
	char bufferin[40];
	char bufferout[40] = "Abin scull device test!";
	
	fp = open("/dev/scull0", O_WRONLY);
	if(fp < 0) {
		printf("Failed to open the scull for writing!\n");
		exit(1);
	}
	len = write(fp, bufferout, strlen(bufferout)+1);
	if(len < 0) {
		printf("Error while writing to the device! \n");
		close(fp);
		exit(1);
	}
	printf("Wrote %d bytes to the device! \n", len);
	close(fp);
	fp = open("/dev/scull0", O_RDONLY);
	if( fp < 0) {
		printf("Error opening the device for reading \n");
		exit(1);
	}
	len = read(fp, bufferin, len);
	if (len < 0) {
		printf("Error reading from the device! \n");
		close(fp);
		exit(1);
	}
	printf("Read %d bytes from the device! \n", len);
	printf("%s \n", bufferin);
}
