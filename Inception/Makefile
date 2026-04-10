# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: xhamzall <xhamzall@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/03/26 20:35:23 by xhamzall          #+#    #+#              #
#    Updated: 2026/04/10 02:18:50 by xhamzall         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#Varibles
Name = Inception
USER_LOGIN = xhamzall
DATA_PATH = /home/$(USER_LOGIN)/data
DOCKER_COMPOSE = sudo docker compose -f src/docker-compose.yml

all: setup build up

setup:
	@echo "Preparing of the folders in DATA_PATH..."
	@sudo mkdir -p $(DATA_PATH)/mariadb
	@sudo mkdir -p $(DATA_PATH)/wordpress
	@sudo chmod 777 $(DATA_PATH)/mariadb
	@sudo chmod 777 $(DATA_PATH)/wordpress

build:
	@echo "Building the images..."
	@$(DOCKER_COMPOSE) build

up:
	@echo "Starting containers in background..."
	@$(DOCKER_COMPOSE) up -d

down:
	@echo "Shoutdon of containers..."
	@$(DOCKER_COMPOSE) down

stop:
	@$(DOCKER_COMPOSE) stop

start:
	@$(DOCKER_COMPOSE) start
db_shell:
	@sudo docker exec -it mariadb mariadb -u $(MYSQL_USER) -p
#Clean up
clean: down
	@echo "Cleanup of the containers and networks..."
	@sudo docker system prune -af

fclean: clean
	@if [ $$(sudo docker volume ls -q | wc -l) -gt 0 ]; then \
		sudo docker volume rm $$(sudo docker volume ls -q); \
	fi
	@sudo rm -rf $(DATA_PATH)

re: fclean all

.PHONY: all setup build up down stop start clean fclean logs re
