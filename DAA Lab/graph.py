import pandas as pd
import matplotlib.pyplot as plt

# Read the CSV file
file_name = "benchmark_results.csv"
data = pd.read_csv(file_name)

# Extract data for plotting
array_sizes = data["Array Size"]
merge_sort_times = data["Merge Sort (microseconds)"]
bubble_sort_times = data["Bubble Sort (microseconds)"]

# Plot the data
plt.figure(figsize=(10, 6))
plt.plot(array_sizes, merge_sort_times, label="Merge Sort", marker='o')
plt.plot(array_sizes, bubble_sort_times, label="Bubble Sort", marker='o')

# Add labels, title, and legend
plt.xlabel("Array Size", fontsize=14)
plt.ylabel("Time (no of operations)", fontsize=14)
plt.title("Sorting Algorithm Performance Comparison", fontsize=16)
plt.legend(fontsize=12)
plt.grid(True, linestyle='--', alpha=0.7)

# Save the plot as an image
plt.savefig("sorting_comparison_graph.png", dpi=300)

# Show the plot
plt.show()
