#include <iostream>
#include <string>
#include <iomanip>    // for fixed, setprecision
using namespace std;

// Function prototype
string calculatePoolState(double V, double P1, double P2, double H);

int main() {
    double V, P1, P2, H;
    
    cout << "Enter pool volume (liters): ";
    cin >> V;
    cout << "Enter flow rate of pipe 1 (liters/hour): ";
    cin >> P1;
    cout << "Enter flow rate of pipe 2 (liters/hour): ";
    cin >> P2;
    cout << "Enter number of hours: ";
    cin >> H;
    
    string result = calculatePoolState(V, P1, P2, H);
    cout << result << endl;
    
    return 0;
}

// Function definition
string calculatePoolState(double V, double P1, double P2, double H) {
    // Calculate total water filled
    double totalWater = (P1 + P2) * H;
    
    // Calculate water from each pipe
    double waterFromPipe1 = P1 * H;
    double waterFromPipe2 = P2 * H;
    
    // For percentage formatting (2 decimal places)
    cout << fixed << setprecision(2);
    
    // Case 1: Overflowing (Total water > Pool volume)
    if (totalWater > V) {
        double overflow = totalWater - V;
        
        double pipe1Percent = (waterFromPipe1 / totalWater) * 100;
        double pipe2Percent = (waterFromPipe2 / totalWater) * 100;
        
        // Convert to string with formatting
        string result = "Overflow: " + to_string(overflow) + " liters overflow. ";
        result += "Pipe1: " + to_string(pipe1Percent) + "%, ";
        result += "Pipe2: " + to_string(pipe2Percent) + "%";
        
        return result;
    }
    
    // Case 2: Exactly full (Total water == Pool volume)
    else if (totalWater == V) {
        double pipe1Percent = (waterFromPipe1 / totalWater) * 100;
        double pipe2Percent = (waterFromPipe2 / totalWater) * 100;
        
        string result = "Full: 100.00% filled. ";
        result += "Pipe1: " + to_string(pipe1Percent) + "%, ";
        result += "Pipe2: " + to_string(pipe2Percent) + "%";
        
        return result;
    }
    
    // Case 3: Not full (Total water < Pool volume)
    else {
        double poolPercent = (totalWater / V) * 100;
        
        double pipe1Percent = (waterFromPipe1 / totalWater) * 100;
        double pipe2Percent = (waterFromPipe2 / totalWater) * 100;
        
        string result = "Not Full: " + to_string(poolPercent) + "% filled. ";
        result += "Pipe1: " + to_string(pipe1Percent) + "%, ";
        result += "Pipe2: " + to_string(pipe2Percent) + "%";
        
        return result;
    }
}