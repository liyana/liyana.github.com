objs =  main.o tcp_client.o udp_client.o jiexi.o
main:$(objs)
	$(CC) $^ -o $@


clean:
	@echo "cleanning project"
	-rm main *.o
	@echo "clean completed"

.PHONY: clean
