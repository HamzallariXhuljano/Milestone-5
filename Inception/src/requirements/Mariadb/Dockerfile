FROM debian:bookworm
RUN apt-get update && apt-get install mariadb-server -y
COPY 50-server.cnf /etc/mysql/mariadb.conf.d/50-server.cnf
COPY Tools/mariadb.sh /bin/mariadb.sh
RUN chmod +x /bin/mariadb.sh
EXPOSE 3306

CMD ["mariadb.sh"]

