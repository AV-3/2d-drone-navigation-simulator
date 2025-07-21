import pandas as pd
import matplotlib.pyplot as plt
import os

def plot_simulation_data():
    script_dir = os.path.dirname(os.path.abspath(__file__))

    csv_path = os.path.join(script_dir, 'trajectory.csv')

    try:
        df = pd.read_csv(csv_path)
    except FileNotFoundError:
        print(f"Error: Could not find trajectory.csv at '{csv_path}'")
        print("Please make sure you have run the C++ simulation first.")
        return

    # Extract waypoints for plotting
    waypoints_data = df[['target_x', 'target_y']].drop_duplicates()
    waypoints_x = waypoints_data['target_x'].tolist()
    waypoints_y = waypoints_data['target_y'].tolist()

    # --- Plot 1: Trajectory Path ---
    plt.figure(figsize=(10, 10))
    
    # Plot drone path
    plt.plot(df['x'], df['y'], label='Drone Path', color='blue', linewidth=2)
    
    # Plot waypoints
    plt.plot(waypoints_x, waypoints_y, 'go', markersize=10, label='Waypoints', linestyle='None')
    plt.plot(df['x'].iloc[0], df['y'].iloc[0], 'bo', markersize=12, label='Start')


    plt.title('Drone 2D Trajectory')
    plt.xlabel('X Position (m)')
    plt.ylabel('Y Position (m)')
    plt.grid(True)
    plt.legend()
    plt.axis('equal')
    plt.show()

    # --- Plot 2: Position vs Time ---
    plt.figure(figsize=(12, 6))
    
    # X position
    plt.subplot(2, 1, 1)
    plt.plot(df['time'], df['x'], label='Actual X', color='blue')
    plt.plot(df['time'], df['target_x'], label='Target X', color='red', linestyle='--')
    plt.title('Position vs. Time')
    plt.ylabel('X Position (m)')
    plt.grid(True)
    plt.legend()

    # Y position
    plt.subplot(2, 1, 2)
    plt.plot(df['time'], df['y'], label='Actual Y', color='blue')
    plt.plot(df['time'], df['target_y'], label='Target Y', color='red', linestyle='--')
    plt.xlabel('Time (s)')
    plt.ylabel('Y Position (m)')
    plt.grid(True)
    plt.legend()

    plt.tight_layout()
    plt.show()

if __name__ == '__main__':
    plot_simulation_data()