#include <iostream>

using namespace std;

class GymProfile
{
private:
    string memberName;
    string membershipTier;
    double bodyWeight;
    double benchPressMax;
public:
    GymProfile();
    GymProfile(string name, string tier, double weight, double maxPress);
    ~GymProfile();

    string getMemberName() const;
    string getMembershipTier() const;
    double getBodyWeight() const;
    double getbenchPressMax() const;

    int setMemberName(string name);
    int setMembershipTier(string tier);
    int setBodyWeight(double weight);
    int setbenchPressMax(double maxPress);

    void printProfileDetails() const;
};

GymProfile::GymProfile() {
    memberName = "N/A";
    membershipTier = "N/A";
    bodyWeight = 0.0f;
    benchPressMax = 0.0f;
}
GymProfile::GymProfile(string name, string tier, double weight, double maxPress)
{
    memberName = name;
    membershipTier = tier;
    bodyWeight = weight;
    benchPressMax = maxPress;
}

GymProfile::~GymProfile()
{
}

string GymProfile::getMemberName() const {
    return memberName;
}
string GymProfile::getMembershipTier() const {
    return membershipTier;
}
double GymProfile::getBodyWeight() const {
    return bodyWeight;
}
double GymProfile::getbenchPressMax() const {
    return benchPressMax;
}

int GymProfile::setMemberName(string name) {
    memberName = name;
    return 0;
}
int GymProfile::setMembershipTier(string tier) {
    if (tier.length() <= 3) {
        membershipTier = "Standard";
        return 1;
    }
    membershipTier = tier;
    return 0; 
}
int GymProfile::setBodyWeight(double weight) {
    if (weight < 40.0f and weight > 200.0f) {
        bodyWeight = 70.0f;
        return 1;
    }
    bodyWeight = weight;
    return 0;
}
int GymProfile::setbenchPressMax(double maxPress) {
    if (maxPress < 0.0f) {
        maxPress = 0.0f;
        return 1;
    }
    benchPressMax = maxPress;
    return 0;
}

void GymProfile::printProfileDetails() const {
    cout << "Name: " << memberName << endl;
    cout << "Tier: " << membershipTier << endl;
    cout << "Weight: " << bodyWeight << endl;
    cout << "Max Benchpress: " << benchPressMax << endl;
}

void completeTrainingSession(GymProfile &profile) {
    profile.setbenchPressMax(profile.getbenchPressMax()*1.05f);
    double w = profile.getBodyWeight();
    w -= 1.5f;
    if (w < 40) w = 40;
    profile.setBodyWeight(w);
}

int main() {
    GymProfile what_is_cyberImplant[5];

    what_is_cyberImplant[0] = GymProfile("Yuusha", "Gold", 80, 45);
    what_is_cyberImplant[1] = GymProfile("Farhan", "Silver", 70, 35);
    what_is_cyberImplant[2] = GymProfile("Talha", "Basic", 65, 20);
    what_is_cyberImplant[3] = GymProfile("Shihab", "Silver", 58, 25);
    what_is_cyberImplant[4] = GymProfile("Pafez", "Silver", 64, 15);

    for (int i = 0; i < 5; i++) {
        cout << "Before: " << endl;
        what_is_cyberImplant[i].printProfileDetails();
        cout << endl;
        completeTrainingSession(what_is_cyberImplant[i]);
        cout << "After: " << endl;
        what_is_cyberImplant[i].printProfileDetails();
    }
}
 