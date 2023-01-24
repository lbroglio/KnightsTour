KnightsTour: KnightsTour.c
	gcc KnightsTour.c -o KnightsTour
	rm foundTours.txt
	
clean:
	rm -f KnightsTour foundTours.txt
