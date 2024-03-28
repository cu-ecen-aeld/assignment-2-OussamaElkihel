#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <syslog.h>
#include <errno.h>
#include <string.h>


int main(int argc, char *argv[]){
	//open the file
	int fd;
	fd = open(argv[1], O_WRONLY);
	//setup the syslog
	openlog(NULL, LOG_CONS, LOG_USER);
	if(argc < 2){
	syslog(LOG_ERR, "Invalid number of arguments");
	return 1;
	}
	else if(argv[2] == NULL){
	syslog(LOG_ERR, "Error: Please specify WriteStr");
	return 1;
	}
	if(fd == -1){
	syslog(LOG_ERR, "Unable to open file");
	printf("Error opening file: %s\n", strerror(errno));
	}
	else{
	syslog(LOG_DEBUG, "Writing %s to %s", argv[2], argv[1]);}
	//write to file
	ssize_t nr;
	nr = write(fd, argv[2], strlen(argv[2]));
	if(nr == -1){
	syslog(LOG_ERR, "Unable to write to file");}
	int cl = close(fd);
	if(cl == -1){
	syslog(LOG_ERR, "Unable to close file");}
	closelog();
}
