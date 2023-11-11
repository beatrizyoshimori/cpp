NAME			=		phonebook

CC				=		c++
FLAGS			=		-Wall -Wextra -Werror -std=c++98
RM				=		rm -rf

OBJECTS_PATH	=		objects/

SOURCES			=		main.cpp \
						PhoneBook.cpp \
						Contact.cpp

OBJECTS			=		$(patsubst %.cpp, $(OBJECTS_PATH)%.o, $(SOURCES))

all:					$(NAME)

$(OBJECTS_PATH)%.o:		%.cpp
						@mkdir -p $(dir $@)
						@$(CC) $(FLAGS) -c $< -o $@

$(NAME):				$(OBJECTS)
						@$(CC) $(FLAGS) $(OBJECTS) -o $@
						@echo "\033[32mPhonebook compiled!"

clean:
						@$(RM) $(OBJECTS_PATH)

fclean:					clean
						@$(RM) $(NAME)

re:						fclean all

.PHONY:					all bonus clean fclean re
