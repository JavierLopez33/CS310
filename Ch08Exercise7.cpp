#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

int main() {
    const int numCandidates = 5;
    string candidates[numCandidates];
    int votes[numCandidates];
    int totalVotes = 0;
    
    // Input candidate names and votes
    for (int i = 0; i < numCandidates; i++) {
        cout << "Enter candidate #" << i + 1 << " name:";
        cin >> candidates[i];
        cout << "Enter the number of votes for " << candidates[i] << ": ";
        cin >> votes[i];
        totalVotes += votes[i];
    }
    
    // Display results
    cout << "\nElection Results:\n";
    cout << left << setw(15) << "Candidate" << right << setw(10) << "Votes Received" << setw(20) << "% of Total Votes\n";
    cout << "--------------------------------------------\n";
    
    int maxVotes = 0;
    string winner;
    
    for (int i = 0; i < numCandidates; i++) {
        double percentage = (static_cast<double>(votes[i]) / totalVotes) * 100;
        cout << left << setw(15) << candidates[i] << right << setw(10) << votes[i] << setw(19) << fixed << setprecision(2) << percentage << "%\n";
        
        // Determine the winner
        if (votes[i] > maxVotes) {
            maxVotes = votes[i];
            winner = candidates[i];
        }
    }
    
    // Output the winner
    cout << "\nThe winner of the election is: " << winner;
    
    return 0;
}