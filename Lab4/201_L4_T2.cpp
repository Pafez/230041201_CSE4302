#include <iostream>

using namespace std;

class TaxEstimator
{
private:
    double totalAnnualIncome;
    double totalDeductibleExpenses;
    float determineBracketRate() const;
public:
    TaxEstimator();
    ~TaxEstimator();

    int addIncomeSource(double incomeAmount);
    int addExpense(double expenseAmount);
    void printTaxSlip() const;
};

TaxEstimator::TaxEstimator()
{
    totalAnnualIncome = 0.0f;
    totalDeductibleExpenses = 0.0f;
}

TaxEstimator::~TaxEstimator()
{
    cout << "Tax session closed." << endl;
}

float TaxEstimator::determineBracketRate() const {
    double netIncome = totalAnnualIncome - totalDeductibleExpenses;
    if (netIncome < 10000) return 0.0f;
    if (netIncome >= 10000 and netIncome <= 50000) return 0.1f;
    if (netIncome > 50000) return 0.2f;
}

int TaxEstimator::addIncomeSource(double incomeAmount) {
    if (incomeAmount < 0) {
        cout << "Negative income is bad for the economy and my code." << endl;
        return 1;
    }
    totalAnnualIncome += incomeAmount;
    return 0;
}

int TaxEstimator::addExpense(double expenseAmount) {
    if (expenseAmount < 0) {
        cout << "Although good for the economy, negative expense is bad for my code." << endl;
        return 1;
    }
    totalDeductibleExpenses += expenseAmount;
    return 0;
}

void TaxEstimator::printTaxSlip() const {
    double netIncome = totalAnnualIncome - totalDeductibleExpenses;
    double taxAmountDue = netIncome * determineBracketRate();
    cout << "Tax Due: " << taxAmountDue << endl;
}
