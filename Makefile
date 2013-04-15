all:
	gcc parta.c -o parta -lpthread
	gcc partb.c -o partb -lpthread
	gcc partc.c -o partc -lpthread
	gcc partd.c -o partd -lpthread
	
parta:
	gcc parta.c -o parta -lpthread

partb:
	gcc partb.c -o partb -lpthread
	
partc:
	gcc partd.c -o partd -lpthread
	
partd:
	gcc partd.c -o partd -lpthread

clean:
	rm parta
	rm partb
	rm partc
	rm partd
	
run: 
	gcc parta.c -o parta -lpthread
	gcc partb.c -o partb -lpthread
	gcc partc.c -o partc -lpthread
	gcc partd.c -o partd -lpthread
	./parta
	./partb
	./partc
	./partd