# Docker Examples

Este repositorio contiene **ejemplos diversos relacionados con Docker**,
principalmente varios Dockerfiles y proyectos de ejemplo para
experimentar con contenedores y distintas formas de construir imágenes.

## Estructura del repositorio

El repositorio está compuesto por:

### Directorios con ejemplos

-   `cgroups/` --- Ejemplo o configuración relacionada con grupos de
    control (cgroups).
-   `docker-example/` --- Ejemplo genérico de Docker con su propio
    Dockerfile.
-   `docker-nginx/` --- Dockerfile para ejecutar Nginx.

### Dockerfiles en la raíz

Estos Dockerfiles muestran distintas formas de crear imágenes Docker:

-   `Dockerfile.simplest` --- Dockerfile mínimo para una imagen muy
    simple.
-   `Dockerfile_apache_v1` --- Dockerfile que levanta Apache.
-   `Dockerfile_noroot` --- Dockerfile configurado para no ejecutar como
    usuario root.
-   `Dockerfile_optimizado` --- Dockerfile con optimizaciones básicas.
-   `Dockerfile_optimizado_hijo` --- Variante optimizada basada en una
    imagen padre.
-   `Dockerfile_sinoptimizar` --- Dockerfile no optimizado para
    comparativas.

Puedes explorar cada uno de estos archivos y carpetas para ver distintos
patrones y técnicas de uso de Docker.

## Propósito del repositorio

Este repositorio se creó para:

-   Proporcionar ejemplos prácticos de Dockerfiles y enfoques de
    construcción de contenedores.
-   Servir como referencia de distintas maneras de construir imágenes
    Docker, desde lo más simple hasta variantes optimizadas.
-   Permitir la comparación entre buenas y malas prácticas al escribir
    Dockerfiles.

No está ligado a un único proyecto concreto, sino a una colección de
ejemplos útiles para aprendizaje y pruebas.

## Cómo usar los ejemplos

1.  Clona este repositorio:

    git clone https://github.com/dgarridouma/docker.git

2.  Dirígete al directorio o al Dockerfile que quieres usar:

    cd docker/`<directorio-o-ruta>`{=html}

3.  Construye la imagen Docker desde ese contexto:

    docker build -t nombre-de-la-imagen .

4.  Ejecuta un contenedor basado en esa imagen:

    docker run -it --rm nombre-de-la-imagen

Estos pasos son generales y pueden necesitar adaptarse para cada ejemplo
particular (por ejemplo, exponiendo puertos o montando volúmenes según
lo requiera la aplicación).
