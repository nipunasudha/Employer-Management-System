all:
	@g++ main.cpp HashTable.cpp LinkedList.cpp ManagementSystem.cpp People.cpp -o out && ./out

old98:
	@gcc -std=c++98  main.cpp HashTable.cpp LinkedList.cpp ManagementSystem.cpp People.cpp -o out && ./out
	
old03:
	@gcc -std=c++03  main.cpp HashTable.cpp LinkedList.cpp ManagementSystem.cpp People.cpp -o out && ./out
