all:
	g++ fget.cpp -o fget
	g++ fput.cpp -o fput
	g++ main.cpp -o main
	g++ getacl.cpp -o getacl
	g++ setacl.cpp -o setacl
	g++ create_dir.cpp -o create_dir
	chmod +s fget
	chmod +s fput
	chmod +s getacl
	chmod +s setacl
	chmod +s create_dir
	cp main simple_slash/home/azim/main
	cp main simple_slash/home/bill/main
	cp main simple_slash/home/larry/main
	cp main simple_slash/home/mark/main
	cp main simple_slash/home/mukesh/main
	cp main simple_slash/home/steve/main
