import pandas as pd
import matplotlib.pyplot as plt

# Read the CSV file
file_name = "benchmark_results.csv"
data = pd.read_csv(file_name)

# Extract data for plotting
array_sizes = data["Array Size"]
merge_sort_times = data["Merge Sort (microseconds)"]
bubble_sort_times = data["Bubble Sort (microseconds)"]

# Plot for Merge Sort
plt.figure(figsize=(10, 6))
plt.plot(array_sizes, merge_sort_times, label="Merge Sort", marker='o', color='blue')
plt.xlabel("Array Size", fontsize=14)
plt.ylabel("Time (microseconds)", fontsize=14)
plt.title("Merge Sort Performance", fontsize=16)
plt.grid(True, linestyle='--', alpha=0.7)
plt.legend(fontsize=12)
plt.savefig("merge_sort_graph.png", dpi=300)
plt.show()

# Plot for Bubble Sort
plt.figure(figsize=(10, 6))
plt.plot(array_sizes, bubble_sort_times, label="Bubble Sort", marker='o', color='red')
plt.xlabel("Array Size", fontsize=14)
plt.ylabel("Time (microseconds)", fontsize=14)
plt.title("Bubble Sort Performance", fontsize=16)
plt.grid(True, linestyle='--', alpha=0.7)
plt.legend(fontsize=12)
plt.savefig("bubble_sort_graph.png", dpi=300)
plt.show()
