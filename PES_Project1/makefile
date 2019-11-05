DEP_HEADER = help_function.h\
			 parse_function.h\
			 allocate.h\
			 comparison.h\
			 free_mem.h\
			 random_gen.h\
			 write_mem.h\
			 display_mem.h\
			 p_write.h\
			 p_verify.h\
			 invert.h\
			 wait_for_yes.h

C_FILES = main.c \
		help_function.c \
		parse_function.c \
		comparison.c \
		allocate.c \
        free_mem.c \
     	random_gen.c\
		write_mem.c\
		display_mem.c\
		p_write.c\
		p_verify.c\
		invert.c\
		wait_for_yes.c

#to allow make flexibility these are the only places these values need to be updated

%.o: %.c $(DEP_HEADER)
	gcc -c -o $@ $< -I.
#indicates that object and c files depend on the header file

project1_run: $(C_FILES)
	gcc -o $@ $^ -I.
#	gcc -o project1_run main.c help_function.c parse_function.c comparison.c -I.
#	the FILES variable list all c programs to help insertion into project

clean:
	rm -f .o run.txt project1_run
#cleans the run.txt output and project1_run file to get a clean build

test: project1_run test.txt
	./project1_run < allocate_test.txt > run.txt
#inserts a test script to run an automated test for project1_run
#cs.colby.edu helped provide a tutorial for creating a make file
