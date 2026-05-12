# Resumen de Git

## Configuración inicial

Antes de empezar a trabajar con Git, es recomendable configurar tu nombre de usuario y correo electrónico:

```bash
git config --global user.name "Tu Nombre"
git config --global user.email "tunombre@ejemplo.com"
```
Esto se guarda en la configuración global de Git para identificar quién hace los commits.

## git clone
Se usa para clonar repositorios remotos en tu máquina local.

```bash
git clone https://github.com/damrcorba/Informatica-2
```
Esto creará una carpeta llamada Informatica-2 con todo el contenido del repositorio.

## git add .
Se usa para agregar todos los archivos modificados al área de staging.

```bash
git add .
```
También podés agregar archivos específicos:

```bash
git add archivo.txt
git commit -am "Comentario"
```
Se usa para guardar los cambios en el historial del repositorio con un mensaje descriptivo.

```bash
git commit -am "Agrego nueva funcionalidad al formulario"
```
Nota: la opción -a agrega automáticamente archivos que ya estaban siendo trackeados (seguimiento activo). Para archivos nuevos, se necesita git add primero.

## git push
Se usa para subir los cambios locales al repositorio remoto.

```bash
git push origin main
```
En este ejemplo se están subiendo los cambios a la rama main en el repositorio remoto llamado origin.

## git pull
Se usa para traer y fusionar los cambios del repositorio remoto a tu rama local.

```bash
git pull origin main
```
Esto asegura que estás trabajando con la versión más actualizada del repositorio remoto.

## git branch
Muestra las ramas existentes o crea una nueva rama.

```bash
git branch          # Lista las ramas
git branch nueva-funcionalidad   # Crea una nueva rama
git checkout
```
Se usa para cambiar entre ramas o volver a una versión anterior.

```bash
git checkout main                # Cambia a la rama main
git checkout -b fix-error-login # Crea y cambia a una nueva rama llamada fix-error-login
```
Ejemplo de flujo básico
```bash
# Clonar el repo
git clone https://github.com/usuario/proyecto.git
cd proyecto

# Crear nueva rama
git checkout -b nueva-feature

# Hacer cambios y guardar
git add .
git commit -am "Agrego nueva feature"

# Subir cambios
git push origin nueva-feature
```