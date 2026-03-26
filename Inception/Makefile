# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: xhamzall <xhamzall@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/03/26 20:35:23 by xhamzall          #+#    #+#              #
#    Updated: 2026/03/26 21:15:41 by xhamzall         ###   ########.fr        #
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
	@mkdir -p $(DATA_PATH)/mariadb
	@mkdir -p $(DATA_PATH)/wordpress
	@chmod 777 $(DATA_PATH)/mariadb
	@chmod 777 $(DATA_PATH)/wordpress

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

#Clean up
clean: down
	@echo "Cleanup of the containers and networks..."
	@sudo docker system prune -af

fclean: clean
	@echo "Total cleanup: included the volumes and databese..."
	@sudo docker volume rm $(sudo docker volume ls -q) || true
	@sudo rm -rf $(DATA_PATH)

re: fclean all

.PHONY: all setup build up down stop start clean fclean re
