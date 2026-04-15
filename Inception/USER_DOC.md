# USER_DOC.md — User Documentation

## Services Provided
The Inception stack provides a secure, self-hosted **WordPress** platform.
- **NGINX**: The web server providing secure access via HTTPS.
- **WordPress**: The Content Management System (CMS) for creating and managing content.
- **MariaDB**: The database storing all site data and users.

## How to Start and Stop
- **To Start**: Run `make all` from the root directory.
- **To Stop**: Run `make down` to pause the services without losing data.
- **To Reset**: Run `make fclean` to wipe all services and data.

## Accessing the Project
- **Website**: Open your browser and go to `https://xhamzall.42.fr`.
- **Admin Panel**: Go to `https://xhamzall.42.fr/wp-admin` to manage the site.
- **Security Note**: You will see a "Your connection is not private" warning because the SSL certificate is self-signed. Click **Advanced** and then **Proceed** to access the site.

## Credentials
Credentials for the WordPress Admin and the secondary user are stored in the `.env` file located in the `src/` directory. You can find the administrator username and password there to log in to the admin panel.

## Health Check
To verify that the services are running correctly, execute:
```bash
docker ps
