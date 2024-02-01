# Filter-less

## A problem set file helper.c implements already given functions to manipulate bits of images.

	FLAGS: -g grayscale -s sepia -r reflect -b blur.
	Usage: ./filter FLAG input_file(*.bmp) output_file(*.bmp)
	make filter - Makefile exists
	./filter -g images/yard.bmp images/grey.bmp - Produces a grayscale image of the yard.bmp file
	./filter -s images/stadium.bmp images/sepia.bmp - Produces a speia image of the stadium.bmp file
	./filter -r images/tower.bmp images/reflect.bmp - Reflects bytes from the right to left and vice versa from the tower.bmp
	./filter -b images/courtyard.bmp images/blur.bmp - blurs the courtyard image.
