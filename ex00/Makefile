NAME= btc
CC= c++
CFLAGS= -Wall -Wextra -Werror -std=c++98

MAIN= main.cpp

NAMES= BitcoinExchange
SRC= $(addsuffix .cpp, $(NAMES))
OBJ= $(addsuffix .o, $(NAMES))
INC= $(addsuffix .hpp, $(NAMES))


all: $(NAME)

$(NAME): $(OBJ) $(MAIN)
	$(CC) $(CFLAGS) $(MAIN) $(OBJ) -o $(NAME)


%.o: %.cpp $(INC) 
		$(CC) $(CFLAGS)  -c -o $@ $<

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all
