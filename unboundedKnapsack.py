def knapsack(w, p, C, n):
    # Initialize a 2D array with (C+1) rows and (n+1) columns, filled with zeros
    profit = [[0 for _ in range(n + 1)] for _ in range(C + 1)]

    for r in range(1, C + 1):  
        for c in range(1, n + 1): 
            # Start with the maximum profit excluding this item
            profit[r][c] = profit[r][c - 1]
            if w[c - 1] <= r:
                # Allow multiple instances of the same item by adding it repeatedly
                profit[r][c] = max(profit[r][c], profit[r - w[c - 1]][c] + p[c - 1])

    print("Table:")
    for row in range(C + 1):
        print(profit[row])  # Show working

    # Print the items needed for the max profit
    selected_items = []
    cap = C
    itemNum = n

    # Backtrack to find selected items
    while cap > 0 and itemNum > 0:
        if profit[cap][itemNum] != profit[cap][itemNum - 1]:  # Item was included
            selected_items.append(itemNum - 1)  # Add the index of the selected item
            cap -= w[itemNum - 1]  # Reduce the capacity by the weight of the included item (allowing repeats)
        else:
            itemNum -= 1  # Move to the previous item

    print("Indices of items in the knapsack:", selected_items[::-1])  # Reverse to get original order
    return profit[C][n]

# Example usage:
weights = [4,6,8]
profits = [7,6,9]
capacity = 14
numObjects = len(weights)

print("Maximum profit:", knapsack(weights, profits, capacity, numObjects))
