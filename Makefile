NAME = philo

CC = clang 
CFLAGS = -Wall -Werror -Wextra 

HEADER = $(addprefix $(INCLUDES_PATH)/, philo.h)

OBJECTS_PATH = ./objects
SOURCES_PATH = ./sources
INCLUDES_PATH = ./includes

SOURCES_FILES =	main.c 


SOURCES = $(addprefix $(SOURCES_PATH)/, $(SOURCES_FILES))

OBJECTS = $(addprefix $(OBJECTS_PATH)/, $(subst .c,.o,$(SOURCES_FILES)))

SAFE_MAKEDIR = mkdir -p
REMOVE = rm -rf 

all: $(NAME)

$(NAME): $(OBJECTS) 
	$(CC) $(OBJECTS) -o $(NAME) -I $(INCLUDES_PATH)

$(OBJECTS_PATH)/%.o: $(SOURCES_PATH)/%.c $(HEADER)
	$(SAFE_MAKEDIR) $(OBJECTS_PATH)
	$(CC) $(CFLAGS) -I $(INCLUDES_PATH) -o $@ -c $< 

re: fclean all 

clean: 
	$(REMOVE) $(OBJECTS_PATH)

fclean: clean
	$(REMOVE) $(NAME)

.PHONY: all re clean fclean 