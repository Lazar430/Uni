import random

# Define the file path
file_path = "large_input_file.txt"

# Define the number of random values you want to generate
num_values = 10000  # Adjust this number for desired size

# Open the file in write mode
with open(file_path, 'w') as file:
    # Generate and write random values to the file, one per line
    for _ in range(num_values):
        random_value = random.randint(0, 1000)
        file.write(str(random_value) + '\n')

print(f"File '{file_path}' with {num_values} random values generated successfully.")
