objs =  main.o tcp_server.o udp_server.o 
main:$(objs)
	$(CC) $^ -o $@


clean:
	@echo "cleanning project"
	-rm main *.o
	@echo "clean completed"

.PHONY: clean
