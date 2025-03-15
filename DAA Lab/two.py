import matplotlib.pyplot as plt
import pandas as pd

# Load the CSV file into a pandas DataFrame
data = pd.read_csv("results.csv")

# Extract the columns
array_sizes = data["ArraySize"]
brute_force_times = data["BruteForce"]
merge_algo_times = data["MergeAlgo"]

# Plot the data
plt.figure(figsize=(12, 6))
plt.plot(array_sizes, brute_force_times, label="Brute Force", color="red", linewidth=2)
plt.plot(array_sizes, merge_algo_times, label="Merge Sort Algorithm", color="blue", linewidth=2)

# Add labels and title
plt.xlabel("Array Size", fontsize=14)
plt.ylabel("Execution Time (seconds)", fontsize=14)
plt.title("Comparison of Execution Times for Inverse Pair Algorithms", fontsize=16)

# Add a legend
plt.legend(fontsize=12)

# Add grid lines
plt.grid(True, linestyle="--", alpha=0.7)

# Save the plot as an image file
plt.savefig("inverse_pairs_comparison.png", dpi=300)

# Show the plot
plt.show()
