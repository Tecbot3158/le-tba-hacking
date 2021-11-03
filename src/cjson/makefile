EXECUTABLE=filter.x
main:
	cc -lcurl -lcjson main.c downloader/tba_downloader.c -o $(EXECUTABLE)
all: main run

run:
	./$(EXECUTABLE)
