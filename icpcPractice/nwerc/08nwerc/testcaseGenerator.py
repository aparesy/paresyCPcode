import random

def generate_test_case(c, d, v, seed=None):
    if seed is not None:
        random.seed(seed)

    animals = []
    for i in range(c):
        animals.append(f"C{i+1}")
    for i in range(d):
        animals.append(f"D{i+1}")

    votes = []
    for _ in range(v):
        love = random.choice(animals)
        hate = random.choice(animals)
        while hate == love:
            hate = random.choice(animals)
        votes.append((love, hate))

    return c, d, v, votes

# Generate a few diverse test cases
test_cases = []
for seed in range(3):
    test_cases.append(generate_test_case(c=2, d=2, v=6, seed=seed))

# Print test cases
for idx, (c, d, v, votes) in enumerate(test_cases):
    print(f"Test Case {idx + 1}:")
    print(c, d, v)
    for love, hate in votes:
        print(love, hate)
    print()