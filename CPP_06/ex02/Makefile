exec = RealType
src = *.cpp
src_obj = $(exec.c=.o)
cc = c++
flags = -Wall -Wextra -std=c++98

all: $(exec)

$(exec): $(src_obj)
	$(cc) $(flags) $(src) -I./ -o $(exec)

fclean: clean
	rm -f $(exec)

re: fclean all

.PHONY: all clean fclean
