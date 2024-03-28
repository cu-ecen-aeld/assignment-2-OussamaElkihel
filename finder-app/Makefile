
CROSS_COMPILE ?=
CFLAGS := 
CC := $(CROSS_COMPILE)gcc

writer: writer.c
	@echo "building the writer app"
	$(CC) $(CFLAGS) writer.c -o writer
	@echo "build successful"

clean:
	@echo "cleaning"
	@rm -f writer.o writer
	@echo "clean successful"

