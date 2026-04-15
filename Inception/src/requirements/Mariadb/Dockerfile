FROM debian:bookworm

#install mariadb
RUN apt-get update && apt-get install mariadb-server -y

#create folder 
RUN mkdir -p /run/mysqld && chown -R mysql:mysql /run/mysqld
RUN chown -R mysql:mysql /var/lib/mysql
COPY ./50-server.cnf /etc/mysql/mariadb.conf.d/50-server.cnf
COPY ./Tools/mariadb.sh /bin/mariadb.sh
RUN chmod +x /bin/mariadb.sh
EXPOSE 3306

CMD ["mariadb.sh"]
