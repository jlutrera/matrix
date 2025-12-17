# Enter the Matrix – Linear Algebra in C++

Implementación completa en C++ del módulo **Enter the Matrix** de la escuela 42, una introducción práctica al álgebra lineal basada en vectores, matrices y sus operaciones fundamentales.

Este proyecto sigue las especificaciones del subject oficial, respetando las restricciones de código, complejidad y diseño.

---

## 📘 Objetivo del proyecto

El propósito de este repositorio es construir, desde cero:

- Una clase `Vector`
- Una clase `Matrix`

Ambas deben permitir realizar operaciones fundamentales del álgebra lineal sin utilizar librerías matemáticas externas.

El proyecto evoluciona ejercicio a ejercicio, introduciendo conceptos como combinaciones lineales, interpolación, producto escalar, norma, coseno, producto vectorial, multiplicación de matrices, determinante, inversa, rango, etc.

---

## 📂 Estructura del repositorio

- `ex00/` a `ex06/`: Directorios que contienen la implementación de cada ejercicio del proyecto.


---

## ✅ Funcionalidades implementadas

### **Vector**
- Suma y resta
- Multiplicación por escalar
- Combinación lineal
- Producto escalar
- Norma
- Coseno entre vectores
- Producto vectorial (3D)
- Impresión formateada

### **Matrix**
- Suma y resta
- Multiplicación por escalar
- Multiplicación matriz–vector
- Multiplicación matriz–matriz
- Transpuesta
- Traza
- Determinante
- Inversa
- Rango
- Impresión con:
  - columnas alineadas
  - corchetes Unicode
  - colores ANSI
  - **fila vacía final para mejorar la visualización**

---

## 🧪 Tests automáticos (GoogleTest)

El proyecto incluye un entorno de testing basado en **GoogleTest**.

### Ejecutar los tests

```bash
make run
```

## 🛠️ Compilación
El Makefile soporta:

- Compilación estándar (make)

- Limpieza (make clean)

- Limpieza total (make fclean)

- Recompilación (make re)

- Tests (make run)

- Modo debug (make debug)

Todos los objetos se generan en la carpeta obj/.
