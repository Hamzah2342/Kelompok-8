import math
import random

# Data kekuatan sinyal dari access points (contoh)
wifi_data = {
    "fathur": -45,  # Access Point 1
    "fakhran": -60,  # Access Point 2
    "hamzah": -50   # Access Point 3
}

# Fungsi untuk menghitung jarak berdasarkan RSSI (Received Signal Strength Indicator)
def rssi_to_distance(rssi, tx_power=-59):
    n = 2  # Faktor lingkungan (2 untuk indoor)
    return 10 ** ((tx_power - rssi) / (10 * n))

# Fungsi utama untuk menentukan posisi
def estimate_position(wifi_data):
    ap_positions = {
        "fathur": (0, 0),
        "fakhran": (10, 0),
        "hamzah": (5, 10)
    }
    x, y = 0, 0
    for ap, rssi in wifi_data.items():
        distance = rssi_to_distance(rssi)
        pos = ap_positions[ap]
        x += pos[0] / (distance + 0.1)  # Normalisasi untuk pembobotan
        y += pos[1] / (distance + 0.1)
    
    x /= len(wifi_data)
    y /= len(wifi_data)
    return x, y

# Estimasi posisi pengguna
user_position = estimate_position(wifi_data)
print("Perkiraan posisi pengguna:", user_position