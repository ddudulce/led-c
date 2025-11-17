import numpy as np
import matplotlib.pyplot as plt
from scipy.stats import norm
import re

# ---------------------------------------------------
# Cargar datos generados por el programa en C
# ---------------------------------------------------
def cargar_floats(path):
    floats = []
    patron = re.compile(r"-?\d+\.\d+")
    with open(path) as f:
        for linea in f:
            for match in patron.findall(linea):
                floats.append(float(match))
    return np.array(floats)

datos = cargar_floats("datos_yf.txt")

# Media y desviación
mu = np.mean(datos)
sigma = np.std(datos)

# ---------------------------------------------------
# Crear figura con dos subplots
# ---------------------------------------------------
plt.figure(figsize=(8,10))

# ============================
# Subplot 1: Histograma solo
# ============================
plt.subplot(2, 1, 1)
plt.hist(datos, bins=20, edgecolor='black')
plt.xlabel("Valor yf")
plt.ylabel("Frecuencia")
plt.title("Histograma de yf (solo barras)")

# ============================
# Subplot 2: Histograma + curva normal
# ============================
plt.subplot(2, 1, 2)

# Histograma normalizado
n, bins, _ = plt.hist(datos, bins=20, density=True, alpha=0.6, edgecolor='black', label="Histograma")

# Curva normal ajustada
x = np.linspace(min(datos), max(datos), 400)
gauss = norm.pdf(x, mu, sigma)
plt.plot(x, gauss, 'r', linewidth=2, label=f'Gaussiana ajustada\nμ={mu:.3f}, σ={sigma:.3f}')

plt.xlabel("Valor yf")
plt.ylabel("Densidad")
plt.title("Histograma + Ajuste Gaussiano")
plt.legend()

plt.tight_layout()
plt.savefig("resultado_histogramas.pdf")
plt.close()

print("Listo. Se generó el archivo: resultado_histogramas.pdf")