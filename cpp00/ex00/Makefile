NAME			=		megaphone

CC				=		c++
FLAGS			=		-Wall -Wextra -Werror -std=c++98
RM				=		rm -rf

OBJECT_PATH		=		object/

SOURCE			=		megaphone.cpp

OBJECT			=		$(patsubst %.cpp, $(OBJECT_PATH)%.o, $(SOURCE))

all:					$(NAME)

$(OBJECT_PATH)%.o:		%.cpp
						mkdir -p $(dir $@)
						$(CC) $(FLAGS) -c $< -o $@

$(NAME):				$(OBJECT)
						$(CC) $(FLAGS) $(OBJECT) -o $@

clean:
						@$(RM) $(OBJECT_PATH)

fclean:					clean
						@$(RM) $(NAME)

re:						fclean all

.PHONY:					all bonus clean fclean re
