secuenceAlignment.o:
	gcc -std=c99 ../secuenceAlignment.c -o secuenceAlignment.o -c

main.o:
	gcc -std=c99 ../main.c -o main.o -c

iofile.o:
	gcc -std=c99 ../iofile.c -o iofile.o -c

ioperipherals.o:
	gcc -std=c99 ../ioperipherals.c -o ioperipherals.o -c

secuenceGenerator.o:
	gcc -std=c99 ../secuenceGenerator.c -o secuenceGenerator.o -c

compile:
	make clean
	make subcompile

subcompile: secuenceAlignment.o main.o iofile.o ioperipherals.o secuenceGenerator.o
	gcc -std=c99 -o DNASecuenceAlignment secuenceAlignment.o main.o iofile.o
	gcc -std=c99 -o DNASecuenceGenerator secuenceAlignment.o iofile.o ioperipherals.o secuenceGenerator.o
clean:
	rm -rf DNA*
	rm -rf *.o
