exec = WorldOnFire
src = main.cpp Brain.cpp Animal.cpp
src_obj = $(exec.cpp=.o)
cc = c++
flags = -Wall -Wextra -Werror -std=c++98

all: $(exec)

$(exec): $(src_obj)
	$(cc) $(flags) $(src) -I./ -o $(exec)

fclean: clean
	rm -f $(exec)

re: fclean all

.PHONY: all clean fclean
