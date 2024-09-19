exec = JobOfYourDreams
src = *.cpp
src_obj = $(exec.c=.o)
cc = c++
flags = -Wall -Wextra -Werror -std=c++98

all: $(exec)

$(exec): $(src_obj)
	$(cc) $(flags) $(src) -I./ -o $(exec)

clean:
	rm -f $(src_obj)

fclean: clean
	rm -f $(exec)

re: fclean all

.PHON: all clean fclean

