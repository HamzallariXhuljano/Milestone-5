FROM debian:bookworm
RUN apt-get update && apt-get install mariadb-server -y
RUN mkdir -p /run/mysqld && chown -R mysql:mysql /run/mysqld
COPY 50-server.cnf /etc/mysql/mariadb.conf.d/50-server.cnf
COPY Tools/mariadb.sh /bin/mariadb.sh
RUN chmod +x /bin/mariadb.sh
EXPOSE 3306

CMD ["mariadb.sh"]
