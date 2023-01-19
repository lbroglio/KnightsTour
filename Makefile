KnightsTour:
	rm foundTours.txt
	gcc KnightsTour.c -o KnightsTour

clean:
	rm -f KnightsTour foundTours.txt
