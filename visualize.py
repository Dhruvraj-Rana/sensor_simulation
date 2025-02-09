import pandas as pd
import matplotlib.pyplot as plt

# Load CSV data
df = pd.read_csv("data/sensor_data.csv")

# Plot sensor temperatures
plt.figure(figsize=(12, 6))
plt.plot(df["Time"], df["Thermoelectric"], label="Thermoelectric", linestyle="dotted")
plt.plot(df["Time"], df["Thermoresistive"], label="Thermoresistive", linestyle="dashed")
plt.plot(df["Time"], df["Thermo-Optical"], label="Thermo-Optical", linestyle="solid")
plt.plot(df["Time"], df["Thermo-Acoustic"], label="Thermo-Acoustic", linestyle="dashdot")
plt.plot(df["Time"], df["Avg Temp"], label="Average Temp", linewidth=2, color="black")

# Highlight control actions
for i, action in enumerate(df["Action"]):
    if action == "Fan ON":
        plt.axvline(x=i, color="red", alpha=0.3)
    elif action == "Heater ON":
        plt.axvline(x=i, color="blue", alpha=0.3)

plt.xlabel("Time")
plt.ylabel("Temperature (°C)")
plt.title("Temperature Sensor Readings Over Time")
plt.legend()
plt.grid()
plt.show()
