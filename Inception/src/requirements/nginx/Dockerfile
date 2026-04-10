FROM debian:bookworm

RUN apt-get update && apt-get install -y nginx openssl

# Creazione cartella per i certificati
RUN mkdir -p /etc/nginx/ssl

# Generazione certificato auto-firmato (per il protocollo TLS)
RUN openssl req -x509 -nodes -out /etc/nginx/ssl/inception.crt -keyout /etc/nginx/ssl/inception.key -subj "/C=IT/ST=Florence/L=Florence/O=42/OU=42/CN=xhamzall.42.fr/UID=xhamzall"

#cancella cartella di default (port 80)
RUN rm -rf /etc/nginx/sites-enabled/default

# Copia della tua configurazione personalizzata
COPY conf/nginx.conf /etc/nginx/conf.d/default.conf

# Lancio di Nginx in primo piano (daemon off)
CMD [ "nginx", "-g", "daemon off;" ]
