#!/usr/bin/python
# -*- coding: utf-8 -*-

'''
Author: Echedey Luis Álvarez
Date: 2023-04-12
Subject: Robótica

File: precision_segun_pote.py

Abstract: cálculo de la precisión que ofrece el sistema de realimentación,
en grados/bit debido al potenciómetro multivuelta empleado y el ADC del
Arduino.
'''

# %%
# Imports
import numpy as np
import pandas as pd
import matplotlib.pyplot as plt
import scienceplots
from scipy.optimize import curve_fit
from scipy.interpolate import interp1d

# %%
# Rango del ADC, a partir del número de bits
adc_range = lambda bits: np.power(2, bits)
# Fórmula para el arco, conocido el ángulo en grados y el radio
arc_from_deg = lambda angle_deg, radius: np.deg2rad(angle_deg) * radius
# Fórmula rango que cambia el potenciómetro en n grados
# usamos el WDX3-13-2W que tiene 10 vueltas (3600º +- 20º)
# Se asume pote entre Gnd y Vcc, y ref analógica en Vcc
pot_range = lambda degs, adc_bits: degs / 3600 * adc_range(adc_bits)
# Giro del pote en func del giro de la articulación mediante
# relación de transmisión de la multiplicadora (giro articulación:giro pote)
pot_rotation = lambda rel_i, art_rotation: rel_i * art_rotation
# Grados de salida por cada bit del ADC
deg_out_from_bit = lambda pot_bits_range: 360 / pot_bits_range

# %%
# Condiciones del problema
bits_adc = 10  # Arduino UNO, MEGA
radius = 200  # mm

# %%
# Calcular precisiones para el rango de relaciones de transmisión
# Rangos rel. trans.
rel_i = np.linspace(0.5, 10, 50)
# Rotación del potenciómetro por vuelta articulación en func. rel. trans.
pot_rot_by_turn = pot_rotation(rel_i, 360)
# Rango en bits del potenciómetro para esa vuelta
pot_range_by_turn = pot_range(pot_rot_by_turn, bits_adc)
# Grados por un bit
degs_by_bit = deg_out_from_bit(pot_rot_by_turn)
# Distancia del arco por bit
arc_by_bit = arc_from_deg(degs_by_bit, 300)
# Número de vueltas que podría dar la articulación,
# teniendo en cuenta el máx de vueltas del pote
vueltas_articulacion = 10 / rel_i

# %%
plt.style.use(['science', 'no-latex', 'grid'])
fig, (ax1, ax2, ax3) = plt.subplots(ncols=3, sharex=True)
ax1.set_xlim((0.5, 10))

ax1.plot(rel_i, degs_by_bit)
ax1.set_xlabel('Relación de transmisión')
ax1.set_ylabel('Grados por bit de precisión $[\degree/b]$')

ax2.plot(rel_i, arc_by_bit)
ax2.set_xlabel('Relación de transmisión')
ax2.set_ylabel('Distancia arco por bit de precisión $[mm/b]$')

ax3.plot(rel_i, vueltas_articulacion)
ax3.set_xlabel('Relación de transmisión')
ax3.set_ylabel('Vueltas que puede dar la articulación')

plt.show()

# %%
pass
