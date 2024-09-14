#include <iostream>
#include <iomanip> // for formatting output

using namespace std;

int main() {
    // Constants
    const double FIXED_PAYMENT_ON_DELIVERY = 5000.00;
    const double FIXED_PAYMENT_ON_PUBLICATION = 20000.00;
    const double ROYALTY_RATE_OPTION_2 = 0.125; // 12.5%
    const double ROYALTY_RATE_OPTION_3_BELOW_4000 = 0.10; // 10% for first 4000 copies
    const double ROYALTY_RATE_OPTION_3_ABOVE_4000 = 0.14; // 14% for copies over 4000
    const int THRESHOLD_4000_COPIES = 4000;

    // Initialize Variables for users input
    double netPricePerCopy;
    int estimatedCopiesSold;

    // Prompting the user
    cout << "Enter the net price of each copy of the novel: $";
    cin >> netPricePerCopy;
    cout << "Enter the estimated number of copies that will be sold: ";
    cin >> estimatedCopiesSold;

    // Option 1: Fixed payments on delivery and publication
    double option1Royalties = FIXED_PAYMENT_ON_DELIVERY + FIXED_PAYMENT_ON_PUBLICATION;

    // Option 2: 12.5% of net price for each copy sold
    double option2Royalties = ROYALTY_RATE_OPTION_2 * netPricePerCopy * estimatedCopiesSold;

    // Option 3: 10% for the first 4000 copies, 14% for copies above 4000
    double option3Royalties = 0.0;
    if (estimatedCopiesSold <= THRESHOLD_4000_COPIES) {
        option3Royalties = ROYALTY_RATE_OPTION_3_BELOW_4000 * netPricePerCopy * estimatedCopiesSold;
    } else {
        int copiesAbove4000 = estimatedCopiesSold - THRESHOLD_4000_COPIES;
        option3Royalties = (ROYALTY_RATE_OPTION_3_BELOW_4000 * netPricePerCopy * THRESHOLD_4000_COPIES) +
                           (ROYALTY_RATE_OPTION_3_ABOVE_4000 * netPricePerCopy * copiesAbove4000);
    }

    // Display the royalties for each option
    cout << fixed << setprecision(2);
    cout << "\nRoyalties for each option:" << endl;
    cout << "Option 1 (Fixed Payment): $" << option1Royalties << endl;
    cout << "Option 2 (12.5% Royalty per copy sold): $" << option2Royalties << endl;
    cout << "Option 3 (10% for first 4000, 14% after): $" << option3Royalties << endl;

    // Determine the best option
    double bestOptionRoyalties = max(option1Royalties, max(option2Royalties, option3Royalties));
    cout << "\nThe best option is: ";
    if (bestOptionRoyalties == option1Royalties) {
        cout << "Option 1 (Fixed Payment)" << endl;
    } else if (bestOptionRoyalties == option2Royalties) {
        cout << "Option 2 (12.5% Royalty per copy sold)" << endl;
    } else {
        cout << "Option 3 (10% for first 4000, 14% after)" << endl;
    }

    return 0;
}