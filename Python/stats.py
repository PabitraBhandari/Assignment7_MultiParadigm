from collections import Counter

class StatisticsCalculator:
    def __init__(self, data):
        self.data = sorted(data)

    def calculate_mean(self):
        return sum(self.data) / len(self.data)

    def calculate_median(self):
        n = len(self.data)
        if n % 2 == 0:
            return (self.data[n // 2 - 1] + self.data[n // 2]) / 2
        else:
            return self.data[n // 2]

    def calculate_mode(self):
        counts = Counter(self.data)
        max_count = max(counts.values())
        modes = [k for k, v in counts.items() if v == max_count]
        return modes if max_count > 1 else []

if __name__ == "__main__":
    data = list(map(int, input("Enter a list of integers separated by space: ").split()))
    stats = StatisticsCalculator(data)

    print(f"Mean: {stats.calculate_mean():.2f}")
    print(f"Median: {stats.calculate_median():.2f}")
    modes = stats.calculate_mode()
    if modes:
        print("Mode(s):", *modes)
    else:
        print("No mode found.")
